import sys

def read() :
    return sys.stdin.readline().strip()


def main() :
    # Complexity : O(n*h) 
    # n: number of inputs, h: height of each input
    largeur, longueur = map(int, read().split())
    l = [['.']*longueur for _ in range (largeur)]
    numQueries = int(read())
    for _ in range (numQueries) :
        inpt = [int(i) if i.isnumeric() else i for i in read().split()]
        haut, gauche, bas, droite, char = inpt
        for i in range (haut, bas+1) :
            l[i][gauche:droite+1] = [char]*(droite-gauche+1)
    output(l)

def output(l) :
    for i in l :
        print (''.join(i))

if __name__ == '__main__' :
    main()