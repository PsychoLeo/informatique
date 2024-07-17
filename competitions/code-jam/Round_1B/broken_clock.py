import sys

input = sys.stdin.readline

mod = 360*12*pow(10, 10)

def solve() :
    a, b, c = map(int, input().strip().split())
    for big, med, sml in [(a, b, c), (a, c, b), (b, a, c), (b, c, a), (c, a, b), (c, b, a)] :
        pass


def main() :
    t = int(input())
    for i in range (t) :
        print(f"Case #{i+1}: {solve()}")