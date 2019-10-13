import ctypes
import os

s="unite.so"
Lib=ctypes.CDLL(os.path.abspath(s))

fin = os.path.abspath("test.i")
fou = os.path.abspath("test3.xml")

p1, p2 = [i.encode() for i in (fin,fou)]

s=Lib.parse_c(ctypes.c_char_p(p1),ctypes.c_char_p(p2))
