import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    intervals = []
    for i in range (n) :
        x, y = map(int, read().split())
        intervals.append((x, y))
    intervals.sort()
    fin = 0 # position à la fin
    tot = 0
    for x, y in intervals :
        if y >= fin : # sinon on ne change pas tot
            if x >= fin :
                tot += y - x
            else :
                tot += y - fin
            fin = y
    print (tot)

main()