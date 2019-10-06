%{
	#include "parser.tab.h"
	int position = 1, line = 1;
%}

Assign				(:=)
Less_Or_Eq			(<=)
More_Or_Eq			(>=)
Not_Eq				"/="
Fallen_Colon		".."

Terminal			";"
Colon				":"
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
Real_Literal 		{digit}*\.?{digit}+
Int_Literal 		{digit}+

%%

\n	{position=1; ++line;}
[ \t]	{position+=yyleng;}

{Assign}	{printf("ASSIGN\n");position+=yyleng;return ASSIGN;}
{Less_Or_Eq}	{printf("LESS_OR_EQ\n");position+=yyleng;return LESS_OR_EQ;}
{More_Or_Eq}	{printf("MORE_OR_EQ\n");position+=yyleng;return MORE_OR_EQ;}
{Not_Eq}	{printf("NOT_EQ\n");position+=yyleng;return NOT_EQ;}
{Fallen_Colon}	{printf("FALLEN_COLON\n");position+=yyleng;return FALLEN_COLON;}
{Terminal}	{printf("TERMINAL\n");position+=yyleng;return TERMINAL;}
{Colon}	{printf("COLON\n");position+=yyleng;return COLON;}
{Lbracket}	{printf("LBRACKET\n");position+=yyleng;return LBRACKET;}
{Rbracket}	{printf("RBRACKET\n");position+=yyleng;return RBRACKET;}
{Lparen}	{printf("LPAREN\n");position+=yyleng;return LPAREN;}
{Rparen}	{printf("RPAREN\n");position+=yyleng;return RPAREN;}
{Multiply}	{printf("MULTIPLY\n");position+=yyleng;return MULTIPLY;}
{Divide}	{printf("DIVIDE\n");position+=yyleng;return DIVIDE;}
{Mod}	{printf("MOD\n");position+=yyleng;return MOD;}
{Plus}	{printf("PLUS\n");position+=yyleng;return PLUS;}
{Minus}	{printf("MINUS\n");position+=yyleng;return MINUS;}
{Point}	{printf("POINT\n");position+=yyleng;return POINT;}
{Less}	{printf("LESS\n");position+=yyleng;return LESS;}
{More}	{printf("MORE\n");position+=yyleng;return MORE;}
{Eq}	{printf("EQ\n");position+=yyleng;return EQ;}
{Var_Token}	{printf("VAR_TOKEN\n");position+=yyleng;return VAR_TOKEN;}
{Is_Token}	{printf("IS_TOKEN\n");position+=yyleng;return IS_TOKEN;}
{Type_Token}	{printf("TYPE_TOKEN\n");position+=yyleng;return TYPE_TOKEN;}
{Routine_Token}	{printf("ROUTINE_TOKEN\n");position+=yyleng;return ROUTINE_TOKEN;}
{End_Token}	{printf("END_TOKEN\n");position+=yyleng;return END_TOKEN;}
{Int_Token}	{printf("INT_TOKEN\n");position+=yyleng;return INT_TOKEN;}
{Real_Token}	{printf("REAL_TOKEN\n");position+=yyleng;return REAL_TOKEN;}
{Bool_Token}	{printf("BOOL_TOKEN\n");position+=yyleng;return BOOL_TOKEN;}
{Rec_Token}	{printf("REC_TOKEN\n");position+=yyleng;return REC_TOKEN;}
{Array_Token}	{printf("ARRAY_TOKEN\n");position+=yyleng;return ARRAY_TOKEN;}
{While_Token}	{printf("WHILE_TOKEN\n");position+=yyleng;return WHILE_TOKEN;}
{Loop_Token}	{printf("LOOP_TOKEN\n");position+=yyleng;return LOOP_TOKEN;}
{For_Token}	{printf("FOR_TOKEN\n");position+=yyleng;return FOR_TOKEN;}
{In_Token}	{printf("IN_TOKEN\n");position+=yyleng;return IN_TOKEN;}
{Reverse_Token}	{printf("REVERSE_TOKEN\n");position+=yyleng;return REVERSE_TOKEN;}
{If_Token}	{printf("IF_TOKEN\n");position+=yyleng;return IF_TOKEN;}
{Then_Token}	{printf("THEN_TOKEN\n");position+=yyleng;return THEN_TOKEN;}
{Else_Token}	{printf("ELSE_TOKEN\n");position+=yyleng;return ELSE_TOKEN;}
{And_Token}	{printf("AND_TOKEN\n");position+=yyleng;return AND_TOKEN;}
{Or_Token}	{printf("OR_TOKEN\n");position+=yyleng;return OR_TOKEN;}
{Xor_Token}	{printf("XOR_TOKEN\n");position+=yyleng;return XOR_TOKEN;}
{True_Token}	{printf("TRUE_TOKEN\n");position+=yyleng;return TRUE_TOKEN;}
{False_Token}	{printf("FALSE_TOKEN\n");position+=yyleng;return FALSE_TOKEN;}
{Ident}	{printf("IDENT\n");position+=yyleng;return IDENT;}
{Int_Literal}	{printf("INT_LITERAL\n");position+=yyleng;return INT_LITERAL;}
{Real_Literal}	{printf("REAL_LITERAL\n");position+=yyleng;return REAL_LITERAL;}

.	{position++;}
%%
int yywrap(){return 1;}
