import math

for i in range(int(input())):
    x,y=map(int,input().split())
    arr=list(map(int,input().split()))
    temp=0
    for j in range(0,x):
        temp+=arr[j]%y
    while temp>=y:
        temp-=y
    print(temp)
