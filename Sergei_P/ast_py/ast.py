with open("result.txt") as f:
	c=f.read()
c=c.replace("\t"," ").split("+")
l=[]
for i in c:
	if i:
		x=i[1:-1].split(",")
		x[1]=int(x[1])
		j=x[2].find(":")
		if j<0:
			j=x[2].find("|")
		x[2]=tuple(x[2][j+1:].strip(" ").split(" ")) if x[1]!=-1 else None
		if '[' in x[0]:
			x[2]=x[0][x[0].find('['):][1:-1]
			x[0]=x[0][:x[0].find('[')]
		x+=[[] if x[1]!=-1 else None]
		l+=[x] #Node: Name, Length, Template / Value, Container

i=0

shadows=[]

while True:
	
	x=l[i]
	ln=x[1]
	if x[1]>0:
		shadows+=[' '.join([i[0] for i in l[:i+1]])]
		j=i
		while True:
			y=tuple([k[0] for k in l[j-ln:j]])
			if y==x[2]:
				break
			j-=1
		k=j-ln		
		l[i][3]=l[k:j]
		l[i][1]=0
		li=l.pop(i)
		l2=l[:k]
		l2.extend(l[j:])
		l=l2
		l.insert(k,li)
		i=0
		continue
	
	i=i+1
	if i>=len(l):
		break

shadows+=[' '.join([i[0] for i in l[:i+1]])]

def into(a,t=0):
	type_of='rule' if a[1]!=-1 else 'token'
	value_of='' if a[1]!=-1 or a[2]==None else a[2]
	yield (['<',a[0],' type="',type_of,'" value="',value_of,'">'],t)
	if a[3]:
		for i in a[3]:
			for k in into(i,t+1):
				yield k
	yield (['</',a[0],'>'],t)
	
a=into(l[0])

scheme=[]
for i in a:
	scheme+=[''.join(('\t'*i[1],''.join(i[0])))]

with open("ast.xml","w",encoding="utf-8") as f:
	f.write('\n'.join(scheme))
	
with open("steps.log","w",encoding="utf-8") as f:
	f.write('\n'.join(shadows))
