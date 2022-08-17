#pragma once
#ifdef __cplusplus
extern "C"
{
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

#ifdef __cplusplus
}
#endif