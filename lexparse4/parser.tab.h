/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    LESS_OR_EQ = 259,
    MORE_OR_EQ = 260,
    NOT_EQ = 261,
    FALLEN_COLON = 262,
    TERMINAL = 263,
    COLON = 264,
    COMMA = 265,
    LBRACKET = 266,
    RBRACKET = 267,
    LPAREN = 268,
    RPAREN = 269,
    MULTIPLY = 270,
    DIVIDE = 271,
    MOD = 272,
    PLUS = 273,
    MINUS = 274,
    POINT = 275,
    LESS = 276,
    MORE = 277,
    EQ = 278,
    VAR_TOKEN = 279,
    IS_TOKEN = 280,
    TYPE_TOKEN = 281,
    ROUTINE_TOKEN = 282,
    END_TOKEN = 283,
    INT_TOKEN = 284,
    REAL_TOKEN = 285,
    BOOL_TOKEN = 286,
    REC_TOKEN = 287,
    ARRAY_TOKEN = 288,
    WHILE_TOKEN = 289,
    LOOP_TOKEN = 290,
    FOR_TOKEN = 291,
    IN_TOKEN = 292,
    REVERSE_TOKEN = 293,
    IF_TOKEN = 294,
    THEN_TOKEN = 295,
    ELSE_TOKEN = 296,
    AND_TOKEN = 297,
    OR_TOKEN = 298,
    XOR_TOKEN = 299,
    TRUE_TOKEN = 300,
    FALSE_TOKEN = 301,
    IDENT = 302,
    INT_LITERAL = 303,
    REAL_LITERAL = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
