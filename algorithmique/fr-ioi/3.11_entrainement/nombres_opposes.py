import sys

def read() :
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    numbers = set(map(int, read().split()))
    found = {}
    r = 0
    for nb in numbers :
        if nb > 0 :
            found[nb] = True
            if -nb in numbers :
                r += 1
    print (r)

main()