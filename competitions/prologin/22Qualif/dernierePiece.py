import sys

def read() :
    return sys.stdin.readline().strip()

def solve() :
    result = ""
    for nbCotes, couleur in piecesTrier :
        if nbCotes != nbCotesPieceManque :
            result += "X"
            continue
        if couleur in couleursAdj :
            result += "X"
            continue
        result += "O"
    print(result)
    print(result.count("O"))

if __name__ == "__main__" :
    nbCouleurs = int(read())
    couleurs = [read() for _ in range (nbCouleurs)]
    nbCotesPieceManque = int(read())
    couleursAdj = [read() for _ in range (nbCotesPieceManque)]
    nbPiecesTrier = int(read())
    piecesTrier = []
    for _ in range (nbPiecesTrier) :
        cotes, couleur = int(read()), read()
        piecesTrier.append((cotes, couleur))
    # print(piecesTrier)
    solve()