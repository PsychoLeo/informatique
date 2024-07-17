import sys
import pprint

def read() :
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    l = [[' ']*(n-i) for i in range (n)]
    Sierpinski(n, l, 0, 0)
    # print(triangle)
    for i in result[-1] :
        print (''.join(i))

def Sierpinski(n, l, x, y) :
    if n == 0 : # length of the current Sierpinski form to draw
        result.append(l)
        del result[0]
    else : # if n>0
        for i in range (x, x+n) :
            l[y][i] = '#'
        for i in range (y, y+n) :
            l[i][x] = '#'
        Sierpinski(n//2, l, x, y)
        Sierpinski(n//2, l, x, y+n//2)
        Sierpinski(n//2, l, x+n//2, y)

result = [None] 
main()