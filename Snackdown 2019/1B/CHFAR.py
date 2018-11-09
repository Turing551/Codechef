t=int(input())
while t>0:
    [n,k]=input().split(" ")
    arr=[int(x) for x in input().split(" ")]
    numberOfOnes=0
    for element in arr:
        if element==1:
            numberOfOnes+=1
    if len(arr)-numberOfOnes<=int(k):
        print("YES")
    else:
        print("NO")
    t=t-1
