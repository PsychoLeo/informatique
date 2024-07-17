import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbCibles = int(input())
    cibles = list(map(int, read().split()))
    nbLots = int(input())
    lots = list(map(int, read().split()))
    fete_foraine (nbCibles, cibles, nbLots, lots)

def fete_foraine(nbCibles, cibles, nbLots, lots):
    j = 0 # index at the lots list
    for i in cibles :
        while j < nbLots and i >= lots[j] :
            j += 1
        print (lots[j-1], end = ' ')

main()