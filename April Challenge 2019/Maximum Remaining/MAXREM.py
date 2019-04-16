n=int(input())
x=0
arr=list(map(int,input().split()))
arr.sort(reverse=True)
y=arr[0]
for i in range(1,n):
    if y!=arr[i]:
        x=arr[i]
        break
print(x)
