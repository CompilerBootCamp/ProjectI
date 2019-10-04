%{
#include <stdio.h>
#include "lex_def.h"

int position = 1, line = 1;
%}
terminal     ;
assignment   (:=)
operator	([<\>\/]=)|["."|"<"|":"|"="|">"|"/"|"*"|"%"|"+"|"-"|","]
delimeter    [\{\}\(\)\[\]]
digit        [0-9]
intconst     [+\-]?{digit}+
letter       [A-Za-z_]
identifier   {letter}({letter}|{digit})*
key1         ("var"|"is"|"type"|"routine"|"end"|"integer"|"real"|"boolean"|"record"|"array"|"while")
key2         ("loop"|"for"|"in"|"reverse"|"foreach"|"from"|"if"|"then"|"else"|"and"|"or"|"xor"|"true"|"false")
key          {key1}|{key2}
%%
\n           {position=1; ++line;}
{terminal}   {printf("Terminal in line %d, position %d\n", line, position); position+=yyleng;}
{delimeter}  {printf("Delimeter %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{assignment} {printf("Assigment %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{operator}   {printf("Operator %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
.            {++position;}
{key}        {printf("Keyword %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{intconst}   {printf("Integer constant %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{identifier} {printf("Identifier %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
%%
int yywrap(){return 1;}
