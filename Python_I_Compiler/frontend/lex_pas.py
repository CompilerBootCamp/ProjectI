import ply.lex as lex
import re
from ply.lex import TOKEN

#SYS_FUNCT SYS_PROC SYS_CON SYS_TYPE
rsv_sys_con=["false","true"]
rsv_sys_type=["boolean","integer","real"]
rsv_other=["and","array","else","end","for","routine","if","in",
            "mod","not","of","or","read","record","then",
           "type","var","while",'div', 'is', 'loop']

reserved={}
reserved_type={}

for w in rsv_sys_con:
  reserved[w]='SYS_CON'
  # reserved_type[w]='c'+w.upper()
  reserved_type[w]='cSYS_CON'

for w in rsv_sys_type:
  reserved[w]='SYS_TYPE'
  # reserved_type[w]='c'+w.upper()
  reserved_type[w]='c'+'SYS_TYPE'

for w in rsv_other:
  reserved[w]='k'+w.upper()
  reserved_type[w]='k'+w.upper()

tokens=(
  'cINTEGER','cREAL','oLP','oRP','oLB','oRB','oPLUS','oMINUS',
  'oMUL','oDIV','oASSIGN','oEQUAL','oLT','oGT','oLE','oGE','oCOMMA','oSEMI',
  'oCOLON','oQUOTE','oDOTDOT','oDOT','yNAME'
)
tokens+=tuple(list(set(reserved_type.values())))

letter=r"[a-zA-Z_]"
alnum=r"[_a-zA-Z0-9]"
dec=r"[0-9]"
hex=r"[0-9a-fA-F]"
oct=r"[0-7]"

def t_error(t):
    print("Illegal character '%s'" % t.value[0])    
    t.lexer.skip(1)

t_ignore=' \t\x0c'

def t_newline(t):
  r'\n+'
  t.lexer.lineno+=len(t.value)

#c_INTEGER
@TOKEN(r"(\-)*[0-9]+")
def t_cINTEGER_10(t):
  t.value=int(t.value,10)
  t.type='cINTEGER'
  return t

#@TOKEN(dec+r'+(\.'+dec+r'+)?([E|e][+\-]?'+dec+r'+)?')
@TOKEN(r"(\-)*[0-9]+\.[0-9]+")
def t_cREAL(t):
  return t

t_oLP=re.escape("(")
t_oRP=re.escape(")")
# t_oLB=re.escape('[')
t_oLB='\['
t_oRB=re.escape("]")
t_oPLUS=re.escape(r'+')
t_oMINUS=re.escape(r'-')
t_oMUL=r'\*|MUL'
t_oDIV=r'div'
t_oASSIGN=re.escape(r':=')
t_oEQUAL=re.escape(r'=')
t_oLT=re.escape(r'<')
t_oGT=re.escape(r'>')
t_oLE=re.escape(r'<=')
t_oGE=re.escape(r'>=')
t_oCOMMA=re.escape(r',')
t_oSEMI=re.escape(r';')
t_oCOLON=re.escape(r':')
t_oDOTDOT=re.escape(r'..')
t_oDOT=re.escape(r'.')


@TOKEN(letter+alnum+r'*')
def t_ID_or_KEYWORD(t):  
  if reserved.has_key(t.value):
    t.type=reserved_type[t.value]
    return t
  t.type='yNAME'
  return t

import logging
logging.basicConfig(
  level = logging.DEBUG,
  filename = "parselog.txt",
  filemode = "w",
  format = "%(filename)10s:%(lineno)4d:%(message)s"
)
log=logging.getLogger()
lex.lex(debug=True,debuglog=log)

if __name__ == '__main__':
  import sys
  lexer=lex.lex(debug=1,debuglog=log)
  while True:
    # s=raw_input('>>')
    s=open(sys.argv[1],'r').read()
    lexer.input(s)
    while True:
      tok=lexer.token()
      if not tok:
        break
      print tok
    break

