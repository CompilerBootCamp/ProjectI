%{
#include "parser.tab.h"
extern void printf_into(char* s);
%}
Assign				":="
Less_Or_Eq			"<="
More_Or_Eq			">="
Not_Eq				"/="
Fallen_Colon		".."
Terminal			";"
Colon				":"
Comma				","
Lbracket			"["
Rbracket			"]"
Lparen				"("
Rparen				")"
Multiply			"*"
Divide				"/"
Mod					"%"
Plus				"+"
Minus				"-"
Point				"."
Less				"<"
More				">"
Eq					"="
Var_Token			"var"
Is_Token			"is"
Type_Token			"type"
Routine_Token		"routine"
End_Token			"end"
Int_Token			"integer"
Real_Token			"real"
Bool_Token			"boolean"
Rec_Token			"record"
Array_Token			"array"
While_Token			"while"
Loop_Token			"loop"
For_Token			"for"
In_Token			"in"
Reverse_Token		"reverse"
If_Token			"if"
Then_Token			"then"
Else_Token			"else"
And_Token			"and"
Or_Token			"or"
Xor_Token			"xor"
True_Token			"true"
False_Token			"false"
letter				[A-Za-z_]
digit				[0-9]
Ident				{letter}({letter}|{digit})*
Int_Literal 		{digit}+
Real_Literal 		{digit}*\.?{digit}+
%%
\n	{}
[ \t]	{}
{Assign}	{printf_into("<ASSIGN,-1,>+");return ASSIGN;}
{Less_Or_Eq}	{printf_into("<LESS_OR_EQ,-1,>+");return LESS_OR_EQ;}
{More_Or_Eq}	{printf_into("<MORE_OR_EQ,-1,>+");return MORE_OR_EQ;}
{Not_Eq}	{printf_into("<NOT_EQ,-1,>+");return NOT_EQ;}
{Fallen_Colon}	{printf_into("<FALLEN_COLON,-1,>+");return FALLEN_COLON;}
{Terminal}	{printf_into("<TERMINAL,-1,>+");return TERMINAL;}
{Colon}	{printf_into("<COLON,-1,>+");return COLON;}
{Comma}	{printf_into("<COMMA,-1,>+");return COMMA;}
{Lbracket}	{printf_into("<LBRACKET,-1,>+");return LBRACKET;}
{Rbracket}	{printf_into("<RBRACKET,-1,>+");return RBRACKET;}
{Lparen}	{printf_into("<LPAREN,-1,>+");return LPAREN;}
{Rparen}	{printf_into("<RPAREN,-1,>+");return RPAREN;}
{Multiply}	{printf_into("<MULTIPLY,-1,>+");return MULTIPLY;}
{Divide}	{printf_into("<DIVIDE,-1,>+");return DIVIDE;}
{Mod}	{printf_into("<MOD,-1,>+");return MOD;}
{Plus}	{printf_into("<PLUS,-1,>+");return PLUS;}
{Minus}	{printf_into("<MINUS,-1,>+");return MINUS;}
{Point}	{printf_into("<POINT,-1,>+");return POINT;}
{Less}	{printf_into("<LESS,-1,>+");return LESS;}
{More}	{printf_into("<MORE,-1,>+");return MORE;}
{Eq}	{printf_into("<EQ,-1,>+");return EQ;}
{Var_Token}	{printf_into("<VAR_TOKEN,-1,>+");return VAR_TOKEN;}
{Is_Token}	{printf_into("<IS_TOKEN,-1,>+");return IS_TOKEN;}
{Type_Token}	{printf_into("<TYPE_TOKEN,-1,>+");return TYPE_TOKEN;}
{Routine_Token}	{printf_into("<ROUTINE_TOKEN,-1,>+");return ROUTINE_TOKEN;}
{End_Token}	{printf_into("<END_TOKEN,-1,>+");return END_TOKEN;}
{Int_Token}	{printf_into("<INT_TOKEN,-1,>+");return INT_TOKEN;}
{Real_Token}	{printf_into("<REAL_TOKEN,-1,>+");return REAL_TOKEN;}
{Bool_Token}	{printf_into("<BOOL_TOKEN,-1,>+");return BOOL_TOKEN;}
{Rec_Token}	{printf_into("<REC_TOKEN,-1,>+");return REC_TOKEN;}
{Array_Token}	{printf_into("<ARRAY_TOKEN,-1,>+");return ARRAY_TOKEN;}
{While_Token}	{printf_into("<WHILE_TOKEN,-1,>+");return WHILE_TOKEN;}
{Loop_Token}	{printf_into("<LOOP_TOKEN,-1,>+");return LOOP_TOKEN;}
{For_Token}	{printf_into("<FOR_TOKEN,-1,>+");return FOR_TOKEN;}
{In_Token}	{printf_into("<IN_TOKEN,-1,>+");return IN_TOKEN;}
{Reverse_Token}	{printf_into("<REVERSE_TOKEN,-1,>+");return REVERSE_TOKEN;}
{If_Token}	{printf_into("<IF_TOKEN,-1,>+");return IF_TOKEN;}
{Then_Token}	{printf_into("<THEN_TOKEN,-1,>+");return THEN_TOKEN;}
{Else_Token}	{printf_into("<ELSE_TOKEN,-1,>+");return ELSE_TOKEN;}
{And_Token}	{printf_into("<AND_TOKEN,-1,>+");return AND_TOKEN;}
{Or_Token}	{printf_into("<OR_TOKEN,-1,>+");return OR_TOKEN;}
{Xor_Token}	{printf_into("<XOR_TOKEN,-1,>+");return XOR_TOKEN;}
{True_Token}	{printf_into("<TRUE_TOKEN,-1,>+");return TRUE_TOKEN;}
{False_Token}	{printf_into("<FALSE_TOKEN,-1,>+");return FALSE_TOKEN;}
{Ident}	{printf_into("<IDENT,-1,>[");printf_into(yytext);printf_into("]+");return IDENT;}
{Int_Literal}	{printf_into("<INT_LITERAL,-1,>[");printf_into(yytext);printf_into("]+");return INT_LITERAL;}
{Real_Literal}	{printf_into("<REAL_LITERAL,-1,>[");printf_into(yytext);printf_into("]+");return REAL_LITERAL;}
.	{}
%%
int yywrap(){return 1;}
