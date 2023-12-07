# part 1, 82 characters
import re
print(sum(map(int,[(x:=re.findall('\d',a))[0]+x[-1]for a in open('f')])))

# part 2, 254 characters
a=0
for s in open('f'):
	f,l=0,0
	for i in range(len(s)):
		if s[i].isdigit():
			if f==0:f=int(s[i])
			l=int(s[i])
		for v,n in enumerate('one two three four five six seven eight nine'.split(),1):
			if s[i:i+len(n)]==n:
				if f==0:f=v
				l=v
	a+=f*10+l
print(a)