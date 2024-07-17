import sys
from heapq import heappop, heappush, heapify

input = sys.stdin.readline

def minPieces(n, a) :
    delta = []
    maxi = a[0]
    for i in range (1, n) :
        if a[i] < maxi :
            heappush(delta, maxi-a[i])
        else :
            maxi = a[i]
    # print(delta)
    r = 0
    s = 0
    m = len(delta)
    while delta :
        d = heappop(delta)
        d -= r
        s += (m+1)*d
        m -= 1
        r += d
    return s


def main():
    t = int(input())
    for _ in range (t) :
        n = int(input())
        a = list(map(int, input().split()))
        print(minPieces(n, a))


main()