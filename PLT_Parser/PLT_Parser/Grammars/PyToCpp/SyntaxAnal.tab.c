/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "SyntaxAnal.y"

	
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


#line 90 "SyntaxAnal.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "SyntaxAnal.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__NEW_LINE = 3,                  /* _NEW_LINE  */
  YYSYMBOL__INDENT = 4,                    /* _INDENT  */
  YYSYMBOL__DEDENT = 5,                    /* _DEDENT  */
  YYSYMBOL__INIT = 6,                      /* _INIT  */
  YYSYMBOL__AND = 7,                       /* _AND  */
  YYSYMBOL__BREAK = 8,                     /* _BREAK  */
  YYSYMBOL__CLASS = 9,                     /* _CLASS  */
  YYSYMBOL__CONTINUE = 10,                 /* _CONTINUE  */
  YYSYMBOL__DEF = 11,                      /* _DEF  */
  YYSYMBOL__ELIF = 12,                     /* _ELIF  */
  YYSYMBOL__ELSE = 13,                     /* _ELSE  */
  YYSYMBOL__EXCEPT = 14,                   /* _EXCEPT  */
  YYSYMBOL__FOR = 15,                      /* _FOR  */
  YYSYMBOL__IF = 16,                       /* _IF  */
  YYSYMBOL__IN = 17,                       /* _IN  */
  YYSYMBOL__NOT = 18,                      /* _NOT  */
  YYSYMBOL__OR = 19,                       /* _OR  */
  YYSYMBOL__PASS = 20,                     /* _PASS  */
  YYSYMBOL__RETURN = 21,                   /* _RETURN  */
  YYSYMBOL__TRY = 22,                      /* _TRY  */
  YYSYMBOL__WHILE = 23,                    /* _WHILE  */
  YYSYMBOL__COMMA = 24,                    /* _COMMA  */
  YYSYMBOL__DOT = 25,                      /* _DOT  */
  YYSYMBOL__COLON = 26,                    /* _COLON  */
  YYSYMBOL__LBRACKET = 27,                 /* _LBRACKET  */
  YYSYMBOL__RBRACKET = 28,                 /* _RBRACKET  */
  YYSYMBOL__LPAREN = 29,                   /* _LPAREN  */
  YYSYMBOL__RPAREN = 30,                   /* _RPAREN  */
  YYSYMBOL__ASSIGN = 31,                   /* _ASSIGN  */
  YYSYMBOL__LOP = 32,                      /* _LOP  */
  YYSYMBOL__RELOP = 33,                    /* _RELOP  */
  YYSYMBOL__ADD_SUB_OP = 34,               /* _ADD_SUB_OP  */
  YYSYMBOL__MUL_DIV_OP = 35,               /* _MUL_DIV_OP  */
  YYSYMBOL__ID = 36,                       /* _ID  */
  YYSYMBOL__NUM_BOOL = 37,                 /* _NUM_BOOL  */
  YYSYMBOL__STRING = 38,                   /* _STRING  */
  YYSYMBOL__NONE = 39,                     /* _NONE  */
  YYSYMBOL_PAREN_ASSOC_TOKEN = 40,         /* PAREN_ASSOC_TOKEN  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_file = 42,                      /* file  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_simple_statement = 45,          /* simple_statement  */
  YYSYMBOL_compound_statement = 46,        /* compound_statement  */
  YYSYMBOL_assign_statement = 47,          /* assign_statement  */
  YYSYMBOL_multi_assign_statement = 48,    /* multi_assign_statement  */
  YYSYMBOL_multi_assign_vars = 49,         /* multi_assign_vars  */
  YYSYMBOL_multi_assign_values = 50,       /* multi_assign_values  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_return_statement = 52,          /* return_statement  */
  YYSYMBOL_return_token = 53,              /* return_token  */
  YYSYMBOL_func_meth_call_or_class_inst = 54, /* func_meth_call_or_class_inst  */
  YYSYMBOL_arguments = 55,                 /* arguments  */
  YYSYMBOL_args = 56,                      /* args  */
  YYSYMBOL_function_def = 57,              /* function_def  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_parameters = 60,                /* parameters  */
  YYSYMBOL_param_without_default_val = 61, /* param_without_default_val  */
  YYSYMBOL_param_with_default_val = 62,    /* param_with_default_val  */
  YYSYMBOL_class_def = 63,                 /* class_def  */
  YYSYMBOL_class_body = 64,                /* class_body  */
  YYSYMBOL_class_methods = 65,             /* class_methods  */
  YYSYMBOL_singular_method = 66,           /* singular_method  */
  YYSYMBOL_init_method_params = 67,        /* init_method_params  */
  YYSYMBOL_if_statement = 68,              /* if_statement  */
  YYSYMBOL_if_part = 69,                   /* if_part  */
  YYSYMBOL_elif_part = 70,                 /* elif_part  */
  YYSYMBOL_while_statement = 71,           /* while_statement  */
  YYSYMBOL_72_4 = 72,                      /* $@4  */
  YYSYMBOL_73_5 = 73,                      /* $@5  */
  YYSYMBOL_for_statement = 74,             /* for_statement  */
  YYSYMBOL_75_6 = 75,                      /* $@6  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_else_part = 77,                 /* else_part  */
  YYSYMBOL_body = 78,                      /* body  */
  YYSYMBOL_num_exp = 79,                   /* num_exp  */
  YYSYMBOL_exp = 80,                       /* exp  */
  YYSYMBOL_list = 81,                      /* list  */
  YYSYMBOL_list_elements = 82,             /* list_elements  */
  YYSYMBOL_literal = 83,                   /* literal  */
  YYSYMBOL_new_line = 84                   /* new_line  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    70,    71,    72,    76,    77,    81,    82,
      86,    87,    88,    89,    90,    95,   100,   104,   105,   106,
     107,   108,   112,   122,   131,   136,   144,   143,   151,   158,
     162,   169,   177,   178,   179,   183,   184,   188,   189,   194,
     199,   193,   206,   207,   208,   209,   210,   214,   223,   232,
     236,   240,   241,   245,   246,   250,   251,   255,   259,   263,
     264,   269,   273,   268,   281,   285,   280,   292,   293,   297,
     301,   302,   305,   313,   321,   324,   334,   335,   342,   343,
     344,   348,   352,   353,   354,   358,   359,   360,   364,   365
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_NEW_LINE", "_INDENT",
  "_DEDENT", "_INIT", "_AND", "_BREAK", "_CLASS", "_CONTINUE", "_DEF",
  "_ELIF", "_ELSE", "_EXCEPT", "_FOR", "_IF", "_IN", "_NOT", "_OR",
  "_PASS", "_RETURN", "_TRY", "_WHILE", "_COMMA", "_DOT", "_COLON",
  "_LBRACKET", "_RBRACKET", "_LPAREN", "_RPAREN", "_ASSIGN", "_LOP",
  "_RELOP", "_ADD_SUB_OP", "_MUL_DIV_OP", "_ID", "_NUM_BOOL", "_STRING",
  "_NONE", "PAREN_ASSOC_TOKEN", "$accept", "file", "statement_list",
  "statement", "simple_statement", "compound_statement",
  "assign_statement", "multi_assign_statement", "multi_assign_vars",
  "multi_assign_values", "$@1", "return_statement", "return_token",
  "func_meth_call_or_class_inst", "arguments", "args", "function_def",
  "$@2", "$@3", "parameters", "param_without_default_val",
  "param_with_default_val", "class_def", "class_body", "class_methods",
  "singular_method", "init_method_params", "if_statement", "if_part",
  "elif_part", "while_statement", "$@4", "$@5", "for_statement", "$@6",
  "$@7", "else_part", "body", "num_exp", "exp", "list", "list_elements",
  "literal", "new_line", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      82,  -130,  -130,   -18,  -130,    -4,     5,   150,  -130,  -130,
     150,    13,    48,   155,  -130,    40,  -130,  -130,  -130,    -2,
    -130,   150,   -17,  -130,  -130,  -130,  -130,  -130,  -130,   121,
      27,  -130,    62,   150,   150,   150,    55,  -130,  -130,  -130,
     -17,    43,  -130,  -130,  -130,   164,    38,    52,  -130,   150,
    -130,    93,  -130,    93,    75,   150,    88,   148,    85,    87,
    -130,   155,    40,   106,   150,    92,   148,    58,   184,    40,
     150,   150,   150,   150,    40,  -130,   116,   -13,   148,  -130,
     148,   150,   122,   150,    96,  -130,    57,    97,   168,   150,
    -130,  -130,   105,    92,   104,   115,  -130,    93,  -130,  -130,
     131,   148,   132,   148,  -130,   178,    40,   149,  -130,   136,
     145,  -130,  -130,    40,   148,   155,  -130,   158,    29,   150,
     150,    77,    40,   105,     3,  -130,     8,  -130,   150,    97,
     142,    93,   138,  -130,  -130,   148,   148,  -130,   105,  -130,
     144,  -130,  -130,   148,  -130,  -130,   159,   158,  -130,   171,
    -130,   156,    40,  -130,  -130,   169,   105,   171,    97,   165,
    -130,  -130,   145,   179,    40,   105,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    88,    14,     0,    15,     0,     0,     0,    16,    31,
       0,     0,     0,     3,     6,     0,     9,    10,    11,     0,
      12,    29,    13,    17,    18,    19,    59,    20,    21,     0,
       0,    39,     0,     0,    82,     0,    77,    85,    86,    87,
      78,     0,    70,    80,    76,     0,     0,     0,    35,     0,
       1,     5,     7,     8,     0,     0,    23,    30,     0,    67,
      89,     4,     0,     0,     0,    71,    83,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    22,    25,
      26,     0,     0,     0,     0,    57,     0,    42,     0,     0,
      81,    79,     0,    74,    75,    72,    73,    61,    35,    32,
      36,    37,     0,    28,    35,     0,     0,     0,    49,    47,
      40,    43,    44,     0,    84,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,    51,     0,     0,
       0,    64,     0,    62,    33,    38,    27,    34,     0,    68,
       0,    50,    52,    48,    45,    46,     0,     0,    69,    67,
      60,     0,     0,    65,    63,    55,     0,    67,    42,     0,
      41,    66,    56,     0,     0,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   -28,    -9,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,     2,   -58,  -130,   -96,  -130,  -130,    49,
      79,    80,  -130,  -130,  -130,    89,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -129,  -111,     0,  -130,
    -130,  -130,  -130,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    56,
     102,    20,    21,    40,    77,   100,    23,    63,   130,   110,
     111,   112,    24,   108,   126,   127,   159,    25,    26,    59,
      27,   117,   149,    28,   147,   157,    85,   116,   101,    42,
      43,    67,    44,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    61,    22,    53,    52,    33,   133,    41,    58,   140,
      45,   125,   139,   141,    34,    22,    35,    99,    30,   124,
     154,    57,    54,    36,    37,    38,    39,   150,   161,    55,
     125,    22,    31,    65,    66,    68,   153,    46,    47,    31,
     118,    32,    48,     1,    49,   160,   121,    33,    50,    78,
      86,     1,    52,    62,   166,    80,    34,    92,    35,   134,
      60,   107,    97,    22,    88,    36,    37,    38,    39,    69,
      93,    94,    95,    96,    75,    70,    71,    72,    73,    64,
      47,   103,    89,   105,    48,     1,    90,   132,    76,   114,
       2,     3,     4,     5,   123,    33,    60,     6,     7,    83,
      84,   131,     8,     9,    34,    10,    35,   137,    60,   115,
     138,    79,    81,    36,    37,    38,    39,    22,    11,   135,
     136,    82,   106,    52,    60,    71,    72,    73,   143,     2,
       3,     4,     5,   109,    22,    87,     6,     7,    72,    73,
     156,     8,     9,   148,    10,    98,     2,     3,     4,     5,
      73,   104,   165,     6,     7,   119,   120,    11,     8,     9,
     124,    10,   115,     2,     3,     4,     5,   128,    33,   129,
       6,     7,   146,   151,    11,     8,     9,    34,    10,    35,
      70,    71,    72,    73,    84,   152,    36,    37,    38,    39,
      74,    11,   155,   158,   113,   163,    70,    71,    72,    73,
      70,    71,    72,    73,   122,   164,     0,   162,   144,   145,
      70,    71,    72,    73,    91,   142,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      12,    29,     0,    15,    13,    18,   117,     7,    25,     6,
      10,   107,   123,     5,    27,    13,    29,    30,    36,    11,
     149,    21,    24,    36,    37,    38,    39,   138,   157,    31,
     126,    29,    36,    33,    34,    35,   147,    24,    25,    36,
      98,    36,    29,     3,    31,   156,   104,    18,     0,    49,
      62,     3,    61,    26,   165,    55,    27,    69,    29,    30,
       3,     4,    74,    61,    64,    36,    37,    38,    39,    26,
      70,    71,    72,    73,    36,    32,    33,    34,    35,    17,
      25,    81,    24,    83,    29,     3,    28,   115,    36,    89,
       8,     9,    10,    11,   106,    18,     3,    15,    16,    12,
      13,   113,    20,    21,    27,    23,    29,    30,     3,     4,
     122,    36,    24,    36,    37,    38,    39,   115,    36,   119,
     120,    36,    26,   132,     3,    33,    34,    35,   128,     8,
       9,    10,    11,    36,   132,    29,    15,    16,    34,    35,
     152,    20,    21,     5,    23,    29,     8,     9,    10,    11,
      35,    29,   164,    15,    16,    24,    24,    36,    20,    21,
      11,    23,     4,     8,     9,    10,    11,    31,    18,    24,
      15,    16,    30,    29,    36,    20,    21,    27,    23,    29,
      32,    33,    34,    35,    13,    26,    36,    37,    38,    39,
      26,    36,    36,    24,    26,    30,    32,    33,    34,    35,
      32,    33,    34,    35,    26,    26,    -1,   158,   129,   129,
      32,    33,    34,    35,    30,   126,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,     9,    10,    11,    15,    16,    20,    21,
      23,    36,    42,    43,    44,    45,    46,    47,    48,    49,
      52,    53,    54,    57,    63,    68,    69,    71,    74,    84,
      36,    36,    36,    18,    27,    29,    36,    37,    38,    39,
      54,    79,    80,    81,    83,    79,    24,    25,    29,    31,
       0,    84,    44,    84,    24,    31,    50,    79,    25,    70,
       3,    43,    26,    58,    17,    79,    79,    82,    79,    26,
      32,    33,    34,    35,    26,    36,    36,    55,    79,    36,
      79,    24,    36,    12,    13,    77,    84,    29,    79,    24,
      28,    30,    84,    79,    79,    79,    79,    84,    29,    30,
      56,    79,    51,    79,    29,    79,    26,     4,    64,    36,
      60,    61,    62,    26,    79,     4,    78,    72,    55,    24,
      24,    55,    26,    84,    11,    57,    65,    66,    31,    24,
      59,    84,    43,    78,    30,    79,    79,    30,    84,    78,
       6,     5,    66,    79,    61,    62,    30,    75,     5,    73,
      78,    29,    26,    78,    77,    36,    84,    76,    24,    67,
      78,    77,    60,    30,    26,    84,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    43,    43,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    46,
      46,    46,    47,    48,    49,    49,    51,    50,    50,    52,
      52,    53,    54,    54,    54,    55,    55,    56,    56,    58,
      59,    57,    60,    60,    60,    60,    60,    61,    62,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    69,    70,
      70,    72,    73,    71,    75,    76,    74,    77,    77,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    81,    82,    82,    82,    83,    83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     2,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     0,     5,     3,     1,
       2,     1,     4,     6,     6,     0,     2,     1,     3,     0,
       0,    10,     0,     1,     1,     3,     3,     1,     3,     5,
       3,     1,     2,     9,     1,     0,     2,     3,     5,     0,
       6,     0,     0,     8,     0,     0,    10,     0,     4,     3,
       1,     2,     3,     3,     3,     3,     1,     1,     1,     3,
       1,     3,     0,     1,     3,     1,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 14: /* simple_statement: _BREAK  */
#line 91 "SyntaxAnal.y"
                {
			if (!checkIfIsInLoop())
				return raiseError(SEMANTIC_ERR, yylineno, "'break' statement must be inside a 'while' or 'for' loop.");
		}
#line 1290 "SyntaxAnal.tab.c"
    break;

  case 15: /* simple_statement: _CONTINUE  */
#line 96 "SyntaxAnal.y"
                {
			if (!checkIfIsInLoop())
				return raiseError(SEMANTIC_ERR, yylineno, "'continue' statement must be inside a 'while' or 'for' loop.");
		}
#line 1299 "SyntaxAnal.tab.c"
    break;

  case 22: /* assign_statement: _ID _ASSIGN num_exp  */
#line 113 "SyntaxAnal.y"
                {
			int index = findSymbolByName((yyvsp[-2].s));

			if(index == NO_INDEX)
				index = insertVariableToTable((yyvsp[-2].s), getSymbDataType((yyvsp[0].i)));
		}
#line 1310 "SyntaxAnal.tab.c"
    break;

  case 23: /* multi_assign_statement: multi_assign_vars multi_assign_values  */
#line 123 "SyntaxAnal.y"
                {
			if (!multiAssIsEqualNumOfVarsAndVals())
				return raiseError(SEMANTIC_ERR, yylineno, "There must be equal number of variables and values in multiple assignment statement");
			resetMultiAssCounters();
		}
#line 1320 "SyntaxAnal.tab.c"
    break;

  case 24: /* multi_assign_vars: _ID _COMMA _ID  */
#line 132 "SyntaxAnal.y"
                {
			addVarToMultiAssArray((yyvsp[-2].s));
			addVarToMultiAssArray((yyvsp[0].s));
		}
#line 1329 "SyntaxAnal.tab.c"
    break;

  case 25: /* multi_assign_vars: multi_assign_vars _COMMA _ID  */
#line 137 "SyntaxAnal.y"
                {
			addVarToMultiAssArray((yyvsp[0].s));
		}
#line 1337 "SyntaxAnal.tab.c"
    break;

  case 26: /* $@1: %empty  */
#line 144 "SyntaxAnal.y"
                {
			setVarDataTypeInMultiAss((yyvsp[0].i));
		}
#line 1345 "SyntaxAnal.tab.c"
    break;

  case 27: /* multi_assign_values: _ASSIGN num_exp $@1 _COMMA num_exp  */
#line 148 "SyntaxAnal.y"
                {
			setVarDataTypeInMultiAss((yyvsp[0].i));
		}
#line 1353 "SyntaxAnal.tab.c"
    break;

  case 28: /* multi_assign_values: multi_assign_values _COMMA num_exp  */
#line 152 "SyntaxAnal.y"
                {
			setVarDataTypeInMultiAss((yyvsp[0].i));
		}
#line 1361 "SyntaxAnal.tab.c"
    break;

  case 29: /* return_statement: return_token  */
#line 159 "SyntaxAnal.y"
                {
			updateFuncRetType(NONE);
		}
#line 1369 "SyntaxAnal.tab.c"
    break;

  case 30: /* return_statement: return_token num_exp  */
#line 163 "SyntaxAnal.y"
                {
			updateFuncRetType(getSymbDataType((yyvsp[0].i)));
		}
#line 1377 "SyntaxAnal.tab.c"
    break;

  case 31: /* return_token: _RETURN  */
#line 170 "SyntaxAnal.y"
                {
			if (!canUseReturnStatement)
				return raiseError(SEMANTIC_ERR, yylineno, "'Return' statement must be inside a function definition.");
		}
#line 1386 "SyntaxAnal.tab.c"
    break;

  case 39: /* $@2: %empty  */
#line 194 "SyntaxAnal.y"
                {
			incCurrNestFuncArrInd();
			setCurrFuncIndex(insertFunctionToTable((yyvsp[0].s), false, NO_DATA_TYPE));
		}
#line 1395 "SyntaxAnal.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 199 "SyntaxAnal.y"
                {
			setCanDefNonDefParams(true);
		}
#line 1403 "SyntaxAnal.tab.c"
    break;

  case 47: /* param_without_default_val: _ID  */
#line 215 "SyntaxAnal.y"
                {
			if (!canDefNonDefParams())
				return raiseError(SEMANTIC_ERR, yylineno, "Cannot define parameters without default values after defining parameter with default value.");
			setNextFuncParam(getCurrFuncIndex(), insertParameterToTable((yyvsp[0].s), UNKNOWN, false), false);
		}
#line 1413 "SyntaxAnal.tab.c"
    break;

  case 48: /* param_with_default_val: _ID _ASSIGN num_exp  */
#line 224 "SyntaxAnal.y"
                {
			
			setNextFuncParam(getCurrFuncIndex(), insertParameterToTable((yyvsp[-2].s), getSymbDataType((yyvsp[0].i)), true), false);
			setCanDefNonDefParams(false);
		}
#line 1423 "SyntaxAnal.tab.c"
    break;

  case 61: /* $@4: %empty  */
#line 269 "SyntaxAnal.y"
                {
			incLoopCounter();				
		}
#line 1431 "SyntaxAnal.tab.c"
    break;

  case 62: /* $@5: %empty  */
#line 273 "SyntaxAnal.y"
                {
			decLoopCounter();
		}
#line 1439 "SyntaxAnal.tab.c"
    break;

  case 64: /* $@6: %empty  */
#line 281 "SyntaxAnal.y"
                {
			incLoopCounter();				
		}
#line 1447 "SyntaxAnal.tab.c"
    break;

  case 65: /* $@7: %empty  */
#line 285 "SyntaxAnal.y"
                {
			decLoopCounter();
		}
#line 1455 "SyntaxAnal.tab.c"
    break;

  case 70: /* num_exp: exp  */
#line 301 "SyntaxAnal.y"
                { (yyval.i) = (yyvsp[0].i); }
#line 1461 "SyntaxAnal.tab.c"
    break;

  case 71: /* num_exp: _NOT num_exp  */
#line 303 "SyntaxAnal.y"
                {
		}
#line 1468 "SyntaxAnal.tab.c"
    break;

  case 72: /* num_exp: num_exp _ADD_SUB_OP num_exp  */
#line 306 "SyntaxAnal.y"
                {
			char errMessage[200];
			DataType newType;
			if (!aritOpExpTypesValidation(errMessage, &newType, getSymbDataType((yyvsp[-2].i)), getSymbDataType((yyvsp[0].i)), (yyvsp[-1].i)))
					return raiseError(SEMANTIC_ERR, yylineno, errMessage);
			setSymbDataType((yyvsp[-2].i), newType); 
		}
#line 1480 "SyntaxAnal.tab.c"
    break;

  case 73: /* num_exp: num_exp _MUL_DIV_OP num_exp  */
#line 314 "SyntaxAnal.y"
                {
			char errMessage[200];
			DataType newType;
			if (!aritOpExpTypesValidation(errMessage, &newType, getSymbDataType((yyvsp[-2].i)), getSymbDataType((yyvsp[0].i)), (yyvsp[-1].i)))
					return raiseError(SEMANTIC_ERR, yylineno, errMessage);
			setSymbDataType((yyvsp[-2].i), newType);
		}
#line 1492 "SyntaxAnal.tab.c"
    break;

  case 74: /* num_exp: num_exp _LOP num_exp  */
#line 322 "SyntaxAnal.y"
                {
		}
#line 1499 "SyntaxAnal.tab.c"
    break;

  case 75: /* num_exp: num_exp _RELOP num_exp  */
#line 325 "SyntaxAnal.y"
                {
			char errMessage[200];
			if (!relopExpTypesValidation(errMessage, getSymbDataType((yyvsp[-2].i)), getSymbDataType((yyvsp[0].i)), (yyvsp[-1].i)))
					return raiseError(SEMANTIC_ERR, yylineno, errMessage);
			setSymbDataType((yyvsp[-2].i), NUM_BOOL);
		}
#line 1510 "SyntaxAnal.tab.c"
    break;

  case 76: /* exp: literal  */
#line 334 "SyntaxAnal.y"
                        { (yyval.i) = (yyvsp[0].i); }
#line 1516 "SyntaxAnal.tab.c"
    break;

  case 77: /* exp: _ID  */
#line 336 "SyntaxAnal.y"
                { 
			int idInd = findSymbolByName((yyvsp[0].s));
			if (idInd == NO_INDEX)
				return raiseError(SEMANTIC_ERR, yylineno, "Variable '%s' isn't defined yet!", (yyvsp[0].s));
			(yyval.i) = idInd; 
		}
#line 1527 "SyntaxAnal.tab.c"
    break;

  case 79: /* exp: _LPAREN num_exp _RPAREN  */
#line 343 "SyntaxAnal.y"
                                        { (yyval.i) = (yyvsp[-1].i); }
#line 1533 "SyntaxAnal.tab.c"
    break;

  case 85: /* literal: _NUM_BOOL  */
#line 358 "SyntaxAnal.y"
                        { (yyval.i) = insertLiteralToTable((yyvsp[0].s), NUM_BOOL); }
#line 1539 "SyntaxAnal.tab.c"
    break;

  case 86: /* literal: _STRING  */
#line 359 "SyntaxAnal.y"
                        { (yyval.i) = insertLiteralToTable((yyvsp[0].s), STRING); }
#line 1545 "SyntaxAnal.tab.c"
    break;

  case 87: /* literal: _NONE  */
#line 360 "SyntaxAnal.y"
                        { (yyval.i) = insertLiteralToTable((yyvsp[0].s), NONE); }
#line 1551 "SyntaxAnal.tab.c"
    break;


#line 1555 "SyntaxAnal.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 368 "SyntaxAnal.y"



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
