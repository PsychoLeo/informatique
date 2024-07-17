import sys
from heapq import heappop, heappush
input = sys.stdin.readline

def main():
    nbSalles, nbRepr = map(int, input().split())
    repres = []
    for i in range (nbRepr) :
        x, y = map(int, input().split())
        repres.append((x, y, i))
    sortedRepres = sorted(repres)
    minEndings = [(0, i) for i in range (1, nbSalles+1)] # fins d'utilisation des salles les plus proches
    assignements = [None]*nbRepr
    for i in range (nbRepr) :
        start, end, pos = sortedRepres[i]
        optimalPlace, salleNumber = heappop(minEndings)
        if start >= optimalPlace : # on lui assigne cette salle
            assignements[pos] = salleNumber
            heappush(minEndings, (end, salleNumber))
        else :
            print("NON")
            return
    print("OUI")
    for salle in assignements :
        print (salle, end = ' ')
    print ()

main()