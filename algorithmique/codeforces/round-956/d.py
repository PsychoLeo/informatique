import sys

input = sys.stdin.readline 

def solve(n, a, b) :
    if sorted(a) != sorted(b) :
        return "NO"
    return None


def main() :
    t = int(input())
    for _ in range (t) :
        n = int(input())
        a, b = list(map(int, input().split())), list(map(int, input().split()))
        print(solve(n, a, b))

main()