import llvmlite.ir as ir
import llvmlite.binding as llvm
import sys
from ctypes import CFUNCTYPE,c_double,c_int,c_void_p,cast,c_int32
sys.path.append('../')

#import sys, traceback
#import pdb

from frontend.AST import *
from utils import _Type_Boolean,_Type_Float,_Type_Int

class CodegenError(Exception):
  pass

class SymbleTable(object):
  def __init__(self):
    self.var_table={}
    self.fn_table={}
    self.scope_var={}
    self.scope_fn={}
    self.type_table={}
    self.scope_type={}
    self.const_table={}

  def add_const(self, const_name, const_val):
    self.const_table.setdefault(const_name, const_val)
    print "add_const ", const_name

  def add_var(self,var_name,addr,scope_id,var_type=None):
    self.var_table.setdefault(var_name,[]).append((addr,var_type))
    self.scope_var.setdefault(scope_id,[]).append(var_name)

  def add_fn(self,fn_name,fn_block,scope_id):
    self.fn_table.setdefault(fn_name,[]).append(fn_block)    
    self.scope_fn.setdefault(scope_id,[]).append(fn_name)

  def add_type(self,name,type_def,scope_id):
    self.type_table.setdefault(name,[]).append(type_def)
    self.scope_type.setdefault(scope_id,[]).append(name)

  def fetch_const(self,const_name):
    res = self.const_table.get(const_name, None)
    print "fetch_const ", const_name, res
    if res is None:
      raise CodegenError('Can not find const {0}'.format(const_name))
    else:
      return res

  def fetch_var_addr(self,var_name):
    o=self.var_table.get(var_name,None)
    if o:
      return o[-1][0]
    else:
      raise CodegenError('Can not find symble {0}'.format(var_name))

  def fetch_var_addr_type(self,var_name):
    o=self.var_table.get(var_name,None)
    if o:
      return o[-1]
    else:
      raise CodegenError('Can not find symble {0}'.format(var_name))

  def fetch_fn_block(self,fn_name):
    o=self.fn_table.get(fn_name,None)
    if o:
      return o[-1]
    else:
      raise CodegenError('Can not find function {0}'.format(fn_name))

  def fetch_type(self,type_name):
    o=self.type_table.get(type_name,None)
    if o:
      return o[-1]
    else:
      raise CodegenError('Can not find type {0}'.format(type_name))

  def remove_var(self,var_name):
    o=self.var_table.get(var_name,None)
    if o:
      del o[-1]
    else:
      raise CodegenError('Remove var {0} that not exsists!'.format(var_name))

  def remove_scope(self,scope_id):
    for name in self.scope_var.get(scope_id,[]):
      o=self.var_table.get(name,None)
      if o:
        del o[-1]
      else:
        raise CodeGenerator('Remove var {0} that not exsists!'.format(name))
    del self.scope_var[scope_id]
    scope_id+=1
    for name in self.scope_fn.get(scope_id,[]):
      o=self.fn_table.get(name,None)
      if o:
        del o[-1]
      else:
        raise CodeGenerator('Remove var {0} that not exsists!'.format(name))
    if self.scope_fn.has_key(scope_id):
      del self.scope_fn[scope_id]

def makeContant(t,value):
    print "makeContant :", t
    return ir.Constant(t,value)

class CodeGenerator(object):
  def __init__(self,code_name):
    self.module=ir.Module(code_name)
    self.builder=None
    self.sym_table=SymbleTable()

  #generate code for AST rooted as rt
  def generate_code(self,ast):
    print "Start passing AST"
    return self._codegen(ast,self.builder)

  def _codegen(self,astNode,builder):
    if astNode is None:
      return
    print "get node: ", astNode
    if isinstance(astNode,ListNode):
      print "It is list node"    
      attr = self._codegen_ListASTNode(astNode,builder)
      print "ListNode: ", attr
      return attr;
    method='_codegen_'+ astNode.__class__.__name__
    print "method : ", method
    #return getattr(self,method)(rt,builder)
    attr = getattr(self,method)(astNode,builder)
    print "*attr : ", attr
    return attr

  def _codegen_ProgramNode(self,node,builder):

    if node.routine:
      self._codegen(node.routine,builder)

      print "finish passing Ast"

  def _codegen_RoutineNode(self,node,builder):
    res=None
    tp=self._codegen(node.head,builder) if node.head else None
    res=tp if tp else res
    tp=self._codegen(node.body,builder) if node.body else None
    res=tp if tp else res
    return res

  def _codegen_RoutineHeadNode(self,node,builder):
    res=None
    tp=self._codegen(node.const_part,builder)   if node.const_part   else None
    res=tp if tp else res
    tp=self._codegen(node.type_part,builder)    if node.type_part    else None
    res=tp if tp else res
    tp=self._codegen(node.var_part,builder)     if node.var_part     else None
    res=tp if tp else res
    tp=self._codegen(node.routine_part,builder) if node.routine_part else None
    res=tp if tp else res
    return res

  def _codegen_ListASTNode(self,node,builder):
    res=None
    for v in node.node_list:
      tp=self._codegen(v,builder) if v else None
      res=tp if tp else res
    return res

  def _codegen_do_assign(self,lhs_var,rhs_val,builder):    
    return builder.store(rhs_val,lhs_var)

  #allocate address and add to symble table
  def _codegen_new_var(self,var,var_type,builder, init=None):
    #print "var : ", var, type(var)
    tp=var_type if isinstance(var_type,ir.Type) else self._helper_get_type(var_type)
    print "_codegen_new_var :", tp
    if CodeGenerator.scope_cnt == 0:
      #print "global : ", var
      addr = ir.GlobalVariable(self.module, tp, var)
      addr.linkage = "common"
      addr.align = 4
      if init is not None:
        addr.initializer = self._codegen_ConstValueNode(init,builder)
    else:
      with builder.goto_entry_block():
        #tp=var_type if isinstance(var_type,ir.Type) else self._helper_get_type(var_type)
        addr=builder.alloca(tp,name=var)
        if init is not None:
          initializer = self._codegen_ConstValueNode(init,builder)
          builder.store(initializer,addr)
        #self.sym_table.add_var(var,addr,CodeGenerator.scope_cnt,tp)
    self.sym_table.add_var(var,addr,CodeGenerator.scope_cnt,tp)
    return addr

  def _codegen_type_cast(x,target_type,builder):
    if target_type==_Type_Float:
      builder.sitofp(x,ir.DoubleType())
    else:
      builder.zext(x,CodeGenerator._Type_precedence_list[target_type])

  def _codegen_ConstExprNode(self,node,builder):
    # assert(isinstance(node.var,VariableNode),"ConstExprNode.var should be VariableNode")
    lhs_var=self._codegen_new_var(node.var,builder,node.const_value.type)
    rhs_val=self._codegen(node.const_value,builder)
    return self._codegen_do_assign(lhs_var,rhs_val,builder)
  
  def _codegen_ConstValueNode(self,node,builder):
    print "node : ", node
    return makeContant(self._helper_get_type(node.type),node.value)
  
  def _codegen_ArrayTypeNode(self,node,builder):
    array_range=node.bound
    lb=array_range.rb[0].value
    rb=array_range.rb[1].value
    array_len=rb-lb+1
    ele_type=self._helper_get_type(node.type_name.type_name)
    res=ir.ArrayType(ele_type,array_len)
    setattr(res,'_lb',lb)
    setattr(res,'_rb',rb)
    #traceback.print_stack()
    #print res
    return res

  def _codegen_VariableNode(self,node,builder):
    var_addr=self.sym_table.fetch_var_addr(node.name)
    return builder.load(var_addr,node.name)

  def _codegen_RecordTypeNode(self,node,builder):
    print "_codegen_RecordTypeNode ", node
    #print "field_decl_list : ", node.field_decl_list
    #print "node_list : ",node.field_decl_list.node_list[0].type
    members = []
    pos = 0
    for vardecl in node.field_decl_list.node_list:
      t = self._helper_get_type(vardecl.type.type_name)
      members.append(t)
      self.sym_table.add_const(vardecl.var_name, pos)
      pos += 1
      print "_codegen_RecordTypeNode : ", t, " | ",  vardecl.var_name#, " | ", vardecl.pos
      #print vardecl

    res = ir.LiteralStructType(members)
    return res

  def _codegen_ArrayMemberNode(self,node,builder):
    var_addr,var_type=self.sym_table.fetch_var_addr_type(node.var_name)
    # index=node.indices[0].value
    index=[]
    for i in node.indices:
      if isinstance(i,VariableNode):
        val=self._codegen(i,builder)
      else:
        val=makeContant(ir.IntType(32),i.value)
      index.append(val)
    indices=index
    # indices=[makeContant(ir.IntType(32),index),makeContant(ir.IntType(32),0)]
    indices.append(makeContant(ir.IntType(32),0))
    addr=builder.gep(var_addr,indices)
    return builder.load(addr,"arraymember")

  def _codegen_ArrayMemberLhsNode(self,node,builder):
    var_addr,var_type=self.sym_table.fetch_var_addr_type(node.var_name)
    print var_type, var_addr
    # index=node.indices[0].value
    index=[]
    print "_codegen_ArrayMemberLhsNode ", node.indices
    for i in node.indices:
      print "indices ", i
      if isinstance(i,VariableNode):
        val=self._codegen(i,builder)
      else:
        val=makeContant(ir.IntType(32),i.value)
      index.append(val)
    indices=index
    # indices=[makeContant(ir.IntType(32),index),makeContant(ir.IntType(32),0)]
    indices.append(makeContant(ir.IntType(32),0))
    print "indices ", indices
    # return builder.gep(var_addr,indices)
    return builder.gep(var_addr,indices)


  def _codegen_RecordMemberNode(self,node,builder):
    var_addr,var_type=self.sym_table.fetch_var_addr_type(node.var_name)
    print "_codegen_RecordMemberLoad"
    print var_addr
    print var_type
    print node, " | " , node.var_name, " | " , node.field_name
    pos = self.sym_table.fetch_const(node.field_name)
    index = makeContant(ir.IntType(32),0)
    indices = [index]
    indices.append(makeContant(ir.IntType(32),pos))
    print "indices ", indices
    addr=builder.gep(var_addr,indices)
    return builder.load(addr,"recordmember")


  def _codegen_RecordMemberLhsNode(self,node,builder):
    var_addr,var_type=self.sym_table.fetch_var_addr_type(node.var_name)
    print "_codegen_RecordMemberLhsNode"
    print var_addr
    print var_type
    print node, " | " , node.var_name, " | " , node.field_name
    pos = self.sym_table.fetch_const(node.field_name)
    index = makeContant(ir.IntType(32),0)
    indices = [index]
    indices.append(makeContant(ir.IntType(32),pos))
    print "indices ", indices
    return builder.gep(var_addr,indices)   

  def _codegen_TypeDefinitionNode(self,node,builder):
    # raise CodegenError('not implemented')
    var_name=node.name
    var_type=self._codegen(node.type,builder)
    self.sym_table.add_type(var_name,var_type,CodeGenerator.scope_cnt)

  def _codegen_VarDeclNode(self,node,builder):
    #var_type=self._helper_get_type(node.type.type_name)
    res=None
    init = node.init
    #for var in node.name_list.node_list:
    var = node.name_var
    if isinstance(node.type,VariableTypeNode):
      tp=self.sym_table.fetch_type(node.type.typename)
      tp=self._codegen_new_var(var,tp,builder, init)
    else:
      tp=self._codegen_new_var(var,node.type.type_name,builder, init)
    res=tp if tp else res
    return res

  def __codegen_FunctionDecl(self,node,builder,gen_type):
    CodeGenerator.scope_cnt+=1
    fn_params_name,fn_params_type=[],[]
    fn_return_type_l=[]
    proto=self.__codegen_FunctionPrototype(node.prototype,builder,fn_params_type,fn_params_name,fn_return_type_l,gen_type)
    fn_name=node.prototype.name

    self.sym_table.add_fn(fn_name,proto,CodeGenerator.scope_cnt)

    bb_entry=proto.append_basic_block('entry')
    newBuilder=ir.IRBuilder(bb_entry)
    for i,arg in enumerate(proto.args):
      arg.name=fn_params_name[i]
      addr=self._codegen_new_var(arg.name,fn_params_type[i],newBuilder)
      newBuilder.store(arg,addr)

    fn_return_type=fn_return_type_l[0]
    return_addr=self._codegen_new_var(fn_name,fn_return_type,newBuilder)

    res=self._codegen(node.body,newBuilder)
    if gen_type=='fun':
      return_val=newBuilder.load(return_addr,fn_name)
      newBuilder.ret(return_val)
    else:
      newBuilder.ret_void()

    self.sym_table.remove_scope(CodeGenerator.scope_cnt)

    CodeGenerator.scope_cnt-=1
    return proto

  def __codegen_FunctionPrototype(self,proto,builder,fn_params_type,fn_params_name,fn_return_type_l,gen_type):
    fn_name=proto.name
    fn_return_type=self._helper_get_type(proto.return_type.type_name if gen_type == 'fun' else 'void')
    if proto.params:
      for para_type_list in proto.params.node_list:
        tp=self._helper_get_type(para_type_list.type.type_name)
        fn_params_type+=[tp]*len(para_type_list.var_list)
        fn_params_name+=para_type_list.var_list

    fn_type=ir.FunctionType(fn_return_type,fn_params_type)
    func=ir.Function(self.module,fn_type,fn_name)
    fn_return_type_l.append(fn_return_type)    
    return func

  scope_cnt=0

  def _codegen_FunctionDeclNode(self,node,builder):
    return self.__codegen_FunctionDecl(node,builder,'fun')
  
  # class CallExpr(ExprNode):
  # def __init__(self,callee,args):
  #   self.callee=callee
  #   self.args=args

  def _codegen_CallExpr(self,node,builder):
    callee_func=self.sym_table.fetch_fn_block(node.callee)
    call_args=[self._codegen(arg,builder) for arg in node.args.node_list]
    return builder.call(callee_func,call_args,'call_fn')

  # = >= > <= < = + - or * div mod and
  def _codegen_BinaryExpr(self,node,builder):
    if node.op == ':=':
      if isinstance(node.lhs,ArrayMemberNode):
        lhs_val=self._codegen_ArrayMemberLhsNode(node.lhs,builder)
        rhs_val=self._codegen(node.rhs,builder)
        self._codegen_do_assign(lhs_val,rhs_val,builder)
        return rhs_val
      if isinstance(node.lhs,RecordMemberNode):
        #return
        print "@RecordMemberNode ", RecordMemberNode
        lhs_val=self._codegen_RecordMemberLhsNode(node.lhs,builder)
        rhs_val=self._codegen(node.rhs,builder)
        self._codegen_do_assign(lhs_val,rhs_val,builder)
        return rhs_val
      else:
        assert(isinstance(node.lhs,VariableNode))
        var_addr=self.sym_table.fetch_var_addr(node.lhs.name)
        rhs_val=self._codegen(node.rhs,builder)
        # if isinstance(node.rhs,ArrayMemberNode):
        #   rhs_val=builder.load(rhs_val,"array_member_value")
        self._codegen_do_assign(var_addr,rhs_val,builder)
        return rhs_val

    lhs=self._codegen(node.lhs,builder)
    rhs=self._codegen(node.rhs,builder)
    lhs_type=self._helper_parse_type_to_id(node.lhs)
    rhs_type=self._helper_parse_type_to_id(node.rhs)
    if lhs_type>rhs_type:
      self._codegen_type_cast(rhs,lhs_type,builder)
    elif lhs_type<rhs_type:
      self._codegen_type_cast(lhs,rhs_type,builder)
    node.type=max(lhs_type,rhs_type)

    op=node.op
    op='==' if op == '=' else op    
    if op in ('==','>=','>','<=','<'):
      if node.type == _Type_Float:
        return builder.fcmp_ordered(op,lhs,rhs)
      else:
        return builder.icmp_signed(op,lhs,rhs)
    elif op == '+':
      if node.type == _Type_Float:
        return builder.fadd(lhs,rhs,name='float_add')
      else:
        return builder.add(lhs,rhs,name='integer_add')
    elif op == '-':
      if node.type == _Type_Float:        
        return builder.fsub(lhs,rhs,name='floag_sub')
      else:
        return builder.sub(lhs,rhs,name='integer_sub')
    elif op == 'or':
      if node.type == _Type_Float:
        raise CodegenError('Floating-point number or operation')
      else:
        return builder.or_(lhs,rhs,name='integer_or')
    elif op in ('*','mul'):
      if node.type == _Type_Float:
        return builder.fmul(lhs,rhs,name='float_mul')
      else:
        return builder.mul(lhs,rhs,name='integer_mul')
    elif op == 'div':
      if node.type == _Type_Float:
        return builder.fdiv(lhs,rhs,name='float_div')
      else:
        return builder.sdiv(lhs,rhs,name='integer_div')
    elif op == 'mod':
      if node.type == _Type_Float:
        return builder.frem(lhs,rhs,name='float_mod')
      else:
        return builder.srem(lhs,rhs,name='integer_mod')
    elif op == 'and':
      if node.type == _Type_Float:
        raise CodegenError('Floating-point number or operation')
      else:
        return builder.and_(lhs,rhs,name='integer_and')
    else:
      raise CodegenError('invalid bin_expr operator')

  # class IfExpr(ExprNode):
  #   def __init__(self,cond_expr,then_expr,else_expr):
  #     self.cond_expr=cond_expr
  #     self.then_expr=then_expr
  #     self.else_expr=else_expr

  def _codegen_IfExpr(self,node,builder):
    cond_val=self._codegen(node.cond_expr,builder)
    cond_expr_type=self._helper_parse_type_to_id(node.cond_expr.type)    
    cmp_res=builder.icmp_signed('!=',cond_val,makeContant(ir.IntType(1),0))

    then_bb=builder.function.append_basic_block('then_bb')
    else_bb=builder.function.append_basic_block('else_bb')
    merge_bb=builder.function.append_basic_block('merge_bb')
    builder.cbranch(cmp_res,then_bb,else_bb)

    builder.position_at_start(then_bb)
    then_val=self._codegen(node.then_expr,builder)
    builder.branch(merge_bb)

    then_bb=builder.block
    # builder.function.basic_blocks.append(else_bb)
    builder.position_at_start(else_bb)
    else_val=self._codegen(node.else_expr,builder)
    else_bb=builder.block
    builder.branch(merge_bb)

    # builder.function.basic_blocks.append(merge_bb)
    builder.position_at_start(merge_bb)

  def _helper_gen_cmp_code(self,var_name,addr,target_val,step_dir,addit,builder):
    cur_val=builder.load(addr,var_name)
    if addit:
      step_val=self._codegen(step_dir,builder)
      cur_val=builder.add(cur_val,step_val)
      self._codegen_do_assign(addr,cur_val,builder)
    if step_dir>0:      
      return builder.icmp_signed('<=',cur_val,target_val)
    else:
      return builder.icmp_signed('>=',cur_val,target_val)

  def _codegen_ForExpr(self,node,builder):
    var_addr=self._codegen_new_var(node.id_name,ir.IntType(32),builder)
    start_val=self._codegen(node.start_expr,builder)
    self._codegen_do_assign(var_addr,start_val,builder)
    # print "node.dir",node.dir.value
    # import sys
    # sys.exit(0)
    end_val=self._codegen(node.end_expr,builder)
    cmp_res=self._helper_gen_cmp_code(node.id_name,var_addr,end_val,node.dir,0,builder)

    loop_bb=builder.append_basic_block('loop')
    after_bb=builder.append_basic_block('after_bb')
    builder.cbranch(cmp_res,loop_bb,after_bb)
    
    builder.position_at_start(loop_bb)
    res=self._codegen(node.body,builder)
    end_val=self._codegen(node.end_expr,builder)
    cmp_res=self._helper_gen_cmp_code(node.id_name,var_addr,end_val,node.dir,1,builder)
    builder.cbranch(cmp_res,loop_bb,after_bb)

    builder.position_at_start(after_bb)
    return res

  def _codegen_WhileExpr(self,node,builder):
    end_expr_val=self._codegen(node.cond_expr,builder)
    cmp_res=builder.icmp_signed('!=',end_expr_val,makeContant(ir.IntType(1),0))

    loop_bb=builder.function.append_basic_block('loop')
    after_bb=builder.function.append_basic_block('after_loop')
    builder.cbranch(cmp_res,loop_bb,after_bb)
    
    builder.position_at_start(loop_bb)
    body_val=self._codegen(node.body,builder)

    end_expr_val=self._codegen(node.cond_expr,builder)
    cmp_res=builder.icmp_signed('!=',end_expr_val,makeContant(ir.IntType(1),0))
    builder.cbranch(cmp_res,loop_bb,after_bb)    
    
    builder.position_at_start(after_bb)

  def _helper_get_type(self,t):
    if isinstance(t,TypeNode):
      return t
    if t in ('int','integer'):
      return ir.IntType(32)
    elif t in ('real'):
      return ir.DoubleType()
    elif t in ('boolean'):
      return ir.IntType(1)
    elif t in ('void'):
      return ir.VoidType()
    else:
      raise CodegenError('invalid type name')

  def _helper_parse_type_to_id(self,t):
    if isinstance(t,CallExpr):
      return self.sym_table.fetch_fn_block(t.callee).function_type.return_type
    if type(t)==int:
      return t
    t=t.type
    if type(t)==int:
      return t
    if t in ('int','integer'):
      return _Type_Int
    elif t in ('real'):
      return _Type_Float
    elif t in ('boolean'):
      return _Type_Boolean
    else:
      raise Exception('invalid type name')

  _Type_precedence_list=[ir.IntType(1),ir.IntType(8),ir.IntType(32),ir.DoubleType()]  
  def _helper_cast_to_same_type(a,b):
    raise CodeGenerator('not implemented')


from frontend.yacc_pas import parser,error_list

class IParser(object):
  def __init__(self):
    self.parser=parser    
  
  def parse(self,codestr,_debug=0):
    self.input=codestr
    ast=parser.parse(codestr,debug=_debug,tracking=1)
    if len(error_list)==0:
      return ast
    for e in error_list:
      print 'syntax error in line %d at %d expected " %s " got " %s "'%(e[0],self.find_column(e[1]),e[2],e[3])      
    return None

  def find_column(self,pos):
    last_cr=self.input.rfind('\n',0,pos)
    if last_cr<0:
      last_cr=0
    return pos-last_cr+1    

if __name__ == '__main__':
  def init():
    llvm.initialize()
    llvm.initialize_native_target()
    llvm.initialize_native_asmprinter()

  def evaluate(codestr,codegen,target):
    my_parser=IParser()
    ast=my_parser.parse(codestr,1)
    # ast=parser.parse(codestr,debug=1,tracking=1)
    if not ast:
      return

    # ast.travle()
    # sys.exit(0)
    codegen.generate_code(ast)
    print "====================IR===================="
    print str(codegen.module)
    print "====================IR===================="

    llvmmod=llvm.parse_assembly(str(codegen.module))
    # sys.exit(0)   

  init()

  codegen=CodeGenerator('Test')
  codestr=open(sys.argv[1],'r').read()  

  print >>sys.stderr,codestr
  target=llvm.Target.from_default_triple()

  evaluate(codestr,codegen,target)
