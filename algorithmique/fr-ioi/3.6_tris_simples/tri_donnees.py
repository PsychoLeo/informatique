import sys

def read() :
    return sys.stdin.readline().strip()
def write(txt) :
    return sys.stdout.write(txt)

def main() :
    print (' '.join(map(str, sorted(dechets))))

if __name__ == '__main__' :
    n = int(read())
    dechets = list(map(int, read().split()))
    main()