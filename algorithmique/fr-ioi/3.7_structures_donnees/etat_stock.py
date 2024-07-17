import sys

def read() :
    return sys.stdin.readline().strip()

def main() :
    numChanges = int(read())
    for i in range (numChanges) :
        index, change = map(int, read().split())
        l[index-1] += change
    print (' '.join(map(str, l))); return None

if __name__ == '__main__' :
    n = int(read())
    l = list(map(int, read().split()))
    main()