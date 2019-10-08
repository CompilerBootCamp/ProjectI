%{
#include "parser.tab.h"
int position = 1, line = 1;
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
Int_Literal 		[+\-]?{digit}+
Real_Literal 		[+\-]?{digit}*\.?{digit}+
%%
\n	{position=1; ++line;}
[ \t]	{position+=yyleng;}
{Assign}	{printf("ASSIGN ");return ASSIGN;}
{Less_Or_Eq}	{printf("LESS_OR_EQ ");return LESS_OR_EQ;}
{More_Or_Eq}	{printf("MORE_OR_EQ ");return MORE_OR_EQ;}
{Not_Eq}	{printf("NOT_EQ ");return NOT_EQ;}
{Fallen_Colon}	{printf("FALLEN_COLON ");return FALLEN_COLON;}
{Terminal}	{printf("TERMINAL ");return TERMINAL;}
{Colon}	{printf("COLON ");return COLON;}
{Comma}	{printf("COMMA ");return COMMA;}
{Lbracket}	{printf("LBRACKET ");return LBRACKET;}
{Rbracket}	{printf("RBRACKET ");return RBRACKET;}
{Lparen}	{printf("LPAREN ");return LPAREN;}
{Rparen}	{printf("RPAREN ");return RPAREN;}
{Multiply}	{printf("MULTIPLY ");return MULTIPLY;}
{Divide}	{printf("DIVIDE ");return DIVIDE;}
{Mod}	{printf("MOD ");return MOD;}
{Plus}	{printf("PLUS ");return PLUS;}
{Minus}	{printf("MINUS ");return MINUS;}
{Point}	{printf("POINT ");return POINT;}
{Less}	{printf("LESS ");return LESS;}
{More}	{printf("MORE ");return MORE;}
{Eq}	{printf("EQ ");return EQ;}
{Var_Token}	{printf("VAR_TOKEN ");return VAR_TOKEN;}
{Is_Token}	{printf("IS_TOKEN ");return IS_TOKEN;}
{Type_Token}	{printf("TYPE_TOKEN ");return TYPE_TOKEN;}
{Routine_Token}	{printf("ROUTINE_TOKEN ");return ROUTINE_TOKEN;}
{End_Token}	{printf("END_TOKEN ");return END_TOKEN;}
{Int_Token}	{printf("INT_TOKEN ");return INT_TOKEN;}
{Real_Token}	{printf("REAL_TOKEN ");return REAL_TOKEN;}
{Bool_Token}	{printf("BOOL_TOKEN ");return BOOL_TOKEN;}
{Rec_Token}	{printf("REC_TOKEN ");return REC_TOKEN;}
{Array_Token}	{printf("ARRAY_TOKEN ");return ARRAY_TOKEN;}
{While_Token}	{printf("WHILE_TOKEN ");return WHILE_TOKEN;}
{Loop_Token}	{printf("LOOP_TOKEN ");return LOOP_TOKEN;}
{For_Token}	{printf("FOR_TOKEN ");return FOR_TOKEN;}
{In_Token}	{printf("IN_TOKEN ");return IN_TOKEN;}
{Reverse_Token}	{printf("REVERSE_TOKEN ");return REVERSE_TOKEN;}
{If_Token}	{printf("IF_TOKEN ");return IF_TOKEN;}
{Then_Token}	{printf("THEN_TOKEN ");return THEN_TOKEN;}
{Else_Token}	{printf("ELSE_TOKEN ");return ELSE_TOKEN;}
{And_Token}	{printf("AND_TOKEN ");return AND_TOKEN;}
{Or_Token}	{printf("OR_TOKEN ");return OR_TOKEN;}
{Xor_Token}	{printf("XOR_TOKEN ");return XOR_TOKEN;}
{True_Token}	{printf("TRUE_TOKEN ");return TRUE_TOKEN;}
{False_Token}	{printf("FALSE_TOKEN ");return FALSE_TOKEN;}
{Ident}	{printf("IDENT ");return IDENT;}
{Int_Literal}	{printf("INT_LITERAL ");return INT_LITERAL;}
{Real_Literal}	{printf("REAL_LITERAL ");return REAL_LITERAL;}
.	{position++;}
%%
int yywrap(){return 1;}
/**/