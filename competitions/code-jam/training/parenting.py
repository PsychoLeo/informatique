import sys
input = sys.stdin.readline

def parenting (l) :
    # Algorithme glouton
    parents = [[0, 'C'], [0, 'J']]
    r = [None]*len(l)
    l.sort()
    # print(l)
    for dep, fin, i in l :
        parents.sort()
        if dep < parents[0][0] :
            return "IMPOSSIBLE"
        else :
            r[i] = parents[0][1]
            parents[0][0] = fin
    return ''.join(r)

def main():
    t = int(input())
    for i in range (t) :
        n = int(input())
        l = []
        for j in range (n) :
            dep, end = map(int, input().split())
            l.append([dep, end, j])
        print(f"Case #{i+1}: {parenting(l)}")

main()