%{
#include <stdio.h>
extern void drop_buf();
extern void printf_into(char* s);
%}
%parse-param { FILE* fp }
%token ASSIGN LESS_OR_EQ MORE_OR_EQ NOT_EQ FALLEN_COLON TERMINAL COLON COMMA LBRACKET RBRACKET LPAREN RPAREN MULTIPLY DIVIDE MOD PLUS MINUS POINT LESS MORE EQ VAR_TOKEN IS_TOKEN TYPE_TOKEN ROUTINE_TOKEN END_TOKEN INT_TOKEN REAL_TOKEN BOOL_TOKEN REC_TOKEN ARRAY_TOKEN WHILE_TOKEN LOOP_TOKEN FOR_TOKEN IN_TOKEN REVERSE_TOKEN IF_TOKEN THEN_TOKEN ELSE_TOKEN AND_TOKEN OR_TOKEN XOR_TOKEN TRUE_TOKEN FALSE_TOKEN IDENT INT_LITERAL REAL_LITERAL
%start Program
%%
Program :{printf_into("<Program,0,Program :>+");}
		| ProgramFull{printf_into("<Program,1,		| ProgramFull>+");}
;
ProgramFull : SimpleDeclaration TERMINAL{printf_into("<ProgramFull,2,ProgramFull : SimpleDeclaration TERMINAL>+");}
			| SimpleDeclaration TERMINAL ProgramFull{printf_into("<ProgramFull,3,			| SimpleDeclaration TERMINAL ProgramFull>+");}
			| RoutineDeclaration TERMINAL{printf_into("<ProgramFull,2,			| RoutineDeclaration TERMINAL>+");}
			| RoutineDeclaration TERMINAL ProgramFull{printf_into("<ProgramFull,3,			| RoutineDeclaration TERMINAL ProgramFull>+");}
;
SimpleDeclaration : VariableDeclaration{printf_into("<SimpleDeclaration,1,SimpleDeclaration : VariableDeclaration>+");}
				  | TypeDeclaration{printf_into("<SimpleDeclaration,1,				  | TypeDeclaration>+");}
;
VariableDeclaration : VAR_TOKEN IDENT COLON Type{printf_into("<VariableDeclaration,4,VariableDeclaration : VAR_TOKEN IDENT COLON Type>+");}
                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression{printf_into("<VariableDeclaration,6,                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression>+");}
                    | VAR_TOKEN IDENT IS_TOKEN Expression{printf_into("<VariableDeclaration,4,                    | VAR_TOKEN IDENT IS_TOKEN Expression>+");}
;
VariableDeclarations : VariableDeclaration TERMINAL{printf_into("<VariableDeclarations,2,VariableDeclarations : VariableDeclaration TERMINAL>+");}
					 | VariableDeclaration TERMINAL VariableDeclarations {printf_into("<VariableDeclarations,3,					 | VariableDeclaration TERMINAL VariableDeclarations >+");}
;
TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type{printf_into("<TypeDeclaration,4,TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type>+");}
;
Type : PrimitiveType{printf_into("<Type,1,Type : PrimitiveType>+");}
	 | ArrayType{printf_into("<Type,1,	 | ArrayType>+");}
	 | RecordType{printf_into("<Type,1,	 | RecordType>+");}
	 | IDENT {printf_into("<Type,1,	 | IDENT >+");}
;
PrimitiveType : INT_TOKEN{printf_into("<PrimitiveType,1,PrimitiveType : INT_TOKEN>+");}
			  | REAL_TOKEN{printf_into("<PrimitiveType,1,			  | REAL_TOKEN>+");}
			  | BOOL_TOKEN {printf_into("<PrimitiveType,1,			  | BOOL_TOKEN >+");}
;
RecordType : REC_TOKEN END_TOKEN{printf_into("<RecordType,2,RecordType : REC_TOKEN END_TOKEN>+");}
		   | REC_TOKEN VariableDeclarations END_TOKEN{printf_into("<RecordType,3,		   | REC_TOKEN VariableDeclarations END_TOKEN>+");}
;
ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type{printf_into("<ArrayType,5,ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type>+");}
          | ARRAY_TOKEN LBRACKET RBRACKET Type{printf_into("<ArrayType,4,          | ARRAY_TOKEN LBRACKET RBRACKET Type>+");}
          | ARRAY_TOKEN Type {printf_into("<ArrayType,2,          | ARRAY_TOKEN Type >+");}
;
Expression : Relation{printf_into("<Expression,1,Expression : Relation>+");}
		   | Relation Logical Relation {printf_into("<Expression,3,		   | Relation Logical Relation >+");}
;
Logical : AND_TOKEN{printf_into("<Logical,1,Logical : AND_TOKEN>+");}
		| OR_TOKEN{printf_into("<Logical,1,		| OR_TOKEN>+");}
		| XOR_TOKEN {printf_into("<Logical,1,		| XOR_TOKEN >+");}
;
Relation : Simple{printf_into("<Relation,1,Relation : Simple>+");}
		 | Simple Correlation Simple {printf_into("<Relation,3,		 | Simple Correlation Simple >+");}
;
Correlation : LESS{printf_into("<Correlation,1,Correlation : LESS>+");}
			| LESS_OR_EQ{printf_into("<Correlation,1,			| LESS_OR_EQ>+");}
			| MORE{printf_into("<Correlation,1,			| MORE>+");}
			| MORE_OR_EQ{printf_into("<Correlation,1,			| MORE_OR_EQ>+");}
			| EQ{printf_into("<Correlation,1,			| EQ>+");}
			| NOT_EQ {printf_into("<Correlation,1,			| NOT_EQ >+");}
;
Simple : Factor {printf_into("<Simple,1,Simple : Factor >+");}
	   | Factor FactorSign Factor {printf_into("<Simple,3,	   | Factor FactorSign Factor >+");}
;
FactorSign : MULTIPLY {printf_into("<FactorSign,1,FactorSign : MULTIPLY >+");}
		   | DIVIDE{printf_into("<FactorSign,1,		   | DIVIDE>+");}
		   | MOD {printf_into("<FactorSign,1,		   | MOD >+");}
;
Factor : Summand{printf_into("<Factor,1,Factor : Summand>+");}
	   | Summand Sign Summand {printf_into("<Factor,3,	   | Summand Sign Summand >+");}
;
Sign : PLUS{printf_into("<Sign,1,Sign : PLUS>+");}
	 | MINUS {printf_into("<Sign,1,	 | MINUS >+");}
;
Summand : Primary{printf_into("<Summand,1,Summand : Primary>+");}
		| LPAREN Expression RPAREN {printf_into("<Summand,3,		| LPAREN Expression RPAREN >+");}
;
Primary : INT_LITERAL{printf_into("<Primary,1,Primary : INT_LITERAL>+");}
		| REAL_LITERAL{printf_into("<Primary,1,		| REAL_LITERAL>+");}
		| TRUE_TOKEN{printf_into("<Primary,1,		| TRUE_TOKEN>+");}
		| FALSE_TOKEN{printf_into("<Primary,1,		| FALSE_TOKEN>+");}
		| ModifiablePrimary{printf_into("<Primary,1,		| ModifiablePrimary>+");}
		| RoutineCall{printf_into("<Primary,1,		| RoutineCall>+");}
;
ModifiablePrimary : IDENT{printf_into("<ModifiablePrimary,1,ModifiablePrimary : IDENT>+");}
                  | IDENT ModifiableSecondary{printf_into("<ModifiablePrimary,2,                  | IDENT ModifiableSecondary>+");}
;
ModifiableSecondary : POINT IDENT{printf_into("<ModifiableSecondary,2,ModifiableSecondary : POINT IDENT>+");}
					| LBRACKET Expression RBRACKET{printf_into("<ModifiableSecondary,3,					| LBRACKET Expression RBRACKET>+");}
					| POINT IDENT ModifiableSecondary{printf_into("<ModifiableSecondary,3,					| POINT IDENT ModifiableSecondary>+");}
					| LBRACKET Expression RBRACKET ModifiableSecondary{printf_into("<ModifiableSecondary,4,					| LBRACKET Expression RBRACKET ModifiableSecondary>+");}
;
RoutineDeclaration : ROUTINE_TOKEN IDENT{printf_into("<RoutineDeclaration,2,RoutineDeclaration : ROUTINE_TOKEN IDENT>+");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN{printf_into("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN{printf_into("<RoutineDeclaration,5,                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT COLON Type{printf_into("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT COLON Type>+");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN{printf_into("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN{printf_into("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN{printf_into("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN{printf_into("<RoutineDeclaration,5,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN{printf_into("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN{printf_into("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN{printf_into("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN{printf_into("<RoutineDeclaration,8,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type{printf_into("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type>+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type{printf_into("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN {printf_into("<RoutineDeclaration,8,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN >+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN{printf_into("<RoutineDeclaration,9,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN>+");}
                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN  {printf_into("<RoutineDeclaration,9,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN  >+");}
                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN{printf_into("<RoutineDeclaration,10,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN>+");}
;
ParameterDeclaration : IDENT COLON IDENT{printf_into("<ParameterDeclaration,3,ParameterDeclaration : IDENT COLON IDENT>+");}
					 | IDENT COLON PrimitiveType{printf_into("<ParameterDeclaration,3,					 | IDENT COLON PrimitiveType>+");}
;
Parameters : ParameterDeclaration{printf_into("<Parameters,1,Parameters : ParameterDeclaration>+");}
		   | ParameterDeclaration COMMA Parameters{printf_into("<Parameters,3,		   | ParameterDeclaration COMMA Parameters>+");}
;
Body : SimpleDeclaration TERMINAL{printf_into("<Body,2,Body : SimpleDeclaration TERMINAL>+");}
     | Statement TERMINAL{printf_into("<Body,2,     | Statement TERMINAL>+");}
     | SimpleDeclaration TERMINAL Body{printf_into("<Body,3,     | SimpleDeclaration TERMINAL Body>+");}
     | Statement TERMINAL Body {printf_into("<Body,3,     | Statement TERMINAL Body >+");}
;
Statement : Assignment{printf_into("<Statement,1,Statement : Assignment>+");}
		  | RoutineCall{printf_into("<Statement,1,		  | RoutineCall>+");}
		  | WhileLoop{printf_into("<Statement,1,		  | WhileLoop>+");}
		  | ForLoop{printf_into("<Statement,1,		  | ForLoop>+");}
		  | IfStatement {printf_into("<Statement,1,		  | IfStatement >+");}
;
Assignment : ModifiablePrimary ASSIGN Expression {printf_into("<Assignment,3,Assignment : ModifiablePrimary ASSIGN Expression >+");}
;
RoutineCall : IDENT LPAREN RPAREN {printf_into("<RoutineCall,3,RoutineCall : IDENT LPAREN RPAREN >+");}
            | IDENT LPAREN Expressions RPAREN {printf_into("<RoutineCall,4,            | IDENT LPAREN Expressions RPAREN >+");}
;
Expressions : Expression{printf_into("<Expressions,1,Expressions : Expression>+");}
			| Expression COMMA Expressions{printf_into("<Expressions,3,			| Expression COMMA Expressions>+");}
;
WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN{printf_into("<WhileLoop,4,WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN>+");}
		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN{printf_into("<WhileLoop,5,		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN>+");}
;
ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN {printf_into("<ForLoop,5,ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN >+");}
		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN{printf_into("<ForLoop,6,		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN>+");}
;
Range : IN_TOKEN Expression FALLEN_COLON Expression{printf_into("<Range,4,Range : IN_TOKEN Expression FALLEN_COLON Expression>+");}
      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression {printf_into("<Range,5,      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression >+");}
;
IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN{printf_into("<IfStatement,5,IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN>+");}
			| IF_TOKEN Expression THEN_TOKEN END_TOKEN{printf_into("<IfStatement,4,			| IF_TOKEN Expression THEN_TOKEN END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN{printf_into("<IfStatement,7,            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN{printf_into("<IfStatement,6,            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN{printf_into("<IfStatement,6,            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN>+");}
            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN{printf_into("<IfStatement,5,            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN>+");}
;
%%
int yyerror(char *s) {
	drop_buf();
	printf_into("<!Error!,-1,>");
}
