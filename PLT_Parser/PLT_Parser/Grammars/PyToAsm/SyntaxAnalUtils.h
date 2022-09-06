#pragma once
#ifndef SYNTAX_ANAL_UTILS_H
#define SYNTAX_ANAL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h> 

	
#define INPUT_FILE_PATH "Tests/PyToAsm/test1.txt"


void appendNewLineToFileIfNotExists(FILE*);


#ifdef __cplusplus
}
#endif

#endif