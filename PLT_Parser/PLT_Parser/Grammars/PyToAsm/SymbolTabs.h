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
#define MAX_TABLE_SIZE 512

extern int lastMainTabElem;
extern int lastFuncTabElem;
extern int lastClassTabElem;
extern int lastVarTabElem;
extern int lastLitTabElem;

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
	bool isList;
	DataType type;
	int ordNum;
} PropertiesTable;


typedef struct VariablesTable {
	char* name;
	bool isList;
	DataType type;
	int ordNum;
} VariablesTable;


typedef struct ParametersTable {
	char* name;
	bool isList;
	DataType type;
	bool hasDefVal;
	int ordNum;
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
int insertFunctionToTable(char*, bool);
int insertVariableToTable(char*, bool, DataType, int);
int insertLiteralToTable(char*, DataType);

// _CLEAR_ functions
void clearMainTableFromInd(int);
void clearFromSpecificTable(TableType, int);
void clearElemFromFuncTable(int);
void clearElemFromClassTable(int);
void clearElemFromVarTable(int);

// _GET_ functions
DataType getSymbDataType(int);

// _SET_ functions
void setSymbDataType(int, DataType); 
#ifdef __cplusplus
}
#endif

#endif	// SYMBOL_TABS_H