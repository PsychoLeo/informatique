import sys

def read():
    return sys.stdin.readline().strip().split()

def main() :
    nbDays, nbDates = map(int, read())
    days = list(map(int, read()))
    ecc = [0]
    tot = 0
    for i in range (nbDays) :
        tot += days[i]
        ecc.append(tot)
    for i in range (nbDates) :
        x, y = map(int, read())
        print (ecc[y]-ecc[x-1])

main()