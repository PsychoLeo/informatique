import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    maisons = list(map(int, read().split()))
    maisons.sort()
    delta = float("+inf")
    for i in range (1, n):
        delta = min(maisons[i] - maisons[i-1], delta)
    print (delta)

main()