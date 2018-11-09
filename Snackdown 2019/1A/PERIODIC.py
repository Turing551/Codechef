from math import gcd
def solve1(arr,k):
    x=max(arr)
    y=None
    z=None
    for i in range(k):
        if arr[i]==-1:
            continue
        if z is None:
            z=i
            continue
        if arr[i]-arr[z]==i-z:
            z=i
            continue
        if arr[i]-arr[z]>i-z:
            return "impossible"
        temp=(i-arr[i]-z)+arr[z]
        if temp<arr[z]:
            return "impossible"
        y=temp if y is None else gcd(y,temp)
        if y<x:
            return "impossible"
    return "inf" if y is None else y
def solve2():
    k=int(input())
    arr=[int(i) for i in input().split()]
    return k,arr
def main():
    n=int(input())
    for i in range(n):
        k,arr=solve2()
        y=solve1(arr,k)
        print(y)
if __name__ == '__main__':
    main()

#Accepted
