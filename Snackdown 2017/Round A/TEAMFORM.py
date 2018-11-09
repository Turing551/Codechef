def solve(x,y):
    a=2*y
    b=x-a
    if b%2==0:
        return 'yes'
    else:
        return 'no'

n=int(input())
for i in range(n):
    x,k=input().strip().split()
    x,k=[int(x),int(k)]
    for i in range(k):
        p,q=input().strip().split()
    print(solve(x,k))
