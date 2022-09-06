#include "SyntaxAnalUtils.h"


void appendNewLineToFileIfNotExists(FILE* file) {
	fopen_s(&file, INPUT_FILE_PATH, "a+");
	
	int nextCharVal;
	char prevChar;
	while ((nextCharVal = fgetc(file)) != EOF)
		prevChar = (char)nextCharVal;

	if (prevChar != '\n')
		fprintf(file, "\n");
	
	fclose(file);
}

