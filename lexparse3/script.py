from lexparse import call; call(r"""

~ TEST ~

var realVal1 : real;
var realVal2 is 3.14159;
type Data_child is record
	var arr : array [20] integer;
	var size : integer;
end;
type Data is Data_child;

type bubble_sort_arr is array [] integer;

routine bubble_sort (arr : bubble_sort_arr, size : integer) : boolean is

	var i is 0;
	var buf : integer;
	var swap_cnt is 0;
	var retVal is false;
	if (size = 0) then 
		retVal := false;
	else
		while (i < size) loop
			if ( ((i + 1) /= size) and (arr[i] > arr[i + 1]) ) then
				buf := arr[i];
				arr[i] := arr[i + 1];
				arr[i + 1] := buf;
				swap_cnt := 1;				
			end;
			i := i + 1;
			if ( (i = size) and (swap_cnt = 1) ) then
				swap_cnt := 0;
				i := 0;
			end;
			retVal := true;
		end;
	end;
	bubble_sort_arr := retVal;
end;

routine func_without_params : boolean is
	func_without_params := true;
end;

routine func_without_body_and_type;

routine main (arr : bubble_sort_arr) : integer is
	var size is 20;
	var data1 : Data;
	var data2 : Data;
	
	data1.size := 20;
	data2.size := 20;
	
	var i : Integer;
	
	for i in 1..20 loop
		data1.arr[i] := i % 5;
	end;
	
	for i in reverse 1..20 loop
		data2.arr[i] := i % 7;
	end;
	
	bubble_sort(data1.arr, data1.size);
	bubble_sort(data2.arr, data2.size);

	if (func_without_params) then
		func_without_body_and_type();
	end;
	
	main := 0;
end;

~ GRAMMAR ~

#printf(" <%RULE% : %LENGTH%> ");

Program : 
		| ProgramFull
ProgramFull : SimpleDeclaration TERMINAL
			| SimpleDeclaration TERMINAL ProgramFull
			| RoutineDeclaration TERMINAL
			| RoutineDeclaration TERMINAL ProgramFull
SimpleDeclaration : VariableDeclaration
				  | TypeDeclaration
VariableDeclaration : VAR_TOKEN IDENT COLON Type
                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression
                    | VAR_TOKEN IDENT IS_TOKEN Expression
VariableDeclarations : VariableDeclaration TERMINAL
					 | VariableDeclaration TERMINAL VariableDeclarations 
TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type
Type : PrimitiveType
	 | ArrayType
	 | RecordType
	 | IDENT 
PrimitiveType : INT_TOKEN
			  | REAL_TOKEN
			  | BOOL_TOKEN 
RecordType : REC_TOKEN END_TOKEN
		   | REC_TOKEN VariableDeclarations END_TOKEN
ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type
          | ARRAY_TOKEN LBRACKET RBRACKET Type
          | ARRAY_TOKEN Type 
Expression : Relation
		   | Relation Logical Relation 
Logical : AND_TOKEN
		| OR_TOKEN
		| XOR_TOKEN 
Relation : Simple
		 | Simple Correlation Simple 
Correlation : LESS
			| LESS_OR_EQ
			| MORE
			| MORE_OR_EQ
			| EQ
			| NOT_EQ 
Simple : Factor 
	   | Factor FactorSign Factor 
FactorSign : MULTIPLY 
		   | DIVIDE
		   | MOD 
Factor : Summand
	   | Summand Sign Summand 
Sign : PLUS
	 | MINUS 
Summand : Primary
		| LPAREN Expression RPAREN 
Primary : INT_LITERAL
		| REAL_LITERAL
		| TRUE_TOKEN
		| FALSE_TOKEN
		| ModifiablePrimary
		| RoutineCall
ModifiablePrimary : IDENT
                  | IDENT ModifiableSecondary
ModifiableSecondary : POINT IDENT
					| LBRACKET Expression RBRACKET
					| POINT IDENT ModifiableSecondary
					| LBRACKET Expression RBRACKET ModifiableSecondary

RoutineDeclaration : ROUTINE_TOKEN IDENT
                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN
                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN
                   | ROUTINE_TOKEN IDENT COLON Type
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN 
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN  
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN 
                   
ParameterDeclaration : IDENT COLON IDENT
					 | IDENT COLON PrimitiveType
Parameters : ParameterDeclaration
		   | ParameterDeclaration COMMA Parameters

Body : SimpleDeclaration TERMINAL
     | Statement TERMINAL
     | SimpleDeclaration TERMINAL Body
     | Statement TERMINAL Body 
Statement : Assignment
		  | RoutineCall
		  | WhileLoop
		  | ForLoop
		  | IfStatement 
Assignment : ModifiablePrimary ASSIGN Expression 
RoutineCall : IDENT LPAREN RPAREN 
            | IDENT LPAREN Expressions RPAREN 
Expressions : Expression
			| Expression COMMA Expressions
WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN
		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN
ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN 
		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN
Range : IN_TOKEN Expression FALLEN_COLON Expression
      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression 
IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN
			| IF_TOKEN Expression THEN_TOKEN END_TOKEN
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN

~ TOKENS ~

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

~ RULES ~

\n#position=1; ++line;
[ \t]#position+=yyleng;
\
.#position++;
#printf("%TOKEN%[%s] ",yytext);return %TOKEN%;
Int_Literal#
Real_Literal#
Ident#
#printf("%TOKEN% ");return %TOKEN%;

~ PRELEX ~

int position = 1, line = 1;

~ POSTLEX ~

/**/

~ PRE ~

#include <stdio.h>

~ POST ~

int main(int argc, char **argv){
	yyparse();
}
int yyerror(char *s){
	printf("\n\n-\nError: %s\n-\n", s);
}

~ END ~

""");
