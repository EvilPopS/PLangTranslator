%{
	
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>

	int yyerror(const char *);

%}

%union {
  int i;
  char *s;
}

%token _NEW_LINE _INDENT _DEDENT 

%token _AND
%token _BREAK
%token _CONTINUE
%token _DEF
%token _ELIF _ELSE _EXCEPT
%token _FINALLY _FOR
%token _IF _IN
%token _NOT
%token _OR
%token _PASS
%token _RETURN
%token _TRY
%token _WHILE

%token _COMMA _COLON

%token _LPAREN _RPAREN
%token _ASSIGN

%token <i> _ADD_SUB_OP _MUL_DIV_OP _LOP _RELOP

%token <s> _ID
%token <s> _NUM_BOOL _STRING _NONE


%%

TEMP
	: _COMMA

%%


int parser_main(int argc, char* argv[]) {
	return 0;
}
int yyerror(const char *s) {
	fprintf(stderr, "SYNTAX ERROR %s\n", s);
	return 0;
}