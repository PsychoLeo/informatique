def main() :
    n = int(input())
    delta = int(input())
    S = erath(n)
    res = 0
    for i in range (n) :
        if abs(S[i] - i -1) <= delta :
            res += 1
    print (res)


def erath (n) :
    Sn = [1]*n # from 1 to n
    Sn[0] = 0
    for i in range (2, n+1) :
        for j in range (2*i, n+1, i) :
            Sn[j-1] += i
    return Sn
        
main()