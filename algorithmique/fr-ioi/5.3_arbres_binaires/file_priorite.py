from heapq import heappop, heappush
import sys
input = sys.stdin.readline

def main() :
    n = int(input())
    r = []
    for i in range (n) :
        l = input().split()
        if l[0] == 'I' :
            heappush(r, int(l[1]))
        else :
            if r :
                print(heappop(r))
            else :
                print('-')

main()