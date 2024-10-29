import sys

def read():
    return sys.stdin.readline().strip()

def main():
    m = int(read())
    p = int(read())
    r = 0
    for i in range (p) :
        r += sum(list(map(int, input().split())))
    for i in range (p):
        r -= sum(list(map(int, input().split())))
    print (r)

main()