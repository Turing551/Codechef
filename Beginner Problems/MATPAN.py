t = int(input())
for x in range(t):
    price = list(map(int,input().strip().split()))
    s = str(input().strip())
    s = list(s)
    s = list(set(s))
    s.sort()
    for i in range(len(s)):
        s[i] = ord(s[i]) - ord('a')
    res = 0
    j = 0
    for i in range(len(price)):
        if(j < len(s)):
            if s[j]!=i:
                res = res + price[i]
            else:
                j = j + 1
        else:
            res = res + price[i]
    print(res)
