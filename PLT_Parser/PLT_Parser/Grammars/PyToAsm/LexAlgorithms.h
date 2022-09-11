#pragma once
#ifndef LEX_ALGORITHMS_H
#define LEX_ALGORITHMS_H

#ifdef __cplusplus
extern "C" {
#endif


#define IS_INDENT 1
#define IS_DEDENT -1

extern int prevIndentLvl;
extern int curIndentLvl;

extern int retDedent;
extern int retIndent;

void resetIndentation();
void incOrdDecIndentation();
int preRegExprIndentTokenzier();
void setCurrIndentByNumOfTabs(char*);
int countNewLines(char*);


#ifdef __cplusplus
}
#endif

#endif	// LEX_ALGORITHMS_H