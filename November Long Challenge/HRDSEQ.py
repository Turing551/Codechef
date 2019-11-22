def solve(arr):
    n=""
    for x,y in zip(*arr):
        n=n+str(int(x)^int(y))
    return n
if __name__ == "__main__":
    for i in range(int(input())):
        arr=[]
        for i in range(int(input())):
            arr.append(input())
            if len(arr)==2:
                arr=[solve(arr)]
        print(arr[0].count("1"))
