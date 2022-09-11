#pragma once
#ifndef SYNTAX_ANAL_UTILS_HEADER_H
#define SYNTAX_ANAL_UTILS_HEADER_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h> 


#define INPUT_FILE_PATH "Tests/PyToAsm/test1.txt"


int parser_main(int, char**);

void appendNewLineToFileIfNotExists(FILE*);


#ifdef __cplusplus
}
#endif

#endif // SYNTAX_ANAL_UTILS_HEADER_H