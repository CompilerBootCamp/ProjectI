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
{Assign}	{printf("<ASSIGN,-1,>+");return ASSIGN;}
{Less_Or_Eq}	{printf("<LESS_OR_EQ,-1,>+");return LESS_OR_EQ;}
{More_Or_Eq}	{printf("<MORE_OR_EQ,-1,>+");return MORE_OR_EQ;}
{Not_Eq}	{printf("<NOT_EQ,-1,>+");return NOT_EQ;}
{Fallen_Colon}	{printf("<FALLEN_COLON,-1,>+");return FALLEN_COLON;}
{Terminal}	{printf("<TERMINAL,-1,>+");return TERMINAL;}
{Colon}	{printf("<COLON,-1,>+");return COLON;}
{Comma}	{printf("<COMMA,-1,>+");return COMMA;}
{Lbracket}	{printf("<LBRACKET,-1,>+");return LBRACKET;}
{Rbracket}	{printf("<RBRACKET,-1,>+");return RBRACKET;}
{Lparen}	{printf("<LPAREN,-1,>+");return LPAREN;}
{Rparen}	{printf("<RPAREN,-1,>+");return RPAREN;}
{Multiply}	{printf("<MULTIPLY,-1,>+");return MULTIPLY;}
{Divide}	{printf("<DIVIDE,-1,>+");return DIVIDE;}
{Mod}	{printf("<MOD,-1,>+");return MOD;}
{Plus}	{printf("<PLUS,-1,>+");return PLUS;}
{Minus}	{printf("<MINUS,-1,>+");return MINUS;}
{Point}	{printf("<POINT,-1,>+");return POINT;}
{Less}	{printf("<LESS,-1,>+");return LESS;}
{More}	{printf("<MORE,-1,>+");return MORE;}
{Eq}	{printf("<EQ,-1,>+");return EQ;}
{Var_Token}	{printf("<VAR_TOKEN,-1,>+");return VAR_TOKEN;}
{Is_Token}	{printf("<IS_TOKEN,-1,>+");return IS_TOKEN;}
{Type_Token}	{printf("<TYPE_TOKEN,-1,>+");return TYPE_TOKEN;}
{Routine_Token}	{printf("<ROUTINE_TOKEN,-1,>+");return ROUTINE_TOKEN;}
{End_Token}	{printf("<END_TOKEN,-1,>+");return END_TOKEN;}
{Int_Token}	{printf("<INT_TOKEN,-1,>+");return INT_TOKEN;}
{Real_Token}	{printf("<REAL_TOKEN,-1,>+");return REAL_TOKEN;}
{Bool_Token}	{printf("<BOOL_TOKEN,-1,>+");return BOOL_TOKEN;}
{Rec_Token}	{printf("<REC_TOKEN,-1,>+");return REC_TOKEN;}
{Array_Token}	{printf("<ARRAY_TOKEN,-1,>+");return ARRAY_TOKEN;}
{While_Token}	{printf("<WHILE_TOKEN,-1,>+");return WHILE_TOKEN;}
{Loop_Token}	{printf("<LOOP_TOKEN,-1,>+");return LOOP_TOKEN;}
{For_Token}	{printf("<FOR_TOKEN,-1,>+");return FOR_TOKEN;}
{In_Token}	{printf("<IN_TOKEN,-1,>+");return IN_TOKEN;}
{Reverse_Token}	{printf("<REVERSE_TOKEN,-1,>+");return REVERSE_TOKEN;}
{If_Token}	{printf("<IF_TOKEN,-1,>+");return IF_TOKEN;}
{Then_Token}	{printf("<THEN_TOKEN,-1,>+");return THEN_TOKEN;}
{Else_Token}	{printf("<ELSE_TOKEN,-1,>+");return ELSE_TOKEN;}
{And_Token}	{printf("<AND_TOKEN,-1,>+");return AND_TOKEN;}
{Or_Token}	{printf("<OR_TOKEN,-1,>+");return OR_TOKEN;}
{Xor_Token}	{printf("<XOR_TOKEN,-1,>+");return XOR_TOKEN;}
{True_Token}	{printf("<TRUE_TOKEN,-1,>+");return TRUE_TOKEN;}
{False_Token}	{printf("<FALSE_TOKEN,-1,>+");return FALSE_TOKEN;}
{Ident}	{printf("<IDENT[%s],-1,>+",yytext);return IDENT;}
{Int_Literal}	{printf("<INT_LITERAL[%s],-1,>+",yytext);return INT_LITERAL;}
{Real_Literal}	{printf("<REAL_LITERAL[%s],-1,>+",yytext);return REAL_LITERAL;}
.	{position++;}
%%
int yywrap(){return 1;}
/**/