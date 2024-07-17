import sys

def read() :
    return sys.stdin.readline().strip()

def main() :
    print (' '.join(map(str, sorted(dechets, reverse=True)[:maxDechets])))

if __name__ == '__main__' :
    numDechets, maxDechets = map(int, read().split())
    dechets = list(map(int, read().split()))
    main()