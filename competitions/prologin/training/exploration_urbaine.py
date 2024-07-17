import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbNodes, nbVertices = map(int,read().split())
    listeAdj = [list() for _ in range (nbNodes)]
    for i in range (nbVertices) :
        A, B = map(int, read().split())
        listeAdj[A].append(B)
        listeAdj[B].append(A)
    maxSize, component = findConnected(nbNodes, nbVertices, listeAdj)
    print (maxSize)

def findConnected(nbNodes, nbVertices, listeAdj):
    # print (listeAdj)
    visited = [False]*nbNodes
    connectedComponents = []
    maxSize = 0 # biggest connected components
    biggestComponent = []
    for node in range (nbNodes) :
        if not visited[node] :
            currComponent = [node]
            toVisit = [node]
            visited[node] = True
            while toVisit :
                currNode = toVisit.pop()
                visited[currNode] = True
                for neighbor in listeAdj[currNode] :
                    if not visited[neighbor] :
                        toVisit.append(neighbor)
                        currComponent.append(neighbor)
            if len(currComponent) > maxSize :
                biggestComponent = currComponent[:]
                maxSize = len(currComponent)
    return maxSize, biggestComponent


main()