%{
#include <stdio.h>

int position = 1, line = 1;
%}
assignment   (:=)
operator	 ["."|">="|"<="|"<"|":"|"="|">"|"/"|"*"|"%"|"+"|"-"|","]
delimeter    [\{\}\(\)\[\]]
digit        [0-9]
intconst     [+\-]?{digit}+
letter       [A-Za-z_]
identifier   {letter}({letter}|{digit})*
terminal     [;|\n]
key1         ("var"|"is"|"type"|"routine"|"end"|"integer"|"real"|"boolean"|"record"|"array"|"while")
key2         ("loop"|"for"|"in"|"reverse"|"foreach"|"from"|"if"|"then"|"else"|"and"|"or"|"xor"|"true"|"false")
key          {key1}|{key2}
%%
{delimeter}  {printf("Delimeter %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{assignment} {printf("Assigment %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{operator}   {printf("Operator %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
.            {++position;}
{key}        {printf("Keyword %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{intconst}   {printf("Integer constant %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{identifier} {printf("Identifier %s in line %d, position %d\n", yytext, line, position); position+=yyleng;}
{terminal}   {printf("Terminal in line %d, position %d\n", line, position); if(*yytext == ';') position+=yyleng; else {position=1; ++line;}}
%%
int yywrap(){return 1;}
