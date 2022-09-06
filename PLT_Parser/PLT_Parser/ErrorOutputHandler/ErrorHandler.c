#include "ErrorHandler.h"
#include <stdio.h>


int raiseError(ErrorType errType, int line, char* errMessage, ...) {
	va_list strArgs;
	va_start(strArgs, errMessage);
	char formattedMess[400];
	jsonErrMessFormatter(formattedMess, errType, line, errMessage, strArgs);
	writeErrMessToFile(formattedMess);
	va_end(strArgs);
	return errType;
}

void jsonErrMessFormatter(char* jsonFormat, ErrorType errType, int line, char* errMessage, va_list messArgs) {
	char formattedErrMess[300];
	vsprintf_s(formattedErrMess, 300, errMessage, messArgs);
	
	char* errTypeName;
	switch (errType) {
		case LEXICAL_ERR:
			errTypeName = "Lexical";
			break;
		case SYNTAX_ERR:
			errTypeName = "Syntax";
			break;
		case SEMANTIC_ERR:
			errTypeName = "Semantic";
			break;
		default:
			errTypeName = "Other";
	}

	sprintf_s(
		jsonFormat,
		400,
		"{\n\tErrorType: \"%s\"\n\tLine: \"%d\"\n\tErrorMessage : \"%s\"\n}", 
		errTypeName, line, formattedErrMess
	);
}


void writeErrMessToFile(char* errMessage) {
	FILE* file;
	fopen_s(&file, ERR_OUTPUT_FILE_PATH, "w"); 
	fprintf(file, errMessage);
	fclose(file);
}

