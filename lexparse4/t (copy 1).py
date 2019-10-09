with open("result.txt") as f:
	c=f.read()

c=c.replace(" : ",":").replace(" <","<").split(" ")

l=[]
for i in c:
	if i:
		i=i.split(":")
		if len(i)<2:
			i=[i[0],-1,[]]
		else:
			i=[i[0].strip("<"),int(i[1].strip(">")),[]]
		l+=[i]

c=0
while True:
	
	i=l[c]
	if i[1]>0:						
		#print(i[0],i[1],len(i[2]),end=" - ")
		i[2].insert(0,l.pop(c-1))
		i[1]-=1
		#print(i[0],i[1],len(i[2]))
		#input()
		c-=1
		if i[1]==0:
			c=0
		continue
	c=c+1
	if c>=len(l):
		break


for i in l:
	print(i)
exit()
a=[1,2,3,4,5,6]
x=2
y=5

b=a[x:y]
a=a[:x]+a[y:]

print(a,b)
