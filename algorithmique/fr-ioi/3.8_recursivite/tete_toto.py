import sys

def read() :
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    print("0 = " + fill0s(n))

def fill0s (n) :
    if n == 0 :
        return "0"
    else : # if n>0
        return "(" + fill0s(n-1) + " + " + fill0s(n-1) + ")"

main()