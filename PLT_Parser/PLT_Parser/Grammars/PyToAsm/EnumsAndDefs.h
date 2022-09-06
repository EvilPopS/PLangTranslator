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

#ifdef __cplusplus
}
#endif

#endif
