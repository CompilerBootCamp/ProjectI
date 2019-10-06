%{
#include <stdio.h>
%}
%token TERMINAL ASSIGN VAR_TOKEN IDENT COLON IS_TOKEN TYPE_TOKEN ROUTINE_TOKEN END_TOKEN INT_TOKEN REAL_TOKEN BOOL_TOKEN REC_TOKEN ARRAY_TOKEN LBRACKET RBRACKET LPAREN RPAREN WHILE_TOKEN LOOP_TOKEN FOR_TOKEN IN_TOKEN REVERSE_TOKEN FALLEN_COLON IF_TOKEN THEN_TOKEN ELSE_TOKEN AND_TOKEN OR_TOKEN XOR_TOKEN LESS LESS_OR_EQ MORE MORE_OR_EQ EQ NOT_EQ MULTIPLY DIVIDE MOD PLUS MINUS INT_LITERAL REAL_LITERAL TRUE_TOKEN FALSE_TOKEN POINT
%start Program
%%
Program : RoutineDeclarations SimpleDeclarations;
RoutineDeclarations : | RoutineDeclaration RoutineDeclarations;
SimpleDeclarations : | SimpleDeclaration SimpleDeclarations;
SimpleDeclarationNoTerminal : VariableDeclaration | TypeDeclaration;
SimpleDeclaration: SimpleDeclarationNoTerminal TERMINAL;
VariableDeclaration : VAR_TOKEN IDENT COLON Type
                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression
                    | VAR_TOKEN IDENT IS_TOKEN Expression;
VariableDeclarations : | VariableDeclaration | VariableDeclaration TERMINAL VariableDeclarations;
TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type;
RoutineDeclarationNoTerminal : ROUTINE_TOKEN IDENT
                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN
                   | ROUTINE_TOKEN IDENT COLON Type
                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN
                   | ROUTINE_TOKEN IDENT Parameters
                   | ROUTINE_TOKEN IDENT Parameters IS_TOKEN Body END_TOKEN
                   | ROUTINE_TOKEN IDENT Parameters COLON Type
                   | ROUTINE_TOKEN IDENT Parameters COLON Type IS_TOKEN Body END_TOKEN;
RoutineDeclaration : RoutineDeclarationNoTerminal TERMINAL;
Parameters : | ParameterDeclaration Parameters;
ParameterDeclaration : IDENT COLON IDENT TERMINAL;
Type : PrimitiveType | ArrayType | RecordType | IDENT;
PrimitiveType : INT_TOKEN | REAL_TOKEN | BOOL_TOKEN;
RecordType : REC_TOKEN VariableDeclarations END_TOKEN TERMINAL;
ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type
          | ARRAY_TOKEN LBRACKET RBRACKET Type
          | ARRAY_TOKEN Type;
Body : SimpleDeclaration
     | Statement
     | SimpleDeclaration TERMINAL Body
     | Statement TERMINAL Body;
Statement : Assignment | RoutineCall | WhileLoop | ForLoop | IfStatement;
Assignment : ModifiablePrimary ASSIGN Expression;
RoutineCall : IDENT LPAREN RPAREN 
            | IDENT LPAREN Expressions RPAREN;
Expressions : Expression | Expression Expressions;
WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN TERMINAL;
ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN TERMINAL;
Range : IN_TOKEN Expression FALLEN_COLON Expression
      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression;
IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN TERMINAL
            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN TERMINAL;
Expression : Relation | Relation Logical Relation;
Logical : AND_TOKEN | OR_TOKEN | XOR_TOKEN;
Relation : Simple | Simple Correlation Simple;
Correlation : LESS | LESS_OR_EQ | MORE | MORE_OR_EQ | EQ | NOT_EQ;
Simple : Factor | Factor FactorSign Factor;
FactorSign : MULTIPLY | DIVIDE | MOD;
Factor : Summand | Summand Sign Summand;
Sign : PLUS | MINUS;
Summand : Primary | LPAREN Expression RPAREN;
Primary : INT_LITERAL | REAL_LITERAL | TRUE_TOKEN | FALSE_TOKEN | ModifiablePrimary;
ModifiablePrimary : IDENT
                  | IDENT POINT IDENT
                  | IDENT LBRACKET Expression RBRACKET
                  | IDENT POINT IDENT LBRACKET Expression RBRACKET;
%%
int main(int argc, char **argv){
	yyparse();
}
int yyerror(char *s){
	printf("error: %s\n", s);
}
