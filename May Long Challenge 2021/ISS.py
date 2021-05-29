def solve(y,x):
    if(y==0):
        return x
    else:
        return solve(x%y,y)
n=int(input())
for i in range(n):
    p=int(input())
    q=0
    i=1
    for i in range(1,(2*p)+1):
        q+=solve(p+(i+1)*(i+1),p+(i*i))
    print(q)
