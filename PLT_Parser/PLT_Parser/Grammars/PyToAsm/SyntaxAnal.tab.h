/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAXANAL_TAB_H_INCLUDED
# define YY_YY_SYNTAXANAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _NEW_LINE = 258,               /* _NEW_LINE  */
    _INDENT = 259,                 /* _INDENT  */
    _DEDENT = 260,                 /* _DEDENT  */
    _AND = 261,                    /* _AND  */
    _BREAK = 262,                  /* _BREAK  */
    _CLASS = 263,                  /* _CLASS  */
    _CONTINUE = 264,               /* _CONTINUE  */
    _DEF = 265,                    /* _DEF  */
    _ELIF = 266,                   /* _ELIF  */
    _ELSE = 267,                   /* _ELSE  */
    _EXCEPT = 268,                 /* _EXCEPT  */
    _FINALLY = 269,                /* _FINALLY  */
    _FOR = 270,                    /* _FOR  */
    _IF = 271,                     /* _IF  */
    _IN = 272,                     /* _IN  */
    _NOT = 273,                    /* _NOT  */
    _OR = 274,                     /* _OR  */
    _PASS = 275,                   /* _PASS  */
    _RETURN = 276,                 /* _RETURN  */
    _TRY = 277,                    /* _TRY  */
    _WHILE = 278,                  /* _WHILE  */
    _COMMA = 279,                  /* _COMMA  */
    _COLON = 280,                  /* _COLON  */
    _LBRACKET = 281,               /* _LBRACKET  */
    _RBRACKET = 282,               /* _RBRACKET  */
    _LPAREN = 283,                 /* _LPAREN  */
    _RPAREN = 284,                 /* _RPAREN  */
    _ASSIGN = 285,                 /* _ASSIGN  */
    _ADD_SUB_OP = 286,             /* _ADD_SUB_OP  */
    _MUL_DIV_OP = 287,             /* _MUL_DIV_OP  */
    _LOP = 288,                    /* _LOP  */
    _RELOP = 289,                  /* _RELOP  */
    _ID = 290,                     /* _ID  */
    _NUM_BOOL = 291,               /* _NUM_BOOL  */
    _STRING = 292,                 /* _STRING  */
    _NONE = 293,                   /* _NONE  */
    VAR_ID = 294                   /* VAR_ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "SyntaxAnal.y"

  int i;
  char *s;

#line 108 "SyntaxAnal.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAXANAL_TAB_H_INCLUDED  */
