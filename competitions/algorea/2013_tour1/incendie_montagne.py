import sys
input = sys.stdin.readline

def main():
    nbCases = int(input())
    alt = list(map(int, input().split()))
    nbEclairs = int(input())
    pos = list(map(int, input().split()))
    menaces(nbCases, alt, nbEclairs, pos)

def menaces(nbCases, alt, nbEclairs, pos) :
    comptees = [False]*nbCases # cases deja menacées
    r = 0
    for x in pos :
        currPos = x
        if not comptees[x] :
            comptees[x] = True
            r += 1
        while currPos+1 < nbCases and alt[currPos] <= alt[currPos+1] and (not comptees[currPos+1]) :
            comptees[currPos+1] = True
            r += 1
            currPos += 1
        while x > 0 and alt[x] <= alt[x-1] and (not comptees[x-1]) :
            comptees[x-1] = True
            r += 1
            x -= 1
    print (r)



main()