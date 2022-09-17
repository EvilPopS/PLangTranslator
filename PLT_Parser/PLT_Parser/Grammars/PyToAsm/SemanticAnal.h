#pragma once
#ifndef SEMANTIC_ANAL_UTILS_H
#define SEMANTIC_ANAL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "SymbolTabs.h"


#define NUM_OF_DATA_TYPES 5


typedef enum TypeCompatArrayInds {
	NON_TYPE_IND = 0,
	NUM_BOOL_TYPE_IND = 1,
	STRING_TYPE_IND = 2,
	LIST_TYPE_IND = 3,
	CLASS_TYPE_IND = 4
} TypeCompatArrayInds;

typedef enum TypeCompatArrayKind {
	ADDITION_ARR,
	SUBSTRICTION_ARR,
	MULTIPLICATION_ARR,
	DIVISION_ARR,
	RELATION_ARR
} TypeCompatArrayKind;


int loopsCounter;


bool checkIfTypesCompatible(DataType, DataType, TypeCompatArrayKind);
bool getCompatibilityFromArray(TypeCompatArrayKind, TypeCompatArrayInds, DataType);

bool aritOpExpTypesValidation(char*, DataType*, DataType, DataType, ArithmeticOperator);
void setAritOpKindAndStr(TypeCompatArrayKind*, char**, ArithmeticOperator);
DataType makeNewTypeByAritOp(ArithmeticOperator, DataType, DataType);
bool relopExpTypesValidation(char*, DataType, DataType, RelationOperator);

bool checkIfIsInLoop();
void incLoopCounter();
void decLoopCounter();



#ifdef __cplusplus
}
#endif

#endif	// SEMANTIC_ANAL_UTILS_H