#pragma once
#ifndef SYMBOL_TABS_H
#define SYMBOL_TABS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "EnumsAndDefs.h"


#define MAX_PARAMS_NUM 128
#define MAX_METHOD_PROPS_NUM 256


typedef enum TableType { NO_TAB_TYPE, TB_VARS, TB_PARAMS, TB_FUNCS, TB_LITS, TB_CLASSES, TB_PROPS, TB_LISTS, TB_REGS } TableType;


typedef struct MainTable {
	int index;
	TableType tableType;
} MainTable;

typedef struct RegistersTable {
	int index;
	TableType tableType;
} RegistersTable;

typedef struct FunctionsTable {
	char* name;
	bool isMethod;
	DataType type;
	int nonDefParamNum;
	int nonDefParamInds[MAX_PARAMS_NUM];
	int defParamNum;
	int defParamInds[MAX_PARAMS_NUM];
} FunctionsTable;


typedef struct ClassesTable {
	char* name;
	char* selfName;
	int numOfMethods;
	int methodsInds[MAX_METHOD_PROPS_NUM];
	int numOfProps;
	int propertiesInds[MAX_METHOD_PROPS_NUM];
} ClassesTable;


typedef struct PropertiesTable {
	char* name;
	DataType type;
	char* classTypeName;
} PropertiesTable;


typedef struct VariablesTable {
	char* name;
	DataType type;
	char* classTypeName;
} VariablesTable;


typedef struct ParametersTable {
	char* name;
	DataType type;
	bool hasDefVal;
	char* classTypeName;
} ParametersTable;


typedef struct LiteralsTable {
	char* value;
	DataType type;
} LiteralsTable;


typedef struct ListsTable {
	int elementInd;
	TableType tableType;
	bool isListPointer;
	bool hasNext;
	int nextElemInd;	
} ListsTable;


// _FIND_ functions
int findSymbolByName(char*);
bool checkIfNameInTable(char*, TableType, int);

// _INSERT_ functions
void insertSymbolToMainTable(int, TableType);
int insertFunctionToTable(char*, bool, DataType);
int insertVariableToTable(char*, DataType);
int insertParameterToTable(char*, DataType, bool);
int insertLiteralToTable(char*, DataType);

// _CLEAR_ functions
void clearMainTableFromInd(int);
void clearFromSpecificTable(TableType, int);
void clearElemFromFuncTable(int);
void clearElemFromClassTable(int);
void clearElemFromVarTable(int);

// _GET_ functions
DataType getSymbDataType(int);
int getNumOfNonDefParams(int);
int getNumOfDefParams(int);


// _SET_ functions
void setSymbDataType(int, DataType);
void setNextFuncParam(int, int, bool);
void setFuncType(int, DataType);

// _CHECK_ functions
bool checkIfIsGivenTableType(int, TableType);



#ifdef __cplusplus
}
#endif

#endif	// SYMBOL_TABS_H