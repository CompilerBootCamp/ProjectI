import sys
import ply.yacc as yacc
from lex_pas import tokens

sys.path.append('./')
from AST import *

precedence=(
  ('left','oPLUS','oMINUS'),
  ('left','oMUL','oDIV','kDIV','kMOD')
)

error_list=[]

def p_Start(p):
  'program : routine '
  print ">> ", p
  p[0]=ProgramNode("program",p[1])

def p_Routine(p):
  'routine : routine_head routine_body'
  print 'routine : ', p[1],p[2]
  p[0]=RoutineNode(p[1],p[2])

def p_Routine_head(p):
  'routine_head : type_part var_part routine_part'
  print 'routine_head : ', p[1],p[2],p[3]
  p[0]=RoutineHeadNode(None,p[1],p[2],p[3])  

def p_Const_value_1(p):
  'const_value : cINTEGER'
  p[0]=ConstValueNode('int',p[1])

def p_Const_value_2(p):
  'const_value : cREAL'
  p[0]=ConstValueNode('real',p[1])

def p_Const_value_5(p):
  'const_value : cSYS_CON'
  p[0]=ConstValueNode('syscon',p[1])

# type_part : TYPE type_decl_list  |  empty
def p_Type_part(p):
  '''type_part : type_decl_list
               | empty'''
  print 'type_part : ', len(p)
  if len(p)==2:
    p[0]=p[1]
  else:
    p[0]=None

# type_decl_list : type_decl_list  type_definition  |  type_definition
def p_Type_decl_list_1(p):
  'type_decl_list : type_decl_list  type_definition'
  p[0]=p[1]
  p[0].append(p[2])

def p_Type_decl_list_2(p):
  'type_decl_list : type_definition'
  p[0]=TypeDeclListNode(p[1])

# type_definition : ID  EQUAL  type_decl  SEMI
def p_Type_definition(p):
  'type_definition : kTYPE yNAME kIS type_decl oSEMI'
  print 'type_definition : ', p[2],p[4]
  p[0]=TypeDefinitionNode(p[2],p[4])

# type_decl : simple_type_decl  |  array_type_decl  |  record_type_decl
def p_Type_decl(p):
  '''type_decl : simple_type_decl
               | array_type_decl
               | record_type_decl'''
  p[0]=p[1]

def p_Simple_type_decl_1(p):
  'simple_type_decl : cSYS_TYPE'
  p[0]=SimpleTypeNode(p[1])


def p_Simple_type_decl_4(p):
  'simple_type_decl : yNAME'
  p[0]=VariableTypeNode(p[1])

def p_Array_type_decl(p):
  'array_type_decl : kARRAY  oLB  const_value  oRB  type_decl'
  print 'array_type_decl : ', p[3],p[5]
  _start = ConstValueNode('int',1)
  _range = RangeTypeNode('range',(_start,p[3]))
  print _range, _range.lb, _range.rb
  p[0]=ArrayTypeNode(_range,p[5])

# record_type_decl : RECORD  field_decl_list  END
def p_Record_type_decl(p):
  'record_type_decl : kRECORD  field_decl_list  kEND'
  print 'record_type_decl : ', p[2]
  p[0]=RecordTypeNode(p[2]);

# field_decl_list : field_decl_list  field_decl  |  field_decl
def p_Field_decl_list_1(p):
  'field_decl_list : field_decl_list  field_decl'
  print "field_decl_list : ", p[1] , p[2]
  p[0]=p[1]
  p[0].append(p[2])

def p_Field_decl_list_2(p):
  'field_decl_list : field_decl'
  print "field_decl_list: ", p[1]
  p[0]=FieldDeclListNode(p[1])

# field_decl : name_list  COLON  type_decl  SEMI
def p_Field_decl(p):
  'field_decl : kVAR name_list  oCOLON  type_decl  oSEMI'
  print "field_decl: ", p[2], p[4]
  p[0] = RecordMemberDecl(p[2], p[4])

#p_Name_list_2
def p_Name_list(p):
  'name_list : yNAME'
  #p[0]=NameListNode(p[1])
  p[0] = p[1]

# var_part : VAR  var_decl_list  |  empty
def p_Var_part(p):
  '''var_part : var_decl_list
              | empty'''
  if len(p)==2:
    p[0]=p[1]
  else:
    p[0]=None

# var_decl_list :  var_decl_list  var_decl  |  var_decl
def p_Var_decl_list_1(p):
  'var_decl_list :  var_decl_list  var_decl'
  print 'var_decl_list1 : ', p[1], p[2]
  p[0]=p[1]
  p[0].append(p[2])

def p_Var_decl_list_2(p):
  'var_decl_list : var_decl'
  print 'var_decl_list2 : ', p[1]
  p[0]=VarDeclListNode(p[1])

# var_decl :  name_list  COLON  type_decl  SEMI
def p_Var_decl(p):
  'var_decl : kVAR  yNAME  oCOLON  type_decl  oSEMI'
  print 'var_decl : ', p[2],p[4]
  p[0]=VarDeclNode(p[2],p[4])


def p_Var_decl_is(p):
  'var_decl : kVAR  yNAME  oCOLON  type_decl kIS const_value oSEMI'
  print "!p_Var_decl_is ", p[2],p[4], p[6]
  p[0]=VarDeclNode(p[2],p[4], p[6])


def p_Routine_part_1(p):
  'routine_part :  routine_part  function_decl'
  p[0]=p[1]
  p[0].append(p[2])

def p_Routine_part_2(p):
  'routine_part :  function_decl'
  p[0]=FunctionDeclListNode(p[1])

def p_Routine_part_5(p):
  'routine_part : empty'
  p[0]=None

# function_decl : function_head  SEMI  sub_routine  SEMI
def p_Function_decl(p):
  'function_decl : function_head  kIS  sub_routine kEND oSEMI'
  print 'function_decl : ', p[1],p[3]
  p[0]=FunctionDeclNode(p[1],p[3])

# function_head :  FUNCTION  ID  parameters  COLON  simple_type_decl 
def p_Function_head(p):
  'function_head :  kROUTINE  yNAME  parameters  oCOLON  simple_type_decl '
  print 'function_head :  ', p[2],p[3],p[5]
  p[0]=FunctionPrototypeNode(p[2],p[3],p[5])

# sub_routine : routine
def p_Sub_routine(p):
  'sub_routine : routine'
  p[0]=p[1]

# parameters : LP  para_decl_list  RP  |  empty
def p_Parameters(p):
  '''parameters : oLP  para_decl_list  oRP
                | empty'''
  if len(p)==2:
    p[0]=None
  else:
    p[0]=p[2]

# para_decl_list : para_decl_list  SEMI  para_type_list  |  para_type_list
def p_Para_decl_list_1(p):
  'para_decl_list : para_decl_list  oSEMI  para_type_list'
  p[0]=p[1]
  p[0].append(p[3])

def p_Para_decl_list_2(p):
  'para_decl_list : para_type_list'
  p[0]=ParaDeclListNode(p[1])

# para_type_list : var_para_list COLON  simpe_type_decl  |  val_para_list  COLON  simple_type_decl
def p_Para_type_list_2(p):
  'para_type_list : var_para_list  oCOLON  simple_type_decl'
  p[0]=ParaTypeListNode(p[1],p[3])

# var_para_list : VAR  name_list
def p_Var_para_list_1(p):
  'var_para_list : kVAR  name_list'
  p[0]=p[2]

# val_para_list : name_list
def p_Var_para_list_2(p):
  'var_para_list : name_list'
  p[0]=p[1]

def p_Routine_body(p):
  'routine_body : compound_stmt'
  p[0]=p[1]

def p_Stmt_list(p):
  '''stmt_list : stmt_list stmt oSEMI
               | empty'''
  if(len(p)==4):
    if p[1] is None:      
      p[0]=StmtListNode(p[2])
    else:
      p[0]=p[1]
      p[0].append(p[2])
  else:
    p[0]=None

def p_Stmt_list_error(p):
  'stmt_list : stmt_list stmt error'  
  process_syntax_error(p,3,';')
  p[0]=None

def p_Stmt(p):
  '''stmt : cINTEGER  oCOLON  non_label_stmt
          | non_label_stmt'''
  if len(p)==4:
    p[3].set_id(p[1])
    p[0]=p[3]
  else:
    p[0]=p[1]

def p_Non_label_stmt(p):
  '''non_label_stmt : assign_stmt
                    | call_stmt
                    | compound_stmt
                    | if_stmt
                    | while_stmt
                    | for_stmt'''
  p[0]=p[1]


def p_Assign_stmt_1(p):
  'assign_stmt : yNAME  oASSIGN  expression'
  # print '$$$$$ ',p.lineno(1),p.lexpos(1)
  var=VariableNode(p[1])
  p[0]=create_stmt_node(':=',var,p[3])

def find_column(pos):
  print parser.text

def process_syntax_error(p,error_pos,expected_token):
  global error_list  
  # print 'syntax error in line %d at %d'%(p.lineno(error_pos),find_column(p.lexpos(2)))
  error_list.append((p.lineno(error_pos),p.lexpos(2),expected_token,p[error_pos].value))
  # print '@@@@@@@@@'
  # print p[error_pos].value

def p_Assign_stmt_1_error(p):
  'assign_stmt : yNAME  error  expression'  
  process_syntax_error(p,2,':=')  
  p[0]=None

def p_Assign_stmt_2(p):
  'assign_stmt : yNAME oLB expression oRB oASSIGN expression'
  var=ArrayMemberNode(p[1],[p[3]])
  p[0]=create_stmt_node(':=',var,p[6])

def p_Assign_stmt_3(p):
  'assign_stmt : yNAME  oDOT yNAME oASSIGN  expression'
  var=RecordMemberNode(p[1],p[3])
  p[0]=create_stmt_node(':=',var,p[5])

def p_call_stmt_2(p):
  'call_stmt : yNAME oLP args_list oRP'
  p[0]=create_stmt_node('fn',p[1],p[3])

def p_Compound_stmt(p):
  '''compound_stmt : stmt_list 
                   | empty'''
  print 'compound_stmt ', len(p)
  if len(p)==2:
    p[0]=p[1]
  else:
    p[0]=None

def p_If_stmt(p):
  'if_stmt : kIF expression kTHEN stmt_list else_clause '
  p[0]=create_stmt_node('if',p[2],p[4],p[5])

def p_Else_clause(p):
  '''else_clause : kELSE stmt_list kEND
                 | empty'''
  if len(p)==3:
    p[0]=p[2]
  else:
    p[0]=None


def p_While_stmt(p):
  'while_stmt : kWHILE  expression  kLOOP stmt_list kEND'
  p[0]=create_stmt_node('while',p[2],p[4])

def p_For_stmt(p):
  'for_stmt : kFOR  yNAME  kIN  expression  oDOTDOT expression  kLOOP stmt_list kEND'  
  #print p[5]
  #pdir=ConstValueNode('int',p[5].value)
  pdir=ConstValueNode('int', 1)
  p[0]=create_stmt_node('for',p[2],p[4],pdir,p[6],p[8])

# expression_list : expression_list  COMMA  expression  |  expression
def p_Expression_list(p):
  '''expression_list : expression_list  oCOMMA  expression
                     | expression'''
  if len(p)==4:
    if p[3] is not None:
      p[1].append(p[3])
      p[0]=p[1]
    else:
      p[0]=p[1]
  else:
    p[0]=ExprList(p[1])
    # p[0]=p[1]

def p_Expression_1(p):
  '''expression : expression  oGE  expr
                | expression  oGT  expr
                | expression  oLE  expr
                | expression  oLT  expr
                | expression  oEQUAL  expr'''
  p[0]=create_stmt_node('bin_expr',p[2],p[1],p[3])

def p_Expression_2(p):
  'expression : expr'
  p[0]=p[1]

def p_Expr(p):
  '''expr : expr  oPLUS  term
          | expr  oMINUS  term
          | expr  kOR  term
          | term'''
  if len(p)==4:
    p[0]=create_stmt_node('bin_expr',p[2],p[1],p[3])
  else:
    p[0]=p[1]

def p_Term(p):
  '''term : term  oMUL  factor
          | term  kDIV  factor
          | term  kMOD  factor 
          | term  kAND  factor
          | factor'''
  if len(p)==4:
    p[0]=create_stmt_node('bin_expr',p[2],p[1],p[3])
  else:
    p[0]=p[1]

def p_Factor_1(p):
  'factor : yNAME'
  p[0]=VariableNode(p[1])

def p_Factor_2(p):
  'factor : yNAME  oLB  expression  oRB'
  p[0]=ArrayMemberNode(p[1],[p[3]])  

def p_Factor_3(p):
  'factor : const_value'
  p[0]=p[1]

def p_Factor_4(p):
  'factor : oLP  expression  oRP'
  p[0]=p[2]

def p_Factor_5(p):
  '''factor : kNOT factor
            | oMINUS factor'''
  p[0]=create_stmt_node('sin_expr',p[1],p[2])

def p_Factor_6(p):
  'factor : yNAME oDOT yNAME'
  p[0]=RecordMemberNode(p[1],p[3])

def p_Factor_7(p):
  'factor : yNAME oLP args_list oRP'
  p[0]=create_stmt_node('fn',p[1],p[3])


def p_Args_list(p):
  '''args_list : args_list  oCOMMA  expression
               | expression'''
  if len(p)==4:
    p[0]=p[1]
    p[0].append(p[3])
  else:
    p[0]=FunctionArgsListNode(p[1])


def p_empty(p):
  'empty :'  


from lex_pas import log
parser=yacc.yacc(debug=True,debuglog=log)