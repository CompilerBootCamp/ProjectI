def call(c,isfile=False):

	cmd="""
	
	rm -rf ./unite
	bison -vd parser.y
	flex scanner.l
	gcc -o unite parser.tab.c lex.yy.c -lfl 2> gcc.txt
	./unite < test.i > result.txt
	cat result.txt

	"""
	
	with open ("cmd.sh","w",encoding="utf-8") as f:
		f.write(cmd.replace("\t",""))
	
	cmd=cmd.split("\n")

	def split1(a,sym):
		i=a.find(sym)
		return [a[:i],a[i+1:]] if i>=0 else [a]
	if isfile:
		with open (c,encoding="utf-8") as f:
			c=f.readlines()
	else:
		c=c.split("\n")

	parts=[[],[],[],[],[],[],[],[]] # scanner, pre-scanner, post-scanner, lexer tokens, lexer rules, pre-lexer, post-lexer, test
	tokens=[]
	index=-1
	current_branch=""
	current_rule=""
	current_point=0
	meta_symbol="%"
	
	y=lambda x:''.join((meta_symbol,x,meta_symbol))
	z=lambda x:''.join(('{',x,'}'))

	for i in c:
		i=i.strip("\n")
		if i:
			if i.startswith("~") and i.endswith("~"):
				if index==1 and current_rule:
					for n,j in enumerate(parts[index]):
						if not j[1]:
							parts[index][n][1]=current_rule
				current_branch=""
				current_rule=""
				current_point=0
				if index==0:
					if parts[index] and parts[index][-1]!=";":
						parts[index]+=[";"]
				i=i.strip("~ \t")
				if i.startswith("META"):
					meta_symbol=i[4:][1:2]
				elif i=="GRAMMAR":
					index=0
				elif i=="RULES":	
					index=1
				elif i=="TOKENS":
					index=2
				elif i=="PRELEX":
					index=3
				elif i=="POSTLEX":
					index=4
				elif i=="PRE":
					index=5
				elif i=="POST":
					index=6
				elif i=="TEST":
					index=7
				elif i=="END":
					break
				elif i=="REM":
					index=-1
			else:
				if index<0:
					continue
				elif index>=2:				
					if index==2:
						n=i.replace("\t"," ").find(" ")
						s=i[:n]
						if s!=s.lower():
							tokens+=[s.title()]
							parts[1]+=[[tokens[-1],""]]
							i=''.join((i[:n].title(),i[n:]))
					parts[index]+=[i]
				elif index==1:
					i=split1(i,"#")
					i[0]=i[0].strip(" \t")
					if len(i)<=1:
						if i[0]=="\\" and tokens:
							i[0]=tokens[-1]
						seeker=list(filter(lambda x:x[0]==i[0],parts[index]))
						if seeker:
							current_point=parts[index].index(seeker[0])+1
					else:
						if not i[0]:
							current_rule=i[1]
						else:
							i[1]=''.join((i[1],current_rule))
							seeker=list(filter(lambda x:x[0]==i[0].title(),parts[index]))
							if seeker:
								parts[index][parts[index].index(seeker[0])][1]=i[1]
							else:
								parts[index].insert(current_point,[i[0],i[1]])
								current_point+=1
				elif index==0:
					i=split1(i,"#")
					if ":" in i[0]:
						current_branch=i[0][:i[0].find(":")].strip(" \t")
						if parts[index] and parts[index][-1]!=";":
							parts[index]+=[";"]
					code=""
					if len(i)>1:
						code=i[1]
						if not i[0]:
							current_rule=i[1]
					if i[0]:
						total_code=''.join((code,current_rule))						
						if meta_symbol:
							pure_rule=i[0].strip(" \t")
							pure_ind=pure_rule.find(":")
							if pure_ind<0:
								pure_ind=pure_rule.find("|")
							if pure_ind<0:
								pure_ind=0
							pure_rule=pure_rule[pure_ind:]
							meta_len=pure_rule.count(" ")
							total_code=total_code.replace(y("RULE"),current_branch).replace(y("BRANCH"),i[0]).replace(y("LENGTH"),str(meta_len))
						i[0]=''.join((i[0],z(total_code)))
						parts[index]+=[i[0]]

	if not meta_symbol:
		meta_symbol="%"	
	Token_replace,Rule_replace=y("TOKEN"),y("RULE")
	for n,j in enumerate(parts[1]):
		parts[1][n][1]=j[1].replace(Token_replace,j[0].upper()).replace(Rule_replace,j[0])

	scanner=["%{",'#include "parser.tab.h"']
	scanner.extend(parts[3])
	scanner+=["%}"]
	scanner.extend(parts[2])
	scanner+=["%%"]
	for i,j in parts[1]:
		if i in tokens:
			i=z(i)
		scanner+=[''.join((i,"\t",z(j)))]
	scanner.extend(["%%","int yywrap(){return 1;}"])
	scanner.extend(parts[4])

	parser=["%{"]
	parser.extend(parts[5])
	parser.extend(["%}",''.join(('%token ',' '.join([i.upper() for i in tokens]))),"%start Program","%%"])
	parser.extend(parts[0])
	parser+=["%%"]
	parser.extend(parts[6])

	tester=parts[7]

	for fn,entity in [("parser.y",parser),("scanner.l",scanner),("test.i",tester)]:
		with open(fn,"w",encoding="utf-8") as f:
			f.write('\n'.join(entity))

	from os import system

	for c in cmd:
		if c:
			system(c)
