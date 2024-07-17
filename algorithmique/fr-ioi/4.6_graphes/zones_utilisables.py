import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbNodes, nbEdges = map(int, read().split())
    listAdj = [list() for _ in range (nbNodes)]
    for i in range (nbEdges) :
        A, B, weight = map(int, read().split()) # peu importe la matrice d'adjacence
        listAdj[A-1].append(B-1)
        listAdj[B-1].append(A-1)
    connectedComponents(nbNodes, nbEdges, listAdj)

def connectedComponents(nbNodes, nbEdges, listAdj):
    bestSize = 0
    nbZones = 0
    visited = [False]*nbNodes
    for i in range (nbNodes) :
        if not visited[i] :
            visited, size = DFS(nbNodes, nbEdges, listAdj, visited, i)
            bestSize = max(size, bestSize)
            nbZones += 1
    print(nbZones, bestSize)

def DFS(nbNodes, nbEdges, listAdj, visited, i):
    toVisit = [i]
    size = 0
    while toVisit :
        node = toVisit.pop()
        visited[node] = True
        size += 1
        for neighbor in listAdj[node] :
            if not visited[neighbor] :
                visited[neighbor] = True
                toVisit.append(neighbor)
    return visited, size

main()