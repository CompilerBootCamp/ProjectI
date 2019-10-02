%{
#include <stdio.h>

int position = 1, line = 1;
%}
digit        [0-9]
intconst     [+\-]?{digit}+
letter       [A-Za-z_]
identifier   {letter}({letter}|{digit})*
terminal     [;|\n]
delimeter    [\{\}\(\)\[\]]
assignment   [a]
key1         ("var"|"is"|"type"|"routine"|"end"|"integer"|"real"|"boolean"|"record"|"array"|"while")
key2         ("loop"|"for"|"in"|"reverse"|"foreach"|"from"|"if"|"then"|"else"|"and"|"or"|"xor"|"true"|"false")
key          {key1}|{key2}
%%
.             {++position;}
{key}         {printf("Keyword %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{intconst}    {printf("Integer constant %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{identifier}  {printf("Identifier %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{delimeter}   {printf("Delimeter %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{assignment}  {printf("Assigment %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{terminal}    {printf("Terminal in line %d, position %d\n", line, position); if(*yytext == ';') position+=yyleng; else {position=1; ++line;}}
%%
