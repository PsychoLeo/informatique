grid = [
    [1,1,2,2,2,3,3,3], 
    [1,1,2,2,3,3,3,4],
    [1,2,2,3,3,4,4,5],
    [2,2,2,3,3,4,4,5],
    [2,3,3,3,4,4,5,6],
    [2,3,3,3,4,4,5,6],
    [3,3,3,4,5,6,7,8],
    [3,4,4,5,5,6,8,8]
]

n = len(grid)
v = 6
c = 0

def tailleCarre() :
    return n

def valeurCible() :
    return v

def valeurCase(lig, col) :
    global c
    c += 1
    if 0 <= lig < n and 0 <= col < n :
        return grid[lig][col]
    return -1

def repondre(lig, col) :
    global c
    x = valeurCase(lig, col)
    if x == v :
        print(f"Gagné en {c} tours")
    else :
        print("Mauvaise réponse")