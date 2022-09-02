#include "ErrorHandler.h"
#include <stdio.h>



int raiseError(char* message, ...) {
	va_list strArgs;
	va_start(strArgs, message);
	writeErrMessToFile(message, strArgs);
	va_end(strArgs);
	return -1;
}

void writeErrMessToFile(char* errMessage, va_list messArgs) {
	FILE* file;
	fopen_s(&file, ERR_OUTPUT_FILE_PATH, "w");
	vfprintf(file, errMessage, messArgs);
	fclose(file);
}

