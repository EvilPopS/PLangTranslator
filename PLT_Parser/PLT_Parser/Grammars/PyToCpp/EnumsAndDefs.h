#pragma once
#ifndef ENUMS_AND_DEFS_H
#define ENUMS_AND_DEFS_H

#ifdef __cplusplus
extern "C"
{
#endif


#define NO_INDEX              -1
#define CHAR_BUFFER_LENGTH   128


extern char char_buffer[CHAR_BUFFER_LENGTH];
extern int out_lin;

extern void warning(char* s);
extern int yyerror(const char* s);

typedef enum DataType { NO_DATA_TYPE, UNKNOWN, NONE, NUM_BOOL, STRING, LIST, CLASS } DataType;

typedef enum ArithmeticOperator { ADD, SUB, MUL, DIV } ArithmeticOperator;
typedef enum RelationOperator { LS, GR, LSEQ, GREQ, EQ, NEQ } RelationOperator;
typedef enum LogicalOperator { AND, OR } LogicalOperator;

static const char* ar_instructions[] = { "ADDS", "SUBS", "MULS", "DIVS" };
static const char* jumps[] = { "JLTS", "JGTS", "JLES", "JGES", "JEQ ", "JNE ", "JEQ " };
static const char* opp_jumps[] = { "JGES", "JLES", "JGTS", "JLTS", "JNE ", "JEQ ", "JNE " };


#ifdef __cplusplus
}
#endif

#endif	// ENUMS_AND_DEFS_H
