#pragma once
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdarg.h>


#define ERR_OUTPUT_FILE_PATH "ErrorOutputHandler/ErrorOutputFile.txt"


typedef enum ErrorType { 
	LEXICAL_ERR = -101,
	SYNTAX_ERR = -201,
	SEMANTIC_ERR = -301
} ErrorType;


int raiseError(ErrorType, int, char*, ...);
void jsonErrMessFormatter(char*, ErrorType, int, char*, va_list);
void writeErrMessToFile(char*);


#ifdef __cplusplus
}
#endif

#endif	// ERROR_HANDLER_H