%{
	
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>
	#include "EnumsAndDefs.h"
	#include "SyntaxAnalUtils.h"
	#include "SymbolTabs.h"
	#include "../../ErrorOutputHandler/ErrorHandler.h"
	#include "SemanticAnal.h"

	extern int yylex(void);
	extern int yylineno;
	extern FILE* yyin;
	int yyparse(void);
	int yyerror(const char *);

%}

%union {
  int i;
  char* s;
}

%token _NEW_LINE _INDENT _DEDENT 

%token _INIT
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

%token _COMMA _DOT _COLON 

%token _LBRACKET _RBRACKET
%token _LPAREN _RPAREN
%token _ASSIGN

%token <i> _ADD_SUB_OP _MUL_DIV_OP _LOP _RELOP

%token <s> _ID
%token <s> _NUM_BOOL _STRING _NONE

%type <i> literal, exp, num_exp

%nonassoc PAREN_ASSOC_TOKEN 
%nonassoc _LPAREN
%nonassoc _RPAREN

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
	| file new_line
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
	| func_meth_call_or_class_inst
	| _BREAK
	| _CONTINUE
	| _PASS
	;

compound_statement
	: function_def
	| class_def
	| if_statement
	| while_statement
	| for_statement
	| try_except_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp
		{
			int index = findSymbolByName($1);

			if(index == NO_INDEX)
				index = insertVariableToTable($1, false, getSymbDataType($3), 1);
		}
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

func_meth_call_or_class_inst
	: _ID _LPAREN arguments _RPAREN 
	| _ID _DOT _ID _LPAREN arguments _RPAREN
	| func_meth_call_or_class_inst _DOT _ID _LPAREN arguments _RPAREN
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

class_def
	: _CLASS _ID _COLON new_line class_body
	;

class_body
	: _INDENT class_methods _DEDENT
	;

class_methods
	: singular_method
	| class_methods singular_method 
	;

singular_method 
	: _DEF _INIT _LPAREN _ID init_method_params _RPAREN _COLON new_line body
	| function_def
	;

init_method_params
	: %empty
	| _COMMA parameters
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
	: exp	{ $$ = $1; }
	| _NOT num_exp  
	| num_exp _ADD_SUB_OP num_exp
		{
			char errMessage[200];
			DataType newType;
			if (!aritOpExpTypesValidation(errMessage, &newType, getSymbDataType($1), getSymbDataType($3), $2))
					return raiseError(SEMANTIC_ERR, yylineno, errMessage);
			setSymbDataType($1, newType);
		}
	| num_exp _MUL_DIV_OP num_exp
		{
			char errMessage[200];
			DataType newType;
			if (!aritOpExpTypesValidation(errMessage, &newType, getSymbDataType($1), getSymbDataType($3), $2))
					return raiseError(SEMANTIC_ERR, yylineno, errMessage);
			setSymbDataType($1, newType);
		}
	| num_exp _LOP num_exp
		{
		}
	| num_exp _RELOP num_exp
		{
			char errMessage[200];
			if (!relopExpTypesValidation(errMessage, getSymbDataType($1), getSymbDataType($3), $2))
					return raiseError(SEMANTIC_ERR, yylineno, errMessage);
		}
	;
	
exp
	: literal	{ $$ = $1; }
	| _ID %prec PAREN_ASSOC_TOKEN	
		{ 
			int idInd = findSymbolByName($1);
			if (idInd == NO_INDEX)
				return raiseError(SEMANTIC_ERR, yylineno, "Variable '%s' isn't defined yet!", $1);
			$$ = idInd; 
		}
	| func_meth_call_or_class_inst
	| _LPAREN num_exp _RPAREN	{ $$ = $2; }
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
	: _NUM_BOOL	{ $$ = insertLiteralToTable($1, NUM_BOOL); }
	| _STRING	{ $$ = insertLiteralToTable($1, STRING); }
	| _NONE		{ $$ = insertLiteralToTable($1, NONE); }
	;

new_line
	: _NEW_LINE 
	| new_line _NEW_LINE
	;

%%


int parser_main(int argc, char* argv[]) {
	int synerr;
	appendNewLineToFileIfNotExists(yyin);
	fopen_s(&yyin, INPUT_FILE_PATH , "r");
	synerr = yyparse(); 
	fclose(yyin);

	return synerr;
}

int yyerror(const char* errMess) {
	return raiseError(
		SYNTAX_ERR,
		yylineno,
		"unexpected token"
	);
}