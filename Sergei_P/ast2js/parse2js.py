from ast import run_ast; run_ast()
import xml.etree.ElementTree as ET; root = ET.parse('test.xml').getroot()

def params(p):
	for i in p:
		if i.tag=="Parameters":
			for j in params(i):
				yield j
		elif i.tag=="ParameterDeclaration":
			yield i[0].attrib['value']

def workout(i):
	return i

watch=False
w_g=[]

def modme(p):
	global watch
	global w_g
	l=[]
	for i in p:		
		if i.tag=="IDENT":
			l+=[i.attrib['value']]			
			if watch: w_g+=[workout(i)]
		elif i.tag=="POINT":
			l+=["."]
			if watch: w_g+=[workout(i)]
		elif i.tag=="ModifiableSecondary":
			l.extend(modme(i))
		elif i.tag=="LBRACKET":
			l+=["["]
			if watch: w_g+=[workout(i)]
		elif i.tag=="RBRACKET":
			l+=["]"]
			if watch: w_g+=[workout(i)]			
		elif i.tag=="Expression":
			w2=watch
			watch=False
			t=expression(i)
			watch=w2
			l.extend(t)
			if watch: w_g+=[(None,''.join(t))]
	return l

def preinit():
	parse=[]
	allin=[]
	for i in w_g:
		if len(i)>1:
			parse+=[i[1]]
		elif i.tag=="IDENT":
			parse+=[i.attrib['value']]
		elif i.tag=="POINT":
			allin+=[''.join(parse)]
			parse+=["."]
		elif i.tag=="LBRACKET":
			allin+=[''.join(parse)]
			parse+=["["]
		elif i.tag=="RBRACKET":
			parse+=["]"]
	return ["@=(@===undefined?{}:@);".replace("@",i) for i in allin]

def callme(p):
	global watch
	global w_g
	l=[]
	for i in p:
		if i.tag=="TERMINAL":
			l+=["\n"]
		elif i.tag=="IDENT":
			l+=[i.attrib['value']]
		elif i.tag=="ASSIGN":
			watch=False
			l+=["="]
		elif i.tag=="SimpleDeclaration":
			test=special(i[0])
			if test and test!=1:
				l.extend(test)
		elif i.tag=="Body" or i.tag=="Expressions" or i.tag=="Statement" or i.tag=="RoutineCall" or i.tag=="WhileLoop" or i.tag=="ForLoop" or i.tag=="IfStatement":
			l.extend(callme(i))
		elif i.tag=="Assignment":
			watch=True
			w_g=[]
			l.extend(callme(i))
			l=preinit()+l
			w_g=[]
		elif i.tag=="ModifiablePrimary":
			l.extend(modme(i))
		elif i.tag=="Expression":
			l.extend(expression(i))
		elif i.tag=="LPAREN":
			l+=["("]
		elif i.tag=="RPAREN":
			l+=[")"]
		elif i.tag=="COMMA":
			l+=[","]
		elif i.tag=="WHILE_TOKEN":
			l+=["while"]
		elif i.tag=="FOR_TOKEN":
			l+=["for"]
		elif i.tag=="LOOP_TOKEN" or i.tag=="THEN_TOKEN":
			l+=["{\n"]
		elif i.tag=="END_TOKEN":
			l+=["}\n"]
		elif i.tag=="Range":
			r=["var ",l[-1],"="]
			x=[]
			reverse=False
			for d in i:
				if d.tag=="Expression":			
					x+=[expression(d)]
				elif d.tag=="REVERSE_TOKEN":
					reverse=True
			r.extend(x[0])
			r.extend([";",l[-1],">" if reverse else "<","="])
			r.extend(x[1])
			r.extend([";",l[-1],"--" if reverse else "++",")"])
			l[-1]="("
			l.extend(r)
		elif i.tag=="IF_TOKEN":
			l+=["if"]
		elif i.tag=="ELSE_TOKEN":
			l+=["}{\n"]
	return l

def expression(p,brackets=False):
	l=[]
	if p.tag=="Relation" or p.tag=="Expression":
		brackets=True
	if brackets:
		l+=["("]
	for i in p:
		if i.tag=="AND_TOKEN":
			l+=[" && "]
		elif i.tag=="OR_TOKEN":
			l+=[" || "]
		elif i.tag=="XOR_TOKEN":
			l+=["^"]
		elif i.tag=="LESS":
			l+=["<"]
		elif i.tag=="MORE":
			l+=[">"]
		elif i.tag=="MORE_OR_EQ":
			l+=[">="]
		elif i.tag=="LESS_OR_EQ":
			l+=["<="]
		elif i.tag=="EQ":
			l+=["=="]
		elif i.tag=="NOT_EQ":
			l+=["!="]
		elif i.tag=="MULTIPLY":
			l+=["*"]
		elif i.tag=="DIVIDE":
			l+=["/"]
		elif i.tag=="MOD":
			l+=["%"]
		elif i.tag=="MINUS":
			l+=["-"]
		elif i.tag=="PLUS":
			l+=["+"]
		elif i.tag=="Logical" or i.tag=="Correlation" or i.tag=="FactorSign" or i.tag=="Sign":
			l.extend(expression(i))
		elif i.tag=="Relation" or i.tag=="Simple" or i.tag=="Factor" or i.tag=="Summand" or i.tag=="Primary" or i.tag=="Expression":
			l.extend(expression(i))
		elif i.tag=="LPAREN":
			l+=["("]
		elif i.tag=="RPAREN":
			l+=[")"]
		elif i.tag=="INT_LITERAL" or i.tag=="REAL_LITERAL":
			l+=[i.attrib['value']]
		elif i.tag=="TRUE_TOKEN":
			l+=["true"]
		elif i.tag=="FALSE_TOKEN":
			l+=["false"]
		elif i.tag=="ModifiablePrimary":
			l.extend(modme(i))
		elif i.tag=="RoutineCall":
			l.extend(callme(i))
	if brackets:
		l+=[")"]
	return l

def special(e):
	if e.tag=="RoutineDeclaration":
		Body,Name,Parameters=[],None,[]
		for i in e:
			if i.tag=="Body":
				Body=callme(i)
			elif i.tag=="Parameters":
				Parameters=list(params(i))
			elif i.tag=="IDENT":
				Name=i.attrib['value']
		result=["function ",Name,"(",','.join(Parameters),"){ var ",Name,"=undefined\n"]
		result.extend(Body)
		result+=["return ",Name,";}\n"]
		return result
	elif e.tag=="Type":
		return 1
	elif e.tag=="VariableDeclaration":
		Name,Value=None,None
		for i in e:
			if i.tag=="IDENT":
				Name=i.attrib['value']
			elif i.tag=="Expression":
				Value=''.join(expression(i))
		return ["var ",Name,"=","{}" if Value==None else Value,";"]
	return False

js=[]

def t(r):
	global js
	for e in r:
		yield e.tag
		test=special(e)
		if not test:
			for i in t(e):
				yield i
		else:
			if test!=1:
				js.extend(test)
				js+=["\n"]







for i in t(root): pass
with open("result.js","w",encoding="utf-8") as f:
	f.write(''.join(js))
