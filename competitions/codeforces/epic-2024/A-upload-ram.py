import sys

input = sys.stdin.readline


def main() :
    t = int(input())
    for _ in range (t) :
        n, k = list(map(int, input().split()))
        print(n*k-(k-1))

main() 