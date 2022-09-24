%option noyywrap

%{
	#include <stdbool.h>
	#include <stdio.h>
	#include <string.h>

	#include "SyntaxAnal.tab.h"
	#include "LexAlgorithms.h"
	#include "EnumsAndDefs.h"
	#include "SymbolTabs.h"
	#include "../../ErrorOutputHandler/ErrorHandler.h"

%}

%%

	{		
		// Pre reg-expressions indentation tokenizer
		switch(preRegExprIndentTokenzier()) {
			case IS_INDENT:
				return _INDENT;
			case IS_DEDENT:
				return _DEDENT;
		}
	}


" "+	{ /* skip */ }
\#.*	{ /* skip */ }

[\n][ \n\t]*[\n]	{ 
						yylineno += countNewLines(yytext);
						resetIndentation();	  
						return _NEW_LINE;
					}

[\n][ \n\t]*[\n][\t]+	{
							yylineno += countNewLines(yytext);
							setCurrIndentByNumOfTabs(yytext);
							incOrdDecIndentation();
							return _NEW_LINE;
						}					
 

[\n]	{ 
			yylineno++;
			resetIndentation();	  	  	  
			return _NEW_LINE;
		}

[\n][\t]+	{   
				yylineno++;
				curIndentLvl = (int)(strlen(yytext))-1;
				incOrdDecIndentation();
				return _NEW_LINE;
			}

"__init__"	{ return _INIT; }
"and"       { yylval.i = AND; return _LOP;}
"break"     { return _BREAK; }
"class"		{ return _CLASS; }
"continue"  { return _CONTINUE; }
"def"       { return _DEF; } 
"elif"      { return _ELIF; }
"else"      { return _ELSE; }
"False"     { yylval.s = "0"; return _NUM_BOOL; }
"for"		{ return _FOR; }
"if"        { return _IF; }
"in"        { return _IN; }
"None"      { yylval.i = NONE; return _NONE; }
"not"       { return _NOT; }
"or"        { yylval.i = OR; return _LOP; }
"pass"      { return _PASS; }
"return"    { return _RETURN;}
"True"      { yylval.s = "1"; return _NUM_BOOL; }
"while"   	{ return _WHILE; }
	
","		{ return _COMMA; }
"."		{ return _DOT; }
":"		{ return _COLON; }

"["     { return _LBRACKET; }
"]"     { return _RBRACKET; }
"("     { return _LPAREN; }
")"     { return _RPAREN; }
"="		{ return _ASSIGN; }

"+"     { yylval.i = ADD; return _ADD_SUB_OP; }
"-"     { yylval.i = SUB; return _ADD_SUB_OP; }
"*"		{ yylval.i = MUL; return _MUL_DIV_OP; }
"/"		{ yylval.i = DIV; return _MUL_DIV_OP; }

"<"     { yylval.i = LS;   return _RELOP; }
">"     { yylval.i = GR;   return _RELOP; }
"<="    { yylval.i = LSEQ; return _RELOP; }
">="    { yylval.i = GREQ; return _RELOP; }
"=="    { yylval.i = EQ;   return _RELOP; }
"!="    { yylval.i = NEQ;  return _RELOP; }

[a-zA-Z_][a-zA-Z0-9_]* 			{ yylval.s = _strdup(yytext); return _ID; }
[0-9]{1,10}     				{ yylval.s = _strdup(yytext); return _NUM_BOOL; }
[0-9]{0,9}"."[0-9]{1,9}     	{ yylval.s = _strdup(yytext); return _NUM_BOOL; }
[0-9]{1,9}"."[0-9]{0,9}     	{ yylval.s = _strdup(yytext); return _NUM_BOOL; }
\"[^"\n]*\"     				{ yylval.s = _strdup(yytext); return _STRING; }
\'[^'\n]*\'     				{ yylval.s = _strdup(yytext); return _STRING; }

.			{ 
				raiseError(LEXICAL_ERR, yylineno, "Unexpected character '%c'", *yytext); 
				return YYerror; 
			}

%%