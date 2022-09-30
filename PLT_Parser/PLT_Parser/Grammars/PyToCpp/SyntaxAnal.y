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
%token _FOR
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

%token <i> _LOP _RELOP _ADD_SUB_OP _MUL_DIV_OP

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
		{
			if (!checkIfIsInLoop())
				return raiseError(SEMANTIC_ERR, yylineno, "'break' statement must be inside a 'while' or 'for' loop.");
		}
	| _CONTINUE
		{
			if (!checkIfIsInLoop())
				return raiseError(SEMANTIC_ERR, yylineno, "'continue' statement must be inside a 'while' or 'for' loop.");
		}
	| _PASS
	;

compound_statement
	: function_def
	| class_def
	| if_statement
	| while_statement
	| for_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp
		{
			int index = findSymbolByName($1);

			if(index == NO_INDEX || checkIfIsGivenTableType(index, TB_FUNCS))
				index = insertVariableToTable($1, getSymbDataType($3));
		}
	; 

multi_assign_statement
	: multi_assign_vars multi_assign_values 
		{
			if (!multiAssIsEqualNumOfVarsAndVals())
				return raiseError(SEMANTIC_ERR, yylineno, "There must be equal number of variables and values in multiple assignment statement");
			resetMultiAssCounters();
		}
	;

multi_assign_vars
	: _ID _COMMA _ID 
		{
			addVarToMultiAssArray($1);
			addVarToMultiAssArray($3);
		}
	| multi_assign_vars _COMMA _ID 
		{
			addVarToMultiAssArray($3);
		}
	;
	
multi_assign_values
	: _ASSIGN num_exp 
		{
			setVarDataTypeInMultiAss($2);
		}
	  _COMMA num_exp
		{
			setVarDataTypeInMultiAss($5);
		}
	| multi_assign_values _COMMA num_exp
		{
			setVarDataTypeInMultiAss($3);
		}
	;

return_statement
	: return_token
		{
			updateFuncRetType(NONE);
		}
	| return_token num_exp
		{
			updateFuncRetType(getSymbDataType($2));
		}
	;

return_token
	: _RETURN 
		{
			if (!canUseReturnStatement)
				return raiseError(SEMANTIC_ERR, yylineno, "'Return' statement must be inside a function definition.");
		}
	;

func_meth_call_or_class_inst
	: singular_func_call_or_class_inst
	| _ID 
		{
			if (!methodIsCalledOnClass($1))
				return raiseError(SEMANTIC_ERR, yylineno, "Cannot call members on identifier '%s' as it is not a class.", $1);

		}
	  _DOT singular_func_call_or_class_inst
	| func_meth_call_or_class_inst _DOT singular_func_call_or_class_inst
	;
	
singular_func_call_or_class_inst
	: _ID _LPAREN arguments _RPAREN
		{
			int ind = findSymbolByName($1);
			if (!canCallFuncOrInstClass(ind))
				return raiseError(SEMANTIC_ERR, yylineno, "Cannot call identifier '%s' or is unknown.", $1);
			
			if (!argsNumEqParamNum(ind))
				return raiseError(SEMANTIC_ERR, yylineno, "Invalid number of arguments given on identifier '%s' call.", $1);
				
			resetArgsNum();
		}
	;

arguments
	: %empty  /* no arguments */
	| arguments arg_list
	;
	
arg_list
	: arg
	| arg_list _COMMA arg
	;

arg
	: num_exp { incArgsNum(); }
	;

function_def
	: _DEF _ID 
		{
			incCurrNestFuncArrInd();
			setCurrFuncIndex(insertFunctionToTable($2, false, NO_DATA_TYPE));
		}
	  _LPAREN parameters 
		{
			setCanDefNonDefParams(true);
		} 
	  _RPAREN _COLON new_line body 
	;

parameters 
	: %empty  /* no params */
	| param_without_default_val
	| param_with_default_val
	| parameters _COMMA param_without_default_val
	| parameters _COMMA param_with_default_val
	;

param_without_default_val
	: _ID
		{
			if (!canDefNonDefParams())
				return raiseError(SEMANTIC_ERR, yylineno, "Cannot define parameters without default values after defining parameter with default value.");
			setNextFuncParam(getCurrFuncIndex(), insertParameterToTable($1, UNKNOWN, false), false);
		}
	;

param_with_default_val
	: _ID _ASSIGN num_exp
		{
			
			setNextFuncParam(getCurrFuncIndex(), insertParameterToTable($1, getSymbDataType($3), true), true);
			setCanDefNonDefParams(false);
		}
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
	: _WHILE num_exp _COLON new_line
		{
			incLoopCounter();				
		}
	  body
		{
			decLoopCounter();
		}
	  else_part 
	;

for_statement
	: _FOR _ID _IN num_exp _COLON new_line 
		{
			incLoopCounter();				
		}
	  body 
		{
			decLoopCounter();
		}
	  else_part
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
		{
		}
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
			setSymbDataType($1, NUM_BOOL);
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