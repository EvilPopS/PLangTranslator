%{
	
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>
	#include "EnumsAndDefs.h"
	#include "SyntaxMainHeader.h"

	extern int yylex(void);
	extern int yylineno;
	extern FILE* yyin;
	int yyparse(void);
	int yyerror(const char *);

%}

%union {
  int i;
  char *s;
}

%token _NEW_LINE _INDENT _DEDENT 

%token _AND
%token _BREAK
%token _CLASS
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

%token _LBRACKET _RBRACKET
%token _LPAREN _RPAREN
%token _ASSIGN

%token <i> _ADD_SUB_OP _MUL_DIV_OP _LOP _RELOP

%token <s> _ID
%token <s> _NUM_BOOL _STRING _NONE

%nonassoc VAR_ID 
%nonassoc _LPAREN

%left _LOP
%right _NOT
%left _RELOP
%left _ADD_SUB_OP
%left _MUL_DIV_OP 

%%

file
	: %empty  /* empty */ 
	| statement_list
	| new_line statement_list
	;

statement_list
	: statement
	| statement_list statement 
	;

statement
	: simple_statement new_line 
	| compound_statement 
	;

simple_statement
	: assign_statement
	| multi_assign_statement
	| return_statement
	| function_call
	| _BREAK
	| _CONTINUE
	| _PASS
	;

compound_statement
	: function_def
	| if_statement
	| while_statement
	| for_statement
	| try_except_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp
	; 

multi_assign_statement
	: multi_assign_vars multi_assign_values 
	;

multi_assign_vars
	: _ID _COMMA _ID 
	| multi_assign_vars _COMMA _ID 
	;
	
multi_assign_values
	: _ASSIGN num_exp _COMMA num_exp 
	| multi_assign_values _COMMA num_exp 
	;

return_statement
	: _RETURN
	| _RETURN num_exp
	;

function_call
	: _ID _LPAREN arguments _RPAREN
	;
	
arguments
	: %empty  /* no arguments */
	| arguments args
	;
	
args
	: num_exp
	| args _COMMA num_exp
	;

function_def
	: _DEF _ID _LPAREN parameters _RPAREN _COLON new_line body 
	;

parameters 
	: %empty  /* no params */
	| _ID  						
	| param_with_default_val
	| parameters _COMMA _ID		
	| parameters _COMMA param_with_default_val
	;
	
param_with_default_val
	: _ID _ASSIGN num_exp
	;

if_statement
	: if_part elif_part else_part 
	;

if_part
	: _IF num_exp _COLON new_line body
	;
	
elif_part
	: %empty  /* no elif part*/
	| elif_part _ELIF num_exp _COLON new_line body
	;

while_statement
	: _WHILE num_exp _COLON new_line body else_part 
	;

for_statement
	: _FOR _ID _IN num_exp _COLON new_line body else_part
	;

try_except_statement
	: _TRY _COLON new_line body except_part finally_or_else_part
	;

except_part
	: %empty  /* no except block */
	| except_part _EXCEPT _ID _COLON new_line body
	| except_part _EXCEPT _COLON new_line body
	;

finally_or_else_part
	: %empty  /* no else or finally part */
	| _FINALLY _COLON new_line body
	| _ELSE _COLON new_line body
	;

else_part
	: %empty  /* no else part*/
	|_ELSE _COLON new_line body
	;

body
	: _INDENT statement_list _DEDENT 
	;

num_exp
	: exp
	| _NOT num_exp  
	| num_exp _ADD_SUB_OP num_exp
	| num_exp _MUL_DIV_OP num_exp
	| num_exp _LOP num_exp
	| num_exp _RELOP num_exp
	;
	
exp
	: literal
	| _ID %prec VAR_ID
	| function_call
	| _LPAREN num_exp _RPAREN
	| list
	;
	
list
	: _LBRACKET list_elements _RBRACKET
	;

list_elements
	: %empty 
	| num_exp
	| list_elements _COMMA num_exp
	;

literal
	: _NUM_BOOL
	| _STRING
	| _NONE
	;

new_line
	: _NEW_LINE 
	| new_line _NEW_LINE
	;

%%


int parser_main(int argc, char* argv[]) {
	int synerr;

	fopen_s(&yyin, "Tests/PyToAsm/test1.txt" , "r");

	synerr = yyparse(); 

	fclose(yyin);

	printf("%d", synerr);
	if(synerr)
		return -1;
	else
		return 0;
}

int yyerror(const char *s) {
	fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
	return 0;
}