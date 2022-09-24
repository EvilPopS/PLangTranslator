#include "SemanticAnal.h"
#include "../../ErrorOutputHandler/ErrorHandler.h"


#define MA_VARS_ARRAY_SIZE 64
#define NESTED_FUNCS_ARR_SIZE 16

DataType additionCompatArray[][NUM_OF_DATA_TYPES] = {
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS }
};
DataType substractionCompatArray[][NUM_OF_DATA_TYPES] = {
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS }
};
DataType multiplicationCompatArray[][NUM_OF_DATA_TYPES] = {
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, CLASS },
	{ NONE, STRING, LIST, CLASS },
	{ NONE, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS }
};
DataType divisionCompatArray[][NUM_OF_DATA_TYPES] = {
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS }
};
DataType relationsCompatArray[][NUM_OF_DATA_TYPES] = {
	{ NONE, NUM_BOOL, STRING, LIST, CLASS },
	{ NONE, STRING, LIST, CLASS },
	{ NONE, NUM_BOOL, LIST, CLASS },
	{ NONE, NUM_BOOL, STRING, CLASS },
	{ NONE, NUM_BOOL, STRING, LIST, CLASS }
};


char* dataTypeStrNames[15] = { "No Type", "Unknown", "None", "Number/Boolean", "String", "List", "Class" };

// counts current level of nested 'while' or 'for' loop
int loopsCounter = 0;

// multi-assignment needed variables
int maVarsCounter = 0;
int maValsCounter = 0;
int maVarInds[MA_VARS_ARRAY_SIZE] = { -1 };

// functions call/definitions variables
int currNestFuncArrInd = -1;
int nestedFunctionsInds[NESTED_FUNCS_ARR_SIZE] = { -1 };
bool canDefineNonDefParams = true;


// TYPE COMPAT checker functions ------------------------------------------
bool checkIfTypesCompatible(DataType type1, DataType type2, TypeCompatArrayKind arrKind) {
	if (type1 == UNKNOWN || type2 == UNKNOWN)
		return true; 
	
	switch (type1) {
		case NONE:
			return getCompatibilityFromArray(arrKind, NON_TYPE_IND, type2);
		case NUM_BOOL:
			return getCompatibilityFromArray(arrKind, NUM_BOOL_TYPE_IND, type2);
		case STRING:
			return getCompatibilityFromArray(arrKind, STRING_TYPE_IND, type2);
		case LIST:
			return getCompatibilityFromArray(arrKind, LIST_TYPE_IND, type2);
		case CLASS:
			return getCompatibilityFromArray(arrKind, CLASS_TYPE_IND, type2);
		default:
			return false;
	}
}

bool getCompatibilityFromArray(TypeCompatArrayKind arrKind, TypeCompatArrayInds arrInd, DataType type) {
	DataType* compatArray = NULL;
	switch (arrKind) {
		case ADDITION_ARR:
			compatArray = additionCompatArray[arrInd];
			break;
		case SUBSTRICTION_ARR:
			compatArray = substractionCompatArray[arrInd];
			break;
		case MULTIPLICATION_ARR:
			compatArray = multiplicationCompatArray[arrInd];
			break;
		case DIVISION_ARR:
			compatArray = divisionCompatArray[arrInd];
			break;
		case RELATION_ARR:
			compatArray = relationsCompatArray[arrInd];
			break;
	}

	if (compatArray == NULL)
		return false;

	for (int ind = 0; ind < NUM_OF_DATA_TYPES; ind++)
		if (compatArray[ind] == type)
			return false;
	
	return true;
}

bool aritOpExpTypesValidation(char* errMessage, DataType* newType, DataType type1, DataType type2, ArithmeticOperator aritOp) {
	TypeCompatArrayKind kind;
	char* operatorAsStr = NULL;
	setAritOpKindAndStr(&kind, &operatorAsStr, aritOp);

	if (checkIfTypesCompatible(type1, type2, kind))
		return true;
	
	*newType = makeNewTypeByAritOp(type1, type2, aritOp); 

	sprintf_s(
		errMessage, 200, 
		"Cannot use the operator '%s' for values of types '%s' and '%s'",
		operatorAsStr,
		dataTypeStrNames[type1],
		dataTypeStrNames[type2]
	);
	return false;
}

void setAritOpKindAndStr(TypeCompatArrayKind* kind, char** operatorAsStr, ArithmeticOperator aritOp) {
	switch (aritOp) {
		case ADD:
			*kind = ADDITION_ARR;
			*operatorAsStr = "+";
			break;
		case SUB:
			*kind = SUBSTRICTION_ARR;
			*operatorAsStr = "-";
			break;
		case MUL:
			*kind = MULTIPLICATION_ARR;
			*operatorAsStr = "*";
			break;
		default:
			*kind = DIVISION_ARR;
			*operatorAsStr = "/";
			break;
	}
}

DataType makeNewTypeByAritOp(DataType type1, DataType type2, ArithmeticOperator aritOp) {
	switch (aritOp) {
		case ADD: case SUB: case DIV:
			return type1;
		case MUL:
			if (type1 == NUM_BOOL && (type2 == LIST || type2 == STRING))
				return type2;
			else if ((type1 == LIST && type2 == STRING) && type2 == NUM_BOOL)
				return type1;
	}
	return UNKNOWN;
}

bool relopExpTypesValidation(char* errMessage, DataType type1, DataType type2, RelationOperator relOp) {
	if (relOp == EQ || relOp == NEQ)
		return true;

	if (checkIfTypesCompatible(type1, type2, RELATION_ARR))
		return true;

	sprintf_s(
		errMessage, 200,
		"Cannot use the operators '< or > or <= or >=' for values of types '%s' and '%s'",
		dataTypeStrNames[type1],
		dataTypeStrNames[type2]
	);
	return false;
}
// ------------------------------------------------------------------------


// LOOPS functions --------------------------------------------------------
bool checkIfIsInLoop() { return loopsCounter > 0; }

void incLoopCounter() {	loopsCounter++; }

void decLoopCounter() { loopsCounter--; }
// ------------------------------------------------------------------------

// MULTI ASSIGNMENT functions ---------------------------------------------
bool multiAssIsEqualNumOfVarsAndVals() { return maVarsCounter == maValsCounter; }

void incMultiAssNumOfVars() { maVarsCounter++; }

void incMultiAssNumOfVals() { maValsCounter++; }

void resetMultiAssCounters() { maVarsCounter = 0; maValsCounter = 0; }

void addVarToMultiAssArray(char* varName) {
	int varInd = findSymbolByName(varName);
	
	if (varInd == NO_INDEX || checkIfIsGivenTableType(varInd, TB_FUNCS))
		maVarInds[maVarsCounter++] = insertVariableToTable(varName, false, NO_DATA_TYPE);
	else
		maVarInds[maVarsCounter++] = varInd;
}

void setVarDataTypeInMultiAss(int valInd) {
	setSymbDataType(maVarInds[maValsCounter++], getSymbDataType(valInd));
}
// ------------------------------------------------------------------------

// 'DEF/CALL FUNCTIONS' functions -----------------------------------------
void incCurrNestFuncArrInd() { currNestFuncArrInd++; }
void decCurrNestFuncArrInd() { currNestFuncArrInd--; }

int getCurrFuncIndex() { return nestedFunctionsInds[currNestFuncArrInd]; }
void setCurrFuncIndex(int currInd) { nestedFunctionsInds[currNestFuncArrInd] = currInd; }

bool canDefNonDefParams() { return canDefineNonDefParams; }
void setCanDefNonDefParams(bool canDefine) { canDefineNonDefParams = canDefine; }
// ------------------------------------------------------------------------
