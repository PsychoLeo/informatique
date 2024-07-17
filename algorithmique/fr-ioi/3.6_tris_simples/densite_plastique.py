import sys

def read() :
    return sys.stdin.readline().strip()
def write(txt) :
    return sys.stdout.write(txt)

def main() :
    for i in range (numRequests) :
        request = int(read())
        if request in densities :
            write("1\n")
        else :
            write("0\n")

if __name__ == '__main__' :
    numDensities = int(read())
    densities = set(map(int, read().split()))
    numRequests = int(read())
    main()