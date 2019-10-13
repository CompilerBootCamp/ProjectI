import ctypes
from platform import system as platform
import os

name=''.join(("tst",".dll" if platform().lower()=="windows" else ".so" ))
dll=ctypes.CDLL(os.path.abspath(name))

i1=ctypes.c_int(3)
i2=ctypes.c_int(4)
f1=ctypes.c_float(2.8)
f2=ctypes.c_float(7.6)

dll.operatorPlusFloatFloat.restype = ctypes.c_float
dll.operatorPlusIntFloat.restype = ctypes.c_float
dll.operatorPlusFloatInt.restype = ctypes.c_float

a=dll.operatorPlusIntInt(i1,i2)
b=dll.operatorPlusIntFloat(i1,f2)
c=dll.operatorPlusFloatInt(f1,i2)
d=dll.operatorPlusFloatFloat(f1,f2)

print (a, 3 + 4,     sep="\t\t"*2)
print (b, 3 + 7.6,   sep="\t\t")
print (c, 2.8 + 4,   sep="\t\t")
print (d, 2.8 + 7.6, sep="\t\t")
