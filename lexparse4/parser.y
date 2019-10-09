%{
#include <stdio.h>
%}
%token ASSIGN LESS_OR_EQ MORE_OR_EQ NOT_EQ FALLEN_COLON TERMINAL COLON COMMA LBRACKET RBRACKET LPAREN RPAREN MULTIPLY DIVIDE MOD PLUS MINUS POINT LESS MORE EQ VAR_TOKEN IS_TOKEN TYPE_TOKEN ROUTINE_TOKEN END_TOKEN INT_TOKEN REAL_TOKEN BOOL_TOKEN REC_TOKEN ARRAY_TOKEN WHILE_TOKEN LOOP_TOKEN FOR_TOKEN IN_TOKEN REVERSE_TOKEN IF_TOKEN THEN_TOKEN ELSE_TOKEN AND_TOKEN OR_TOKEN XOR_TOKEN TRUE_TOKEN FALSE_TOKEN IDENT INT_LITERAL REAL_LITERAL
%start Program
%%
Program : {printf("<Program,0,Program : >+");}
		| ProgramFull{printf("<Program,1,		| ProgramFull>+");}
;
ProgramFull : SimpleDeclaration TERMINAL{printf("<ProgramFull,2,ProgramFull : SimpleDeclaration TERMINAL>+");}
			| SimpleDeclaration TERMINAL ProgramFull{printf("<ProgramFull,3,			| SimpleDeclaration TERMINAL ProgramFull>+");}
			| RoutineDeclaration TERMINAL{printf("<ProgramFull,2,			| RoutineDeclaration TERMINAL>+");}
			| RoutineDeclaration TERMINAL ProgramFull{printf("<ProgramFull,3,			| RoutineDeclaration TERMINAL ProgramFull>+");}
;
SimpleDeclaration : VariableDeclaration{printf("<SimpleDeclaration,1,SimpleDeclaration : VariableDeclaration>+");}
				  | TypeDeclaration{printf("<SimpleDeclaration,1,				  | TypeDeclaration>+");}
;
VariableDeclaration : VAR_TOKEN IDENT COLON Type{printf("<VariableDeclaration,4,VariableDeclaration : VAR_TOKEN IDENT COLON Type>+");}
                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression{printf("<VariableDeclaration,6,                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression>+");}
                    | VAR_TOKEN IDENT IS_TOKEN Expression{printf("<VariableDeclaration,4,                    | VAR_TOKEN IDENT IS_TOKEN Expression>+");}
;
VariableDeclarations : VariableDeclaration TERMINAL{printf("<VariableDeclarations,2,VariableDeclarations : VariableDeclaration TERMINAL>+");}
					 | VariableDeclaration TERMINAL VariableDeclarations {printf("<VariableDeclarations,3,					 | VariableDeclaration TERMINAL VariableDeclarations >+");}
;
TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type{printf("<TypeDeclaration,4,TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type>+");}
;
Type : PrimitiveType{printf("<Type,1,Type : PrimitiveType>+");}
	 | ArrayType{printf("<Type,1,	 | ArrayType>+");}
	 | RecordType{printf("<Type,1,	 | RecordType>+");}
	 | IDENT {printf("<Type,1,	 | IDENT >+");}
;
PrimitiveType : INT_TOKEN{printf("<PrimitiveType,1,PrimitiveType : INT_TOKEN>+");}
			  | REAL_TOKEN{printf("<PrimitiveType,1,			  | REAL_TOKEN>+");}
			  | BOOL_TOKEN {printf("<PrimitiveType,1,			  | BOOL_TOKEN >+");}
;
RecordType : REC_TOKEN END_TOKEN{printf("<RecordType,2,RecordType : REC_TOKEN END_TOKEN>+");}
		   | REC_TOKEN VariableDeclarations END_TOKEN{printf("<RecordType,3,		   | REC_TOKEN VariableDeclarations END_TOKEN>+");}
;
ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type{printf("<ArrayType,5,ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type>+");}
          | ARRAY_TOKEN LBRACKET RBRACKET Type{printf("<ArrayType,4,          | ARRAY_TOKEN LBRACKET RBRACKET Type>+");}
          | ARRAY_TOKEN Type {printf("<ArrayType,2,          | ARRAY_TOKEN Type >+");}
;
Expression : Relation{printf("<Expression,1,Expression : Relation>+");}
		   | Relation Logical Relation {printf("<Expression,3,		   | Relation Logical Relation >+");}
;
Logical : AND_TOKEN{printf("<Logical,1,Logical : AND_TOKEN>+");}
		| OR_TOKEN{printf("<Logical,1,		| OR_TOKEN>+");}
		| XOR_TOKEN {printf("<Logical,1,		| XOR_TOKEN >+");}
;
Relation : Simple{printf("<Relation,1,Relation : Simple>+");}
		 | Simple Correlation Simple {printf("<Relation,3,		 | Simple Correlation Simple >+");}
;
Correlation : LESS{printf("<Correlation,1,Correlation : LESS>+");}
			| LESS_OR_EQ{printf("<Correlation,1,			| LESS_OR_EQ>+");}
			| MORE{printf("<Correlation,1,			| MORE>+");}
			| MORE_OR_EQ{printf("<Correlation,1,			| MORE_OR_EQ>+");}
			| EQ{printf("<Correlation,1,			| EQ>+");}
			| NOT_EQ {printf("<Correlation,1,			| NOT_EQ >+");}
;
Simple : Factor {printf("<Simple,1,Simple : Factor >+");}
	   | Factor FactorSign Factor {printf("<Simple,3,	   | Factor FactorSign Factor >+");}
;
FactorSign : MULTIPLY {printf("<FactorSign,1,FactorSign : MULTIPLY >+");}
		   | DIVIDE{printf("<FactorSign,1,		   | DIVIDE>+");}
		   | MOD {printf("<FactorSign,1,		   | MOD >+");}
;
Factor : Summand{printf("<Factor,1,Factor : Summand>+");}
	   | Summand Sign Summand {printf("<Factor,3,	   | Summand Sign Summand >+");}
;
Sign : PLUS{printf("<Sign,1,Sign : PLUS>+");}
	 | MINUS {printf("<Sign,1,	 | MINUS >+");}
;
Summand : Primary{printf("<Summand,1,Summand : Primary>+");}
		| LPAREN Expression RPAREN {printf("<Summand,3,		| LPAREN Expression RPAREN >+");}
;
Primary : INT_LITERAL{printf("<Primary,1,Primary : INT_LITERAL>+");}
		| REAL_LITERAL{printf("<Primary,1,		| REAL_LITERAL>+");}
		| TRUE_TOKEN{printf("<Primary,1,		| TRUE_TOKEN>+");}
		| FALSE_TOKEN{printf("<Primary,1,		| FALSE_TOKEN>+");}
		| ModifiablePrimary{printf("<Primary,1,		| ModifiablePrimary>+");}
		| RoutineCall{printf("<Primary,1,		| RoutineCall>+");}
;
ModifiablePrimary : IDENT{printf("<ModifiablePrimary,1,ModifiablePrimary : IDENT>+");}
                  | IDENT ModifiableSecondary{printf("<ModifiablePrimary,2,                  | IDENT ModifiableSecondary>+");}
;
ModifiableSecondary : POINT IDENT{printf("<ModifiableSecondary,2,ModifiableSecondary : POINT IDENT>+");}
					| LBRACKET Expression RBRACKET{printf("<ModifiableSecondary,3,					| LBRACKET Expression RBRACKET>+");}
					| POINT IDENT ModifiableSecondary{printf("<ModifiableSecondary,3,					| POINT IDENT ModifiableSecondary>+");}
					| LBRACKET Expression RBRACKET ModifiableSecondary{printf("<ModifiableSecondary,4,					| LBRACKET Expression RBRACKET ModifiableSecondary>+");}
;
RoutineDeclaration : ROUTINE_TOKEN IDENT{printf("<RoutineDeclaration,2,RoutineDeclaration : ROUTINE_TOKEN IDENT>+");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN{printf("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN{printf("<RoutineDeclaration,5,                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT COLON Type{printf("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT COLON Type>+");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN{printf("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN{printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN{printf("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN{printf("<RoutineDeclaration,5,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN{printf("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN{printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN{printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN{printf("<RoutineDeclaration,8,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type{printf("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type{printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN {printf("<RoutineDeclaration,8,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN >+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN{printf("<RoutineDeclaration,9,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN  {printf("<RoutineDeclaration,9,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN  >+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN {printf("<RoutineDeclaration,10,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN >+");}
                   {printf("<RoutineDeclaration,0,                   >+");}
;
ParameterDeclaration : IDENT COLON IDENT{printf("<ParameterDeclaration,3,ParameterDeclaration : IDENT COLON IDENT>+");}
					 | IDENT COLON PrimitiveType{printf("<ParameterDeclaration,3,					 | IDENT COLON PrimitiveType>+");}
;
Parameters : ParameterDeclaration{printf("<Parameters,1,Parameters : ParameterDeclaration>+");}
		   | ParameterDeclaration COMMA Parameters{printf("<Parameters,3,		   | ParameterDeclaration COMMA Parameters>+");}
;
Body : SimpleDeclaration TERMINAL{printf("<Body,2,Body : SimpleDeclaration TERMINAL>+");}
     | Statement TERMINAL{printf("<Body,2,     | Statement TERMINAL>+");}
     | SimpleDeclaration TERMINAL Body{printf("<Body,3,     | SimpleDeclaration TERMINAL Body>+");}
     | Statement TERMINAL Body {printf("<Body,3,     | Statement TERMINAL Body >+");}
;
Statement : Assignment{printf("<Statement,1,Statement : Assignment>+");}
		  | RoutineCall{printf("<Statement,1,		  | RoutineCall>+");}
		  | WhileLoop{printf("<Statement,1,		  | WhileLoop>+");}
		  | ForLoop{printf("<Statement,1,		  | ForLoop>+");}
		  | IfStatement {printf("<Statement,1,		  | IfStatement >+");}
;
Assignment : ModifiablePrimary ASSIGN Expression {printf("<Assignment,3,Assignment : ModifiablePrimary ASSIGN Expression >+");}
;
RoutineCall : IDENT LPAREN RPAREN {printf("<RoutineCall,3,RoutineCall : IDENT LPAREN RPAREN >+");}
            | IDENT LPAREN Expressions RPAREN {printf("<RoutineCall,4,            | IDENT LPAREN Expressions RPAREN >+");}
;
Expressions : Expression{printf("<Expressions,1,Expressions : Expression>+");}
			| Expression COMMA Expressions{printf("<Expressions,3,			| Expression COMMA Expressions>+");}
;
WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN{printf("<WhileLoop,4,WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN>+");}
		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN{printf("<WhileLoop,5,		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN>+");}
;
ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN {printf("<ForLoop,5,ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN >+");}
		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN{printf("<ForLoop,6,		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN>+");}
;
Range : IN_TOKEN Expression FALLEN_COLON Expression{printf("<Range,4,Range : IN_TOKEN Expression FALLEN_COLON Expression>+");}
      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression {printf("<Range,5,      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression >+");}
;
IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN{printf("<IfStatement,5,IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN>+");}
			| IF_TOKEN Expression THEN_TOKEN END_TOKEN{printf("<IfStatement,4,			| IF_TOKEN Expression THEN_TOKEN END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN{printf("<IfStatement,7,            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN{printf("<IfStatement,6,            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN{printf("<IfStatement,6,            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN{printf("<IfStatement,5,            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN>+");}
;
%%
int main(int argc, char **argv){
	yyparse();
}
int yyerror(char *s){
	printf("\n\n-\nError: %s\n-\n", s);
}