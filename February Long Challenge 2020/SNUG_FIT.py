import math

def main():
    for i in range(int(input())):
        a=0
        n=int(input())
        x=sorted(list(map(int,input().split())))
        y=sorted(list(map(int,input().split())))
        for j in range(n):
            temp=min(x.pop(),y.pop())*0.5
            a+=(2*temp)
        print(int(a))
if __name__ == "__main__":
    main()
