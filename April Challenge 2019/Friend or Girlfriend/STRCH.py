while True:
    try:
        n=int(input())
        for i in range(n):
            k=int(input())
            p,q=input().strip().split()
            x,y=[],0
            for j in range(len(p)):
                if p[j]!=q:
                    x.append(y)
                else:
                    y=j+1
                    x.append(y)
            print(sum(x))
    except:
        break
