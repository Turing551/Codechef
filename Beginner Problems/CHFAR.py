for _ in range(int(input())):
    x, y = [ int(i) for i in input().split()]
    n = [ int(i) for i in input().split()]
    res = n.count(1)
    if (x - res) <= y:
        print("YES") 
    else:
        print("NO") 
