/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     PROG = 258,
     PERIOD = 259,
     VAR = 260,
     ARRAY = 261,
     RANGE = 262,
     OF = 263,
     INT = 264,
     WRITELN = 265,
     THEN = 266,
     ELSE = 267,
     IF = 268,
     BEG = 269,
     END = 270,
     ASG = 271,
     EQ = 272,
     NEQ = 273,
     LT = 274,
     LEQ = 275,
     OR = 276,
     EXOR = 277,
     AND = 278,
     NOT = 279,
     TRUE = 280,
     FALSE = 281,
     WHILE = 282,
     DO = 283,
     FOR = 284,
     BOOLEAN = 285,
     INTEGER = 286,
     ID = 287,
     ICONST = 288
   };
#endif
/* Tokens.  */
#define PROG 258
#define PERIOD 259
#define VAR 260
#define ARRAY 261
#define RANGE 262
#define OF 263
#define INT 264
#define WRITELN 265
#define THEN 266
#define ELSE 267
#define IF 268
#define BEG 269
#define END 270
#define ASG 271
#define EQ 272
#define NEQ 273
#define LT 274
#define LEQ 275
#define OR 276
#define EXOR 277
#define AND 278
#define NOT 279
#define TRUE 280
#define FALSE 281
#define WHILE 282
#define DO 283
#define FOR 284
#define BOOLEAN 285
#define INTEGER 286
#define ID 287
#define ICONST 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "parse.y"
{tokentype token; 

boolean_constant: true
				| false
				;
          }
/* Line 1529 of yacc.c.  */
#line 122 "parse.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

