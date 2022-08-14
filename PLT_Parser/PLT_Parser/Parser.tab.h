
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _NEW_LINE = 258,
     _INDENT = 259,
     _DEDENT = 260,
     _AND = 261,
     _BREAK = 262,
     _CLASS = 263,
     _CONTINUE = 264,
     _DEF = 265,
     _ELIF = 266,
     _ELSE = 267,
     _EXCEPT = 268,
     _FINALLY = 269,
     _FOR = 270,
     _IF = 271,
     _IN = 272,
     _NOT = 273,
     _OR = 274,
     _PASS = 275,
     _RETURN = 276,
     _TRY = 277,
     _WHILE = 278,
     _COMMA = 279,
     _COLON = 280,
     _LBRACKET = 281,
     _RBRACKET = 282,
     _LPAREN = 283,
     _RPAREN = 284,
     _ASSIGN = 285,
     _ADD_SUB_OP = 286,
     _MUL_DIV_OP = 287,
     _LOP = 288,
     _RELOP = 289,
     _ID = 290,
     _NUM_BOOL = 291,
     _STRING = 292,
     _NONE = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 11 "Parser.y"

  int i;
  char *s;



/* Line 1676 of yacc.c  */
#line 97 "Parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


