import llvmlite.ir as ir
import llvmlite.binding as llvm
from backend.codegen import CodeGenerator,IParser
import argparse
import sys
from ctypes import CFUNCTYPE,c_double,c_int,c_void_p,cast,c_int32


arg_parser=argparse.ArgumentParser()
arg_parser.add_argument("input_file",help='specify the input file')
arg_parser.add_argument("-O","--optimization_level",type=int,help="specify the optimization level")
arg_parser.add_argument("-i","--ir_file",help="generate ir code")
arg_parser.add_argument("-m","--machinecode_file",help="generate machine code")
args=arg_parser.parse_args()

parser=IParser()
codestr=open(args.input_file,'r').read()
ast=parser.parse(codestr)
if not ast:
  sys.exit(0)
  
#exit()

llvm.initialize()
llvm.initialize_native_target()
llvm.initialize_native_asmprinter()

target=llvm.Target.from_default_triple()
codegen=CodeGenerator('Test')
codegen.generate_code(ast)
ir_code=str(codegen.module)
print 55*'-'
print ir_code
print 55*'-'
llvmmod=llvm.parse_assembly(str(codegen.module))

if args.ir_file:
  with open(args.ir_file,'w') as f:
    f.write(ir_code)
  