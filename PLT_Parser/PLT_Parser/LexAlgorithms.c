#include "LexAlgorithms.h"


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