import sys
input = sys.stdin.readline 

def reversort(n, l):
    r = 0
    for i in range (n-1) :
        mini = float("+inf")
        bestIndex = None
        for j in range (i, n) :
            if l[j] < mini :
                bestIndex = j
                mini = l[j]
        r += bestIndex-i+1
        l = l[:i] + l[i:bestIndex+1][::-1] + l[bestIndex+1:]
        assert len(l) == n
    return r

def main() :
    t = int(input())
    for i in range (t) :
        n = int(input())
        l = list(map(int, input().split()))
        print(f"Case #{i+1}: {reversort(n, l)}")

main()