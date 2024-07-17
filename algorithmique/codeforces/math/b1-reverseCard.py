def solve(n, m) :
    c = 0
    for b in range(1, m+1) :
        k = max(2//b, 1)
        while b*(k*b-1) <= n :
            k += 1
            c += 1
    return c

def main() :
    t = int(input())
    for _ in range(t) :
        n, m = list(map(int, input().split()))
        print(solve(n, m))

main()