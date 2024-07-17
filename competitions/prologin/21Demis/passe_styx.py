import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    bestTime = None
    bestCost = float("+inf")
    for i in range (n) :
        dep, fin, prix = map(int, read().split())
        for j in range (dep, fin):
            currPrice = prix
            if j+1 < 18 :
                currPrice += 2*(18-j-1)
            elif j+1 > 18 :
                currPrice += 4*(j+1-18)
            if currPrice < bestCost :
                bestTime = j
                bestCost = currPrice
    print(bestTime)

main()