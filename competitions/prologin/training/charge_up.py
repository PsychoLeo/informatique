import sys
# from collections import deque

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    circuit = [input().split() for _ in range (n)]
    bestCharge(circuit, n)

def bestCharge(circuit, n) :
    """
    O(n^2) time complexity (pas 100% sûr)
    O(n^2) memory complexity
    """
    visited = [[False]*n for _ in range (n)] # visited places
    prisePos = [] # positions des prises
    chargerPos = [] # positions des chargeurs
    for i in range(n) :
        for j in range (n): # as len(i) = n
            if circuit[i][j] == 'P' :
                prisePos.append((i, j)) # check how to move from this point
                visited[i][j] = True # we have now been here
            elif circuit[i][j] == 'C' :
                chargerPos.append((i, j))
                visited[i][j] = True
    for priseX, priseY in prisePos :
        x, y = searchNext (priseX, priseY, chargerPos, prisePos, circuit)

def searchNext(px, py, chargerPos, prisePos):
    pass # ce problème est nul à chier
    

main()