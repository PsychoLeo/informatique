import sys

def read() :
    return sys.stdin.readline().strip()

def main():
    n, numBrackets = int(read().split())
    print (roundBrackets(n, numBrackets))

def roundBrackets (n, numBrackets) :
    if n==0 :
        return n
    else :
        return '['+roundBrackets(n, numBrackets-1) + ']'

main()