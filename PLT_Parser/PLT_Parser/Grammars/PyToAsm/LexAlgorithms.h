#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#define IS_INDENT 1
#define IS_DEDENT -1

static int prevIndentLvl = 0;
static int curIndentLvl = 0;

static int retDedent = 0;
static int retIndent = 0;

void resetIndentation();
void incOrdDecIndentation();
int preRegExprIndentTokenzier();

#ifdef __cplusplus
}
#endif