import sys
input = sys.stdin.readline

def vestigium (n, m) :
    s = 0
    doubleRows = 0
    doubleCols = 0
    for i in range (n) :
        s += m[i][i]
        if len(set(m[i])) != n :
            doubleRows += 1
        if len(set([m[j][i] for j in range (n)])) != n:
            doubleCols += 1
    return s, doubleRows, doubleCols

def main() :
    t = int(input())
    for i in range (t) :
        n = int(input())
        m = [list(map(int, input().split())) for _ in range(n)]
        print(f"Case #{i+1}: {' '.join(map(str, vestigium(n, m)))}")

main()