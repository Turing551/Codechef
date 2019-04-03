import math
def main():
    for i in range(int(input())):
        x,y=map(int,input().split())
        arr=list(map(int,input().split()))
        arr.insert(0,None)
        ans=None
        for j in range(1,x+1):
            cnt=sum([math.floor(b/(a+1))
                         for a,b in enumerate(arr[j:x+1])])
            if y>=cnt:
                ans=j
                break
        if ans==None:
            ans=x+1
        print(ans)
if __name__ == "__main__":
    main()
