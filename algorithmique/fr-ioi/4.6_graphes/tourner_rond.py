import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbNodes, nbEdges = map(int, read().split())
    listAdj = [list() for _ in range (nbNodes)]
    for i in range (nbEdges) :
        A, B = map(int, read().split())
        listAdj[A-1].append(B-1)
    # print (listAdj)
    for i in range (nbNodes) :
        if not DFS (nbNodes, listAdj, i) :
            print ("OUI"); return
    print ("NON")

def DFS (nbNodes, listAdj, i):
    visited = [False]*nbNodes
    visited[i] = True
    toVisit = [i]
    while toVisit :
        node = toVisit.pop()
        for neighbor in listAdj[node] :
            if neighbor == i : # we have come back to a previous position
                return False
            if not visited[neighbor] :
                toVisit.append(neighbor)
                visited[neighbor] = True
    return True

main()