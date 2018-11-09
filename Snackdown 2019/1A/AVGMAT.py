def main():
    n=int(input())
    while n:
        x,y=[int(x) for x in input().split()]
        arr={}
        temp=[]        
        i=1
        while i<=x:
            arr1=input()
            j=1
            while j<=y:
                if arr1[j-1] == '1':
                    for k in temp:
                        cnt=abs(j-k[1])+i-k[0]
                        arr[cnt]=1+arr.get(cnt,0)
                    temp.append((i,j))
                j=j+1
            i=i+1        
        for i in range(1,x+y-1):
            print(arr.get(i,0),end=" ")
        n=n-1
main()
