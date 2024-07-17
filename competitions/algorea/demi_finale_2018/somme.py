import sys
input = sys.stdin.readline

def main() :
    res = 42000000
    n = int(input())
    l = set()
    for i in range (n) :
        l.add(int(input()))
    for i in l :
        if res-i in l and i != res//2:
            print(i)
            print(res-i)
            return

main()