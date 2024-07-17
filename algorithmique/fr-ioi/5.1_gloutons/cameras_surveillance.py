import sys
from heapq import heappop, heappush

def read(): # 8 fois plus rapide que input()
    return sys.stdin.readline().strip()

def prim():
    nbVisited = 0 # nombre de noeuds visités
    r = 0 # resultat : poids de l'arbre couvrant de poids minimal
    visited = [False]*nbNodes
    toVisit = [(0, 0)] # potentiels noeuds à visiter
    while nbVisited < nbNodes :
        weight, A = heappop(toVisit)
        if not visited[A] : # car sinon on utilise 2 noeuds déjà visités
            visited[A] = True # on marque A comme visité
            for w, neighb in adjList[A] : # pour vider la liste et ne plus y retourner
                if not visited[neighb] :
                    heappush(toVisit, (w, neighb)) # On rajoute les voisins de ce noeud
            r += weight
            nbVisited += 1
    print(r)

if __name__ == '__main__':
    nbNodes, nbEdges = map(int, input().split())
    adjList = [list() for _ in range (nbNodes)]
    for i in range (nbEdges) :
        dep, end, w = map(int, read().split())
        adjList[dep-1].append((w, end-1))
        adjList[end-1].append((w, dep-1))
    prim()