%{
#include <stdio.h>
%}
%token ASSIGN LESS_OR_EQ MORE_OR_EQ NOT_EQ FALLEN_COLON TERMINAL COLON COMMA LBRACKET RBRACKET LPAREN RPAREN MULTIPLY DIVIDE MOD PLUS MINUS POINT LESS MORE EQ VAR_TOKEN IS_TOKEN TYPE_TOKEN ROUTINE_TOKEN END_TOKEN INT_TOKEN REAL_TOKEN BOOL_TOKEN REC_TOKEN ARRAY_TOKEN WHILE_TOKEN LOOP_TOKEN FOR_TOKEN IN_TOKEN REVERSE_TOKEN IF_TOKEN THEN_TOKEN ELSE_TOKEN AND_TOKEN OR_TOKEN XOR_TOKEN TRUE_TOKEN FALSE_TOKEN IDENT INT_LITERAL REAL_LITERAL
%start Program
%%
Program :  {printf(" \t ");}
		| ProgramFull {printf(" \t ");}
;
ProgramFull : SimpleDeclaration TERMINAL {printf(" \t ");}
			| SimpleDeclaration TERMINAL ProgramFull {printf(" \t ");}
			| RoutineDeclaration TERMINAL {printf(" \t ");}
			| RoutineDeclaration TERMINAL ProgramFull {printf(" \t ");}
;
SimpleDeclaration : VariableDeclaration {printf(" \t ");}
				  | TypeDeclaration {printf(" \t ");}
;
VariableDeclaration : VAR_TOKEN IDENT COLON Type {printf(" \t ");}
                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression {printf(" \t ");}
                    | VAR_TOKEN IDENT IS_TOKEN Expression {printf(" \t ");}
;
VariableDeclarations : VariableDeclaration TERMINAL {printf(" \t ");}
					 | VariableDeclaration TERMINAL VariableDeclarations  {printf(" \t ");}
;
TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type {printf(" \t ");}
;
Type : PrimitiveType {printf(" \t ");}
	 | ArrayType {printf(" \t ");}
	 | RecordType {printf(" \t ");}
	 | IDENT  {printf(" \t ");}
;
PrimitiveType : INT_TOKEN {printf(" \t ");}
			  | REAL_TOKEN {printf(" \t ");}
			  | BOOL_TOKEN  {printf(" \t ");}
;
RecordType : REC_TOKEN END_TOKEN {printf(" \t ");}
		   | REC_TOKEN VariableDeclarations END_TOKEN {printf(" \t ");}
;
ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type {printf(" \t ");}
          | ARRAY_TOKEN LBRACKET RBRACKET Type {printf(" \t ");}
          | ARRAY_TOKEN Type  {printf(" \t ");}
;
Expression : Relation {printf(" \t ");}
		   | Relation Logical Relation  {printf(" \t ");}
;
Logical : AND_TOKEN {printf(" \t ");}
		| OR_TOKEN {printf(" \t ");}
		| XOR_TOKEN  {printf(" \t ");}
;
Relation : Simple {printf(" \t ");}
		 | Simple Correlation Simple  {printf(" \t ");}
;
Correlation : LESS {printf(" \t ");}
			| LESS_OR_EQ {printf(" \t ");}
			| MORE {printf(" \t ");}
			| MORE_OR_EQ {printf(" \t ");}
			| EQ {printf(" \t ");}
			| NOT_EQ  {printf(" \t ");}
;
Simple : Factor  {printf(" \t ");}
	   | Factor FactorSign Factor  {printf(" \t ");}
;
FactorSign : MULTIPLY  {printf(" \t ");}
		   | DIVIDE {printf(" \t ");}
		   | MOD  {printf(" \t ");}
;
Factor : Summand {printf(" \t ");}
	   | Summand Sign Summand  {printf(" \t ");}
;
Sign : PLUS {printf(" \t ");}
	 | MINUS  {printf(" \t ");}
;
Summand : Primary {printf(" \t ");}
		| LPAREN Expression RPAREN  {printf(" \t ");}
;
Primary : INT_LITERAL {printf(" \t ");}
		| REAL_LITERAL {printf(" \t ");}
		| TRUE_TOKEN {printf(" \t ");}
		| FALSE_TOKEN {printf(" \t ");}
		| ModifiablePrimary {printf(" \t ");}
		| RoutineCall {printf(" \t ");}
;
ModifiablePrimary : IDENT {printf(" \t ");}
                  | IDENT ModifiableSecondary {printf(" \t ");}
;
ModifiableSecondary : POINT IDENT {printf(" \t ");}
					| LBRACKET Expression RBRACKET {printf(" \t ");}
					| POINT IDENT ModifiableSecondary {printf(" \t ");}
					| LBRACKET Expression RBRACKET ModifiableSecondary {printf(" \t ");}
;
RoutineDeclaration : ROUTINE_TOKEN IDENT {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT COLON Type {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN  {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN   {printf(" \t ");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN  {printf(" \t ");}
                    {printf(" \t ");}
;
ParameterDeclaration : IDENT COLON IDENT {printf(" \t ");}
					 | IDENT COLON PrimitiveType {printf(" \t ");}
;
Parameters : ParameterDeclaration {printf(" \t ");}
		   | ParameterDeclaration COMMA Parameters {printf(" \t ");}
;
Body : SimpleDeclaration TERMINAL {printf(" \t ");}
     | Statement TERMINAL {printf(" \t ");}
     | SimpleDeclaration TERMINAL Body {printf(" \t ");}
     | Statement TERMINAL Body  {printf(" \t ");}
;
Statement : Assignment {printf(" \t ");}
		  | RoutineCall {printf(" \t ");}
		  | WhileLoop {printf(" \t ");}
		  | ForLoop {printf(" \t ");}
		  | IfStatement  {printf(" \t ");}
;
Assignment : ModifiablePrimary ASSIGN Expression  {printf(" \t ");}
;
RoutineCall : IDENT LPAREN RPAREN  {printf(" \t ");}
            | IDENT LPAREN Expressions RPAREN  {printf(" \t ");}
;
Expressions : Expression {printf(" \t ");}
			| Expression COMMA Expressions {printf(" \t ");}
;
WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN {printf(" \t ");}
		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN {printf(" \t ");}
;
ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN  {printf(" \t ");}
		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN {printf(" \t ");}
;
Range : IN_TOKEN Expression FALLEN_COLON Expression {printf(" \t ");}
      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression  {printf(" \t ");}
;
IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN {printf(" \t ");}
			| IF_TOKEN Expression THEN_TOKEN END_TOKEN {printf(" \t ");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN {printf(" \t ");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN {printf(" \t ");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN {printf(" \t ");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN {printf(" \t ");}
;
%%
int main(int argc, char **argv){
	yyparse();
}
int yyerror(char *s){
	printf("\n\n-\nError: %s\n-\n", s);
}