def stabilisateurs() :
    maxi = 0
    def aux(i, l) :
        nonlocal maxi
        if i+4 < N :
            aux(i+4, l+[(h[i+3]-h[i])**2])
            aux(i+1, l)
        else :
            maxi = max(maxi, len(l)*P - sum(l))
    aux(0, [])
    return maxi

if __name__ == "__main__" :
    N = int(input())
    K = int(input())
    P = int(input())
    h = list(map(int, input().split()))
    h.sort()
    print(stabilisateurs())