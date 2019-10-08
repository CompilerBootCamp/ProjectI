%{
#include <stdio.h>
%}
%token ASSIGN LESS_OR_EQ MORE_OR_EQ NOT_EQ FALLEN_COLON TERMINAL COLON COMMA LBRACKET RBRACKET LPAREN RPAREN MULTIPLY DIVIDE MOD PLUS MINUS POINT LESS MORE EQ VAR_TOKEN IS_TOKEN TYPE_TOKEN ROUTINE_TOKEN END_TOKEN INT_TOKEN REAL_TOKEN BOOL_TOKEN REC_TOKEN ARRAY_TOKEN WHILE_TOKEN LOOP_TOKEN FOR_TOKEN IN_TOKEN REVERSE_TOKEN IF_TOKEN THEN_TOKEN ELSE_TOKEN AND_TOKEN OR_TOKEN XOR_TOKEN TRUE_TOKEN FALSE_TOKEN IDENT INT_LITERAL REAL_LITERAL
%start Program
%%
Program : {printf(" <Program : 0> ");}
		| ProgramFull{printf(" <Program : 1> ");}
;
ProgramFull : SimpleDeclaration TERMINAL{printf(" <ProgramFull : 2> ");}
			| SimpleDeclaration TERMINAL ProgramFull{printf(" <ProgramFull : 3> ");}
			| RoutineDeclaration TERMINAL{printf(" <ProgramFull : 2> ");}
			| RoutineDeclaration TERMINAL ProgramFull{printf(" <ProgramFull : 3> ");}
;
SimpleDeclaration : VariableDeclaration{printf(" <SimpleDeclaration : 1> ");}
				  | TypeDeclaration{printf(" <SimpleDeclaration : 1> ");}
;
VariableDeclaration : VAR_TOKEN IDENT COLON Type{printf(" <VariableDeclaration : 4> ");}
                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression{printf(" <VariableDeclaration : 6> ");}
                    | VAR_TOKEN IDENT IS_TOKEN Expression{printf(" <VariableDeclaration : 4> ");}
;
VariableDeclarations : VariableDeclaration TERMINAL{printf(" <VariableDeclarations : 2> ");}
					 | VariableDeclaration TERMINAL VariableDeclarations {printf(" <VariableDeclarations : 3> ");}
;
TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type{printf(" <TypeDeclaration : 4> ");}
;
Type : PrimitiveType{printf(" <Type : 1> ");}
	 | ArrayType{printf(" <Type : 1> ");}
	 | RecordType{printf(" <Type : 1> ");}
	 | IDENT {printf(" <Type : 1> ");}
;
PrimitiveType : INT_TOKEN{printf(" <PrimitiveType : 1> ");}
			  | REAL_TOKEN{printf(" <PrimitiveType : 1> ");}
			  | BOOL_TOKEN {printf(" <PrimitiveType : 1> ");}
;
RecordType : REC_TOKEN END_TOKEN{printf(" <RecordType : 2> ");}
		   | REC_TOKEN VariableDeclarations END_TOKEN{printf(" <RecordType : 3> ");}
;
ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type{printf(" <ArrayType : 5> ");}
          | ARRAY_TOKEN LBRACKET RBRACKET Type{printf(" <ArrayType : 4> ");}
          | ARRAY_TOKEN Type {printf(" <ArrayType : 2> ");}
;
Expression : Relation{printf(" <Expression : 1> ");}
		   | Relation Logical Relation {printf(" <Expression : 3> ");}
;
Logical : AND_TOKEN{printf(" <Logical : 1> ");}
		| OR_TOKEN{printf(" <Logical : 1> ");}
		| XOR_TOKEN {printf(" <Logical : 1> ");}
;
Relation : Simple{printf(" <Relation : 1> ");}
		 | Simple Correlation Simple {printf(" <Relation : 3> ");}
;
Correlation : LESS{printf(" <Correlation : 1> ");}
			| LESS_OR_EQ{printf(" <Correlation : 1> ");}
			| MORE{printf(" <Correlation : 1> ");}
			| MORE_OR_EQ{printf(" <Correlation : 1> ");}
			| EQ{printf(" <Correlation : 1> ");}
			| NOT_EQ {printf(" <Correlation : 1> ");}
;
Simple : Factor {printf(" <Simple : 1> ");}
	   | Factor FactorSign Factor {printf(" <Simple : 3> ");}
;
FactorSign : MULTIPLY {printf(" <FactorSign : 1> ");}
		   | DIVIDE{printf(" <FactorSign : 1> ");}
		   | MOD {printf(" <FactorSign : 1> ");}
;
Factor : Summand{printf(" <Factor : 1> ");}
	   | Summand Sign Summand {printf(" <Factor : 3> ");}
;
Sign : PLUS{printf(" <Sign : 1> ");}
	 | MINUS {printf(" <Sign : 1> ");}
;
Summand : Primary{printf(" <Summand : 1> ");}
		| LPAREN Expression RPAREN {printf(" <Summand : 3> ");}
;
Primary : INT_LITERAL{printf(" <Primary : 1> ");}
		| REAL_LITERAL{printf(" <Primary : 1> ");}
		| TRUE_TOKEN{printf(" <Primary : 1> ");}
		| FALSE_TOKEN{printf(" <Primary : 1> ");}
		| ModifiablePrimary{printf(" <Primary : 1> ");}
		| RoutineCall{printf(" <Primary : 1> ");}
;
ModifiablePrimary : IDENT{printf(" <ModifiablePrimary : 1> ");}
                  | IDENT ModifiableSecondary{printf(" <ModifiablePrimary : 2> ");}
;
ModifiableSecondary : POINT IDENT{printf(" <ModifiableSecondary : 2> ");}
					| LBRACKET Expression RBRACKET{printf(" <ModifiableSecondary : 3> ");}
					| POINT IDENT ModifiableSecondary{printf(" <ModifiableSecondary : 3> ");}
					| LBRACKET Expression RBRACKET ModifiableSecondary{printf(" <ModifiableSecondary : 4> ");}
;
RoutineDeclaration : ROUTINE_TOKEN IDENT{printf(" <RoutineDeclaration : 2> ");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN{printf(" <RoutineDeclaration : 4> ");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN{printf(" <RoutineDeclaration : 5> ");}
                   | ROUTINE_TOKEN IDENT COLON Type{printf(" <RoutineDeclaration : 4> ");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN{printf(" <RoutineDeclaration : 6> ");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN{printf(" <RoutineDeclaration : 7> ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN{printf(" <RoutineDeclaration : 4> ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN{printf(" <RoutineDeclaration : 5> ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN{printf(" <RoutineDeclaration : 6> ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN{printf(" <RoutineDeclaration : 7> ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN{printf(" <RoutineDeclaration : 7> ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN{printf(" <RoutineDeclaration : 8> ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type{printf(" <RoutineDeclaration : 6> ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type{printf(" <RoutineDeclaration : 7> ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN {printf(" <RoutineDeclaration : 8> ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN{printf(" <RoutineDeclaration : 9> ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN  {printf(" <RoutineDeclaration : 9> ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN {printf(" <RoutineDeclaration : 10> ");}
                   {printf(" <RoutineDeclaration : 0> ");}
;
ParameterDeclaration : IDENT COLON IDENT{printf(" <ParameterDeclaration : 3> ");}
					 | IDENT COLON PrimitiveType{printf(" <ParameterDeclaration : 3> ");}
;
Parameters : ParameterDeclaration{printf(" <Parameters : 1> ");}
		   | ParameterDeclaration COMMA Parameters{printf(" <Parameters : 3> ");}
;
Body : SimpleDeclaration TERMINAL{printf(" <Body : 2> ");}
     | Statement TERMINAL{printf(" <Body : 2> ");}
     | SimpleDeclaration TERMINAL Body{printf(" <Body : 3> ");}
     | Statement TERMINAL Body {printf(" <Body : 3> ");}
;
Statement : Assignment{printf(" <Statement : 1> ");}
		  | RoutineCall{printf(" <Statement : 1> ");}
		  | WhileLoop{printf(" <Statement : 1> ");}
		  | ForLoop{printf(" <Statement : 1> ");}
		  | IfStatement {printf(" <Statement : 1> ");}
;
Assignment : ModifiablePrimary ASSIGN Expression {printf(" <Assignment : 3> ");}
;
RoutineCall : IDENT LPAREN RPAREN {printf(" <RoutineCall : 3> ");}
            | IDENT LPAREN Expressions RPAREN {printf(" <RoutineCall : 4> ");}
;
Expressions : Expression{printf(" <Expressions : 1> ");}
			| Expression COMMA Expressions{printf(" <Expressions : 3> ");}
;
WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN{printf(" <WhileLoop : 4> ");}
		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN{printf(" <WhileLoop : 5> ");}
;
ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN {printf(" <ForLoop : 5> ");}
		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN{printf(" <ForLoop : 6> ");}
;
Range : IN_TOKEN Expression FALLEN_COLON Expression{printf(" <Range : 4> ");}
      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression {printf(" <Range : 5> ");}
;
IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN{printf(" <IfStatement : 5> ");}
			| IF_TOKEN Expression THEN_TOKEN END_TOKEN{printf(" <IfStatement : 4> ");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN{printf(" <IfStatement : 7> ");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN{printf(" <IfStatement : 6> ");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN{printf(" <IfStatement : 6> ");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN{printf(" <IfStatement : 5> ");}
;
%%
int main(int argc, char **argv){
	yyparse();
}
int yyerror(char *s){
	printf("\n\n-\nError: %s\n-\n", s);
}