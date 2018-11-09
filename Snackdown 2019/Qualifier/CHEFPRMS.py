import math
from collections import Counter
def checkSemiprime(num):
    	cnt = 0
    	for i in range(2, int(math.sqrt(num)) + 1): 
        	while num % i == 0: 
            		num /= i 
            		if num==i:
            			cnt+=3
            		cnt += 1  
        	if cnt >= 2:  
            		break
    	if(num > 1): 
        	cnt += 1 
    	return cnt == 2
t=int(input())
while t>0:
	n=int(input())
	l=[]
	for i in range(2,n):
		if checkSemiprime(i):
			l.append(i)
	c=Counter(l)
	flag=0
	for i in l:
		if n-i in c:
			print("YES")
			flag=1
			break
	if flag==0:
		print("NO")
	t-=1
		
	

