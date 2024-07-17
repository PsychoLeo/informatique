import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    l = list(map(int, read().split()))
    print (bentley(n, l))

def bentley(n, l):
    """
    En commençant de la gauche pour traverser la liste
    et calculer les ECC (et on reset dès que les valeurs sont < 0)
    """
    eff = 0
    bestIndex = 0 # best left index found yet
    bestScore = 0
    lastReset = 0
    for i in range (n) :
        eff += l[i]
        if eff < 0 :
            eff = 0
            lastReset = i
        elif eff > bestScore :
            bestScore = eff
            bestIndex = lastReset
    # Now going right to left (from the end to index bestIndex)
    eff = 0
    bestRemove = 0
    for i in range (n-1, i, -1) :
        eff += l[i]
        if eff < bestRemove :
            bestRemove = eff
    return bestScore - bestRemove

main()