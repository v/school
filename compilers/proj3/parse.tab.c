/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parse.y"

#include <stdio.h>
#include "attr.h"
#include "instrutil.h"
int yylex();
void yyerror(char * s);
#include "symtab.h"
#include "deptest.h"

FILE *outfile;
char *CommentBuffer;
 


/* Line 189 of yacc.c  */
#line 87 "parse.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROG = 258,
     PERIOD = 259,
     VAR = 260,
     INT = 261,
     BOOL = 262,
     ARRAY = 263,
     RANGE = 264,
     OF = 265,
     WRITELN = 266,
     THEN = 267,
     IF = 268,
     BEG = 269,
     END = 270,
     ASG = 271,
     DO = 272,
     FOR = 273,
     EQ = 274,
     NEQ = 275,
     LT = 276,
     LEQ = 277,
     AND = 278,
     OR = 279,
     XOR = 280,
     NOT = 281,
     TRUE = 282,
     FALSE = 283,
     ELSE = 284,
     WHILE = 285,
     BOOLEAN = 286,
     EXOR = 287,
     ID = 288,
     ICONST = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 15 "parse.y"
tokentype token;
        regInfo targetReg;
		struct { int trueLabel; int falseLabel; int endLabel; } label;
        


/* Line 214 of yacc.c  */
#line 164 "parse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 176 "parse.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    37,    35,    39,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    11,    14,    15,    18,    22,    25,
      28,    31,    35,    38,    47,    49,    51,    53,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    74,    79,    83,
      84,    91,    94,    99,   100,   101,   108,   117,   121,   123,
     128,   132,   136,   140,   144,   148,   152,   156,   158,   163,
     165,   167,   171,   175,   179,   183,   185,   187,   189,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    -1,    47,     3,    33,    38,    48,     4,
      -1,    49,    57,    -1,    -1,     5,    50,    -1,    50,    51,
      38,    -1,    51,    38,    -1,     1,    38,    -1,    33,    52,
      -1,    39,    33,    52,    -1,    40,    53,    -1,     8,    41,
      34,     9,    34,    42,    10,    54,    -1,    54,    -1,     6,
      -1,    31,    -1,    55,    38,    56,    -1,    56,    -1,     1,
      -1,    59,    -1,    63,    -1,    66,    -1,    67,    -1,    62,
      -1,    57,    -1,    -1,    58,    14,    55,    15,    -1,    61,
      12,    56,    -1,    -1,    61,    12,    56,    29,    60,    56,
      -1,    13,    70,    -1,    11,    43,    69,    44,    -1,    -1,
      -1,    30,    64,    70,    65,    17,    56,    -1,    18,    33,
      16,    34,    39,    34,    17,    67,    -1,    68,    16,    69,
      -1,    33,    -1,    33,    41,    69,    42,    -1,    69,    35,
      69,    -1,    69,    36,    69,    -1,    69,    37,    69,    -1,
      69,    23,    69,    -1,    69,    24,    69,    -1,    69,    32,
      69,    -1,    43,    69,    44,    -1,    33,    -1,    33,    41,
      69,    42,    -1,    71,    -1,     1,    -1,    69,    20,    69,
      -1,    69,    19,    69,    -1,    69,    21,    69,    -1,    69,
      22,    69,    -1,     1,    -1,    34,    -1,    72,    -1,    27,
      -1,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    47,    52,    55,    56,    59,    60,    61,
      64,    67,    68,    71,    72,    75,    76,    79,    80,    81,
      84,    85,    86,    87,    88,    89,    92,    92,    95,    96,
      96,   100,   111,   114,   115,   114,   120,   123,   126,   127,
     130,   139,   148,   156,   161,   166,   171,   173,   175,   178,
     182,   185,   190,   195,   200,   205,   208,   209,   212,   213
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROG", "PERIOD", "VAR", "INT", "BOOL",
  "ARRAY", "RANGE", "OF", "WRITELN", "THEN", "IF", "BEG", "END", "ASG",
  "DO", "FOR", "EQ", "NEQ", "LT", "LEQ", "AND", "OR", "XOR", "NOT", "TRUE",
  "FALSE", "ELSE", "WHILE", "BOOLEAN", "EXOR", "ID", "ICONST", "'+'",
  "'-'", "'*'", "';'", "','", "':'", "'['", "']'", "'('", "')'", "$accept",
  "program", "$@1", "block", "variables", "vardcls", "vardcl", "tail",
  "type", "stype", "stmtlist", "stmt", "cmpdstmt", "$@2", "ifstmt", "$@3",
  "ifhead", "writestmt", "wstmt", "$@4", "$@5", "fstmt", "astmt", "lvalue",
  "exp", "condexp", "constant", "boolean_constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    43,    45,    42,    59,    44,
      58,    91,    93,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    46,    48,    49,    49,    50,    50,    50,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    58,    57,    59,    60,
      59,    61,    62,    64,    65,    63,    66,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    70,    71,    71,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     2,     3,     2,     2,
       2,     3,     2,     8,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     3,     0,
       6,     2,     4,     0,     0,     6,     8,     3,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     1,
       1,     3,     3,     3,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     5,     0,     0,    26,
       0,     0,     6,     0,     3,     4,     0,     9,     0,     0,
      10,     0,     8,     0,     0,    15,     0,    16,    12,    14,
       7,    19,     0,     0,     0,    33,    38,     0,    18,    25,
      20,     0,    24,    21,    22,    23,     0,    11,     0,     0,
      50,    58,    59,    47,    56,     0,     0,    31,    49,    57,
       0,     0,     0,    27,    26,    26,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    17,    28,    37,     0,    32,
       0,    46,    52,    51,    53,    54,    43,    44,    45,    40,
      41,    42,     0,     0,    39,    29,     0,    48,     0,    26,
      26,     0,     0,    35,    30,     0,     0,    13,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    12,    13,    20,    28,    29,
      37,    38,    39,    16,    40,   110,    41,    42,    43,    61,
     103,    44,    45,    46,    56,    57,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int8 yypact[] =
{
     -65,    14,    13,   -65,   -24,   -21,    15,     6,    17,   -65,
     -16,   -27,   -14,   -15,   -65,   -65,    10,   -65,    -8,     2,
     -65,   -11,   -65,    68,   -27,   -65,     0,   -65,   -65,   -65,
     -65,   -65,     5,     1,    -3,   -65,    11,   -12,   -65,   -65,
     -65,    31,   -65,   -65,   -65,   -65,    34,   -65,    20,     4,
      -6,   -65,   -65,    30,   -65,     4,   122,   -65,   -65,   -65,
      35,     1,     4,   -65,    59,    59,     4,    46,   -65,    67,
       4,    73,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    22,   -65,    83,   -65,    29,   115,    39,   -65,
      98,   -65,   115,   115,   115,   115,   -65,   -19,   -19,   -19,
     -19,   -65,    36,    57,   -65,   -65,    38,   -65,    42,    59,
      59,    74,    61,   -65,   -65,     9,    50,   -65,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   -65,   -65,   -65,    75,    64,   -65,   -30,
     -65,   -64,    84,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -22,   -65,   -13,    51,   -65,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int8 yytable[] =
{
      85,    86,    50,    63,    76,    68,   -55,    10,    25,     5,
      26,   -55,    18,    19,     3,    25,     4,     6,    81,    11,
       7,    14,    17,    22,    23,    24,    64,    30,    51,    52,
      60,    51,    52,    27,    53,    54,    69,    53,    54,    11,
      27,    48,    71,    65,    55,   113,   114,    55,    49,    84,
      66,    82,    62,    87,    67,    88,   102,    90,   105,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    31,
      32,    70,    33,   106,   109,   108,   112,    34,   116,    32,
     111,    33,   -26,    36,   115,   117,    34,    21,    47,    35,
      76,    77,    36,    15,   118,     0,    76,    77,    35,    78,
       0,    36,    79,    80,    81,    78,    76,    77,    79,    80,
      81,    89,    83,     0,     0,    78,     0,    91,    79,    80,
      81,    76,    77,     0,     0,   104,     0,     0,     0,     0,
      78,     0,     0,    79,    80,    81,     0,     0,    76,    77,
     107,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,     0,    78,     0,     0,    79,    80,    81
};

static const yytype_int8 yycheck[] =
{
      64,    65,     1,    15,    23,     1,    12,     1,     6,    33,
       8,    17,    39,    40,     0,     6,     3,    38,    37,    33,
       5,     4,    38,    38,    14,    33,    38,    38,    27,    28,
      33,    27,    28,    31,    33,    34,    49,    33,    34,    33,
      31,    41,    55,    12,    43,   109,   110,    43,    43,    62,
      16,    16,    41,    66,    34,     9,    34,    70,    29,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     1,
      11,    41,    13,    34,    17,    39,    34,    18,    17,    11,
      42,    13,    14,    33,    10,   115,    18,    12,    24,    30,
      23,    24,    33,     9,   116,    -1,    23,    24,    30,    32,
      -1,    33,    35,    36,    37,    32,    23,    24,    35,    36,
      37,    44,    61,    -1,    -1,    32,    -1,    44,    35,    36,
      37,    23,    24,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    -1,    -1,    23,    24,
      42,    19,    20,    21,    22,    23,    24,    32,    -1,    -1,
      35,    36,    37,    -1,    32,    -1,    -1,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,     3,    33,    38,     5,    48,    49,
       1,    33,    50,    51,     4,    57,    58,    38,    39,    40,
      52,    51,    38,    14,    33,     6,     8,    31,    53,    54,
      38,     1,    11,    13,    18,    30,    33,    55,    56,    57,
      59,    61,    62,    63,    66,    67,    68,    52,    41,    43,
       1,    27,    28,    33,    34,    43,    69,    70,    71,    72,
      33,    64,    41,    15,    38,    12,    16,    34,     1,    69,
      41,    69,    19,    20,    21,    22,    23,    24,    32,    35,
      36,    37,    16,    70,    69,    56,    56,    69,     9,    44,
      69,    44,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    34,    65,    42,    29,    34,    42,    39,    17,
      60,    42,    34,    56,    56,    10,    17,    54,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 47 "parse.y"
    {emitComment("Assign STATIC_AREA_ADDRESS to register \"r0\"");
           emit(NOLABEL, LOADI, STATIC_AREA_ADDRESS, 0, EMPTY); ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 49 "parse.y"
    { ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 52 "parse.y"
    { ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 56 "parse.y"
    { ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 59 "parse.y"
    { ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 60 "parse.y"
    { ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 61 "parse.y"
    { yyerror("***Error: illegal variable declaration\n");;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 64 "parse.y"
    { insert((yyvsp[(1) - (2)].token).str, (yyvsp[(2) - (2)].token).type, NextOffset());  ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 67 "parse.y"
    { insert((yyvsp[(2) - (3)].token).str, (yyvsp[(3) - (3)].token).type, NextOffset()); (yyval.token).type = (yyvsp[(3) - (3)].token).type; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 68 "parse.y"
    { (yyval.token).type = (yyvsp[(2) - (2)].token).type; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 71 "parse.y"
    { (yyval.token).type = mystrcat("arr-", (yyvsp[(8) - (8)].token).type); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 72 "parse.y"
    { (yyval.token).type = (yyvsp[(1) - (1)].token).type; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 75 "parse.y"
    { (yyval.token).type = "int";  ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 76 "parse.y"
    { (yyval.token).type = "bool"; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 79 "parse.y"
    { ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 80 "parse.y"
    { ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 81 "parse.y"
    { yyerror("***Error: illegal statement \n");;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 84 "parse.y"
    { ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 85 "parse.y"
    { ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 86 "parse.y"
    { ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 87 "parse.y"
    { ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 88 "parse.y"
    { ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 89 "parse.y"
    { ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 92 "parse.y"
    { load_regs(); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 92 "parse.y"
    { clear_regs(); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 95 "parse.y"
    { emit((yyvsp[(1) - (3)].label).falseLabel, NOP, 0, 0, 0); emitComment("This is the \"false\" branch"); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 96 "parse.y"
    { int endLabel = NextLabel(); emit(BR, endLabel, 0, 0, 0); emit((yyvsp[(1) - (4)].label).falseLabel, NOP, 0, 0, 0); (yyvsp[(1) - (4)].label).endLabel = endLabel; ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 97 "parse.y"
    { emit(BR, (yyvsp[(1) - (6)].label).endLabel, 0, 0, 0); emit((yyvsp[(1) - (6)].label).endLabel, NOP, 0, 0, 0); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 100 "parse.y"
    { 
		   int trueLabel = NextLabel();
		   int falseLabel = NextLabel();
		   emit(NOLABEL, CBR, (yyvsp[(2) - (2)].targetReg).targetRegister, trueLabel, falseLabel);
		   emitComment("This is the \"true\" branch"); 
		   emit(trueLabel, NOP, 0, 0, 0);
		   (yyval.label).falseLabel = falseLabel;
		   (yyval.label).trueLabel = trueLabel;
		 ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 111 "parse.y"
    { emit(NOLABEL, STORE, (yyvsp[(3) - (4)].targetReg).targetRegister, 0, 0); emit(NOLABEL, OUTPUT, 1024, 0, 0); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 114 "parse.y"
    { emitComment("Control code for \"WHILE DO\"");;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 115 "parse.y"
    { emitComment("Body of \"WHILE\" construct starts here");;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 116 "parse.y"
    { ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 120 "parse.y"
    { ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 123 "parse.y"
    { set_reg((yyvsp[(1) - (3)].token).str, (yyvsp[(3) - (3)].targetReg).targetRegister); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 126 "parse.y"
    { (yyval.token).str = (yyvsp[(1) - (1)].token).str; ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 127 "parse.y"
    { ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 130 "parse.y"
    { int newReg = NextRegister();
                                  (yyval.targetReg).targetRegister = newReg;
                                  emit(NOLABEL, 
                                       ADD, 
                                       (yyvsp[(1) - (3)].targetReg).targetRegister, 
                                       (yyvsp[(3) - (3)].targetReg).targetRegister, 
                                       newReg);
                                ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 139 "parse.y"
    { int newReg = NextRegister(); 
                                  (yyval.targetReg).targetRegister = newReg;
                                  emit(NOLABEL, 
                                       SUB, 
                                       (yyvsp[(1) - (3)].targetReg).targetRegister, 
                                       (yyvsp[(3) - (3)].targetReg).targetRegister, 
                                       newReg);
                                ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 148 "parse.y"
    { int newReg = NextRegister(); 
                                  (yyval.targetReg).targetRegister = newReg;
                                  emit(NOLABEL, 
                                       MULT, 
                                       (yyvsp[(1) - (3)].targetReg).targetRegister, 
                                       (yyvsp[(3) - (3)].targetReg).targetRegister, 
                                       newReg);
                                ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 156 "parse.y"
    {
		int newReg = NextRegister();
		(yyval.targetReg).targetRegister = newReg;
		emit(NOLABEL, L_AND, (yyvsp[(1) - (3)].targetReg).targetRegister, (yyvsp[(3) - (3)].targetReg).targetRegister, newReg);
	;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 161 "parse.y"
    { 	
		int newReg = NextRegister();
		(yyval.targetReg).targetRegister = newReg;
		emit(NOLABEL, L_OR, (yyvsp[(1) - (3)].targetReg).targetRegister, (yyvsp[(3) - (3)].targetReg).targetRegister, newReg);
	;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 166 "parse.y"
    {
		int newReg = NextRegister();
		(yyval.targetReg).targetRegister = newReg;
		emit(NOLABEL, L_XOR, (yyvsp[(1) - (3)].targetReg).targetRegister, (yyvsp[(3) - (3)].targetReg).targetRegister, newReg);
	;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 171 "parse.y"
    { (yyval.targetReg).targetRegister = (yyvsp[(2) - (3)].targetReg).targetRegister; ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 173 "parse.y"
    { (yyval.targetReg).targetRegister = get_reg((yyvsp[(1) - (1)].token).str); ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 175 "parse.y"
    { ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 178 "parse.y"
    { int newReg = NextRegister();
	                          (yyval.targetReg).targetRegister = newReg;
	                          emit(NOLABEL, LOADI, (yyvsp[(1) - (1)].token).num, newReg, EMPTY); ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 182 "parse.y"
    { yyerror("***Error: illegal expression\n");;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 185 "parse.y"
    {  
		int newReg = NextRegister();
		(yyval.targetReg).targetRegister = newReg;
		emit(NOLABEL, CMPNE, (yyvsp[(1) - (3)].targetReg).targetRegister, (yyvsp[(3) - (3)].targetReg).targetRegister, newReg);
	;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 190 "parse.y"
    {
		int newReg = NextRegister();
		(yyval.targetReg).targetRegister = newReg;
		emit(NOLABEL, CMPEQ, (yyvsp[(1) - (3)].targetReg).targetRegister, (yyvsp[(3) - (3)].targetReg).targetRegister, newReg);
	;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 195 "parse.y"
    {
		int newReg = NextRegister();
		(yyval.targetReg).targetRegister = newReg;
		emit(NOLABEL, CMPLT, (yyvsp[(1) - (3)].targetReg).targetRegister, (yyvsp[(3) - (3)].targetReg).targetRegister, newReg);
	;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 200 "parse.y"
    {
		int newReg = NextRegister();
		(yyval.targetReg).targetRegister = newReg;
		emit(NOLABEL, CMPLE, (yyvsp[(1) - (3)].targetReg).targetRegister, (yyvsp[(3) - (3)].targetReg).targetRegister, newReg);
	;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 205 "parse.y"
    { yyerror("***Error: illegal conditional expression\n");;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 208 "parse.y"
    { (yyval.token).num = (yyvsp[(1) - (1)].token).num; (yyval.token).type = strdup("int");  ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 209 "parse.y"
    { (yyval.token).num = (yyvsp[(1) - (1)].token).num; (yyval.token).type = strdup("bool");  ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 212 "parse.y"
    { (yyval.token).num = 1; ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 213 "parse.y"
    { (yyval.token).num = 0; ;}
    break;



/* Line 1464 of yacc.c  */
#line 1941 "parse.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 216 "parse.y"


void yyerror(char* s) {
        fprintf(stderr,"%s\n",s);
	fflush(stderr);
        }

int
main() {
  printf("\n          CS415 Spring 2011\n        Vectorizing Compiler\n");
  printf("    Version 1.0, Wednesday, April 20 \n\n");
  
  outfile = fopen("iloc.out", "w");
  if (outfile == NULL) { 
    printf("ERROR: cannot open output file \"iloc.out\".\n");
    return -1;
  }

  CommentBuffer = (char *) malloc(500);  

  printf("1\t");
  yyparse();
  printf("\n");
  
  /*** START: THIS IS BOGUS AND NEEDS TO BE REMOVED ***/    
  /*

  emitComment("LOTS MORE BOGUS CODE");
  emit(1, NOP, EMPTY, EMPTY, EMPTY);
  emit(NOLABEL, VECTON, EMPTY, EMPTY, EMPTY);
  emit(NOLABEL, LOADI, 12, 1, EMPTY);
  emit(NOLABEL, LOADI, 1024, 2, EMPTY);
  emit(NOLABEL, STORE, 1, 2, EMPTY);
  emit(NOLABEL, OUTPUT, 1024, EMPTY, EMPTY);
  emit(NOLABEL, LOADI, -5, 3, EMPTY);
  emit(NOLABEL, CMPLT, 1, 3, 4);
  emit(NOLABEL, VECTOFF, EMPTY, EMPTY, EMPTY);
  emit(NOLABEL, STORE, 4, 2, EMPTY);
  emit(NOLABEL, OUTPUT, 1024, EMPTY, EMPTY);
  emit(NOLABEL, CBR, 4, 1, 2);
  emit(2, NOP, EMPTY, EMPTY, EMPTY);

*/

  /*** END: THIS IS BOGUS AND NEEDS TO BE REMOVED ***/    

  fclose(outfile);
  
  return 1;
}





