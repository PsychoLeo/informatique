import sys
sys.setrecursionlimit(1000000)

def solve(n, a) :
    subseq = []
    m = len(set(a))
    found = [False]*(n+1)
    def aux(i, l=[]) :
        if i >= n :
            if len(l) == m :
                subseq.append(l) 
        else :
            aux(i+1, l)
            if not found[a[i]] :
                found[a[i]] = True
                aux(i+1, l+[a[i]])
                found[a[i]] = False
    aux(0)
    return min(subseq, key=lambda v: [v[i]*(1 if i%2 else -1) for i in range (len(v))])


if __name__ == "__main__" :
    t = int(input())
    for _ in range (t) :
        n = int(input())
        a = list(map(int, input().split()))
        l = solve(n, a)
        print(len(l))
        for x in l :
            print(str(x), end=' ')
        print()