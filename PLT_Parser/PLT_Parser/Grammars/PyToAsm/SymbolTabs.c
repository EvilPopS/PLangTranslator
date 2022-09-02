#include "SymbolTabs.h"
#include "EnumsAndDefs.h"


MainTable mainTable[MAX_TABLE_SIZE];
FunctionsTable functionTable[MAX_TABLE_SIZE];
ClassesTable classesTable[MAX_TABLE_SIZE];
PropertiesTable propertiesTable[MAX_TABLE_SIZE];
VariablesTable variableTable[MAX_TABLE_SIZE];
ParametersTable parametersTable[MAX_TABLE_SIZE];
LiteralsTable literalTable[MAX_TABLE_SIZE];
ListsTable listsTable[MAX_TABLE_SIZE];


lastMainTabElem = -1;
lastFuncTabElem = -1;
lastClassTabElem = -1;
lastVarTabElem = -1;
lastLitTabElem = -1;


// _FIND_ functions -------------------------------------------------------------------
int findSymbolByName(char* name) {
	for (int i = 0; i < MAX_TABLE_SIZE; i++) {
		MainTable mt = mainTable[i];
		if (checkIfNameInTable(name, mt.tableType, mt.index))
			return mt.index;
	}
	return NO_INDEX;
}

bool checkIfNameInTable(char* name, TableType tableType, int ind) {
	switch (tableType) {
		case FUNCS:
			return strcmp(functionTable[ind].name, name) == 0;
		case VARS:
			return strcmp(variableTable[ind].name, name) == 0;
		case PARAMS:
			return strcmp(parametersTable[ind].name, name) == 0;
		case CLASSES:
			return strcmp(classesTable[ind].name, name) == 0;
		case PROPS:
			return strcmp(propertiesTable[ind].name, name) == 0;
		default:
			return false;
	}
}
// ------------------------------------------------------------------------------------

// _INSERT_ functions -----------------------------------------------------------------
void insertSymbolToMainTable(int index, TableType tableType) {
	lastMainTabElem++;
	mainTable[lastMainTabElem].index = index;
	mainTable[lastMainTabElem].tableType = tableType;
}

int insertFunctionToTable(char* name, bool isMethod) {
	insertSymbolToMainTable(++lastFuncTabElem, FUNCS);
	functionTable[lastFuncTabElem].name = name;
	functionTable[lastFuncTabElem].isMethod = isMethod;
	return lastMainTabElem;
}

int insertVariableToTable(char* name, bool isList, DataType type, int ordNum) {
	insertSymbolToMainTable(++lastVarTabElem, VARS);
	variableTable[lastVarTabElem].name = name;
	variableTable[lastVarTabElem].isList = isList;
	variableTable[lastVarTabElem].type = type;
	variableTable[lastVarTabElem].ordNum = ordNum;
	return lastMainTabElem;
}

int insertLiteralToTable(char* value, DataType type) {
	insertSymbolToMainTable(++lastLitTabElem, LITS);
	literalTable[lastLitTabElem].value = value;
	literalTable[lastLitTabElem].type = type;
	return lastMainTabElem;
}
// ------------------------------------------------------------------------------------

// _CLEAR_ functions ------------------------------------------------------------------
void clearMainTableFromInd(int ind) {
	while (ind < lastMainTabElem) {
		MainTable mt = mainTable[lastMainTabElem--];
		clearFromSpecificTable(mt.tableType, mt.index);
	}
}

void clearFromSpecificTable(TableType tableType, int ind) {
	switch (tableType) {
		case FUNCS:
			clearElemFromFuncTable(ind);
			break;
		case CLASSES:
			clearElemFromClassTable(ind);
			break;
		case VARS:
			clearElemFromVarTable(ind);
			break;
		case PARAMS:
			break;
		case PROPS:
			break;
	}
}

void clearElemFromFuncTable(int ind) {
	functionTable[ind].name = "";
	functionTable[ind].isMethod = false;

	for (int i = 0; i < functionTable[ind].nonDefParamNum; i++)
		functionTable[ind].nonDefParamInds[i] = -1;
	functionTable[ind].nonDefParamNum = 0;
	
	for (int i = 0; i < functionTable[ind].defParamNum; i++)
		functionTable[ind].defParamInds[i] = -1;
	functionTable[ind].defParamNum = 0;

	lastFuncTabElem--;
}

void clearElemFromClassTable(int ind) {
	classesTable[ind].name = "";
	classesTable[ind].selfName = "";
	
	for (int i = 0; i < classesTable[ind].numOfMethods; i++)
		classesTable[ind].methodsInds[i] = -1;
	classesTable[ind].numOfMethods = 0;

	for (int i = 0; i < classesTable[ind].numOfProps; i++)
		classesTable[ind].propertiesInds[i] = -1;
	classesTable[ind].numOfProps = 0;

	lastClassTabElem--;
}

void clearElemFromVarTable(int ind) {
	variableTable[ind].name = "";
	variableTable[ind].isList = false;
	variableTable[ind].type = NO_DATA_TYPE;
	variableTable[ind].ordNum = -1;

	lastVarTabElem--;
}
// ------------------------------------------------------------------------------------

// _GET_ functions --------------------------------------------------------------------
DataType getSymbDataType(int ind) {
	MainTable mt = mainTable[ind];
	switch (mt.tableType) {
	case VARS:
		return variableTable[mt.index].type;
	case PARAMS:
		return NO_DATA_TYPE;
	case PROPS:
		return NO_DATA_TYPE;
	}
	return NO_DATA_TYPE;
}
// ------------------------------------------------------------------------------------

