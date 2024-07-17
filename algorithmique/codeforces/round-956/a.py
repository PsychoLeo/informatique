import sys

input = sys.stdin.readline 

def solve(n) :
    return list(range(1, n+1))


def main() :
    t = int(input())
    for _ in range (t) :
        n = int(input())
        print(*solve(n))

main()