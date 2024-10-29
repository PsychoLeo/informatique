import sys

def read() :
    return sys.stdin.readline().strip()

def score(p) :
    sc = 0
    for i in range (n) :
        sc += s[p[i]] * e[p[i+1]]
    return sc

def solve() :
    S = 0
    for x in s :
        S += x * x
    for x in e :
        S += x * x
    p1 = [] # pairs
    p2 = [0] # impairs
    for i in range (0, n, 2) :
        p1.append(i)
    dep = n-2 if (n % 2) else n-1
    for i in range (dep, -1, -2) :
        p1.append(i)
    p1.append(0)
    for i in range (1, n, 2) :
        p2.append(i)
    dep = n-1 if (n%2) else n-2
    for i in range (dep, -1, -2) :
        p2.append(i)
    assert len(p1) == n+1 and len(p2) == n+1
    # print(*p1)
    # print(*p2)
    sc1, sc2 = score(p1), score(p2)
    if sc1 > sc2 :
        print(S-2*sc1)
        print(*p1)
    else :
        print(S-2*sc2)
        print(*p2)
    


if __name__ == "__main__" :
    n = int(input())
    s = list(map(int, input().split()))
    e = list(map(int, input().split()))
    solve()