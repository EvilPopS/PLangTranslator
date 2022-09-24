#include "LexAlgorithms.h"

prevIndentLvl = 0;
curIndentLvl = 0;

retDedent = 0;
retIndent = 0;

void resetIndentation() {
	if (prevIndentLvl > 0) {
		retDedent = prevIndentLvl;
		prevIndentLvl = 0;
	}
}

void incOrdDecIndentation() {
	if (prevIndentLvl < curIndentLvl) {
		retIndent = curIndentLvl - prevIndentLvl;
		prevIndentLvl = curIndentLvl;
	}
	else if (prevIndentLvl > curIndentLvl) {
		retDedent = prevIndentLvl - curIndentLvl;
		prevIndentLvl = curIndentLvl;
	}
	curIndentLvl = 0;

}

int preRegExprIndentTokenzier() {
	if (retIndent > 0) {
		retIndent--;
		return IS_INDENT;
	}
	else if (retDedent > 0) {
		retDedent--;
		return IS_DEDENT;
	}

	return 0;
}

void setCurrIndentByNumOfTabs(char* yytext) {
	int ind = (int)(strlen(yytext)) - 1;
	while (yytext[ind] == '\t') {
		ind--;
		curIndentLvl++;
	}
}

int countNewLines(char* yytext) {
	int newLineCounter = 0;
	for (int ind = (int)(strlen(yytext))-1; ind >= 0; ind--)
		if (yytext[ind] == '\n')
			newLineCounter++;
	return newLineCounter;
}