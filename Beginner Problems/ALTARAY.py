def opp_sign(x,y):
    return int((x>0 and y<0) or (y>0 and x<0))


def countAltArray(A, N):

    score = [0]*N
    score[N-1] = 1
    for k in range(N-2,-1,-1):
        score[k] = 1 + score[k+1]*opp_sign(A[k], A[k+1])

    print " ".join(str(el) for el in score)

    return

if __name__ == '__main__':
    #computeProduct(2,[1,2,3,4])
    #countAltArray([1,2,3,4], 4)
    #countAltArray([-5,-1,-1,2,-2,-3], 6)

    T = int(raw_input())
    for k in range(T):
        N = int(raw_input())
        A = [int(el) for el in raw_input().split(" ")]
        countAltArray(A, N)
