#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef DEFS_H
#define DEFS_H

#define NO_INDEX              -1
#define NO_ATR                 0
#define LAST_WORKING_REG      12
#define FUN_REG               13
#define CHAR_BUFFER_LENGTH   128

extern char char_buffer[CHAR_BUFFER_LENGTH];
extern int out_lin;

//pomocni makroi za ispis
extern void warning(char* s);
extern int yyerror(const char* s);

//konstante arithmetickih operatora
enum arops { ADD, SUB, MUL, DIV };
static const char* ar_instructions[] = { "ADDS", "SUBS", "MULS", "DIVS" };

// konstante logickih operatora
enum lops { AND, OR };

//konstante relacionih operatora
enum relops { LS, GR, LSEQ, GREQ, EQ, NEQ, IS };

// Jumpovi
static const char* jumps[] = { "JLTS", "JGTS", "JLES", "JGES", "JEQ ", "JNE ", "JEQ " };

static const char* opp_jumps[] = { "JGES", "JLES", "JGTS", "JLTS", "JNE ", "JEQ ", "JNE " };
#endif

#ifdef __cplusplus
}
#endif