from collections import deque

def BFS (source, sink, weights) :
    pred = [None]*len(weights)
    curr = deque([source])
    while curr :
        node = curr.pop()
        if node == sink :
            break
        for neighbor in residualGraph[node]:
            pred[neighbor] = node
            curr.appendleft(neighbor)
    if pred[sink] is None :
        return [], float("+inf")
    sol = []
    node = sink
    minWeight = float("+inf")
    while pred[node] is not None :
        sol.append((pred[node], node))
        if weights[node][pred[node]] < minWeight :
            minWeight = weights[node][pred[node]]
        node = pred[node]
    return sol, minWeight

def EdmondsKarp (graph, weights, source, sink):
    nodesAugmented, minWeight = BFS(source, sink, weights)
    while nodesAugmented : # as long as there is a path from source to sink
        for A, B in nodesAugmented :
            weights[A][B] -= minWeight
            weights[B][A] -= minWeight
            if weights[A][B] <= 0 :
                residualGraph[A].remove(B)
        nodesAugmented, minWeight = BFS(source, sink, weights)
    toDelete = findToDelete(source, weights)
    print (len(toDelete))
    for a, b in toDelete :
        print (a, b)

def findToDelete (source, weights) :
    canGo = deque([source]) # nodes where we can go from source
    limits = [source]
    result = set()
    while canGo :
        currNode = canGo.pop()
        for neighbor in residualGraph[currNode] :
            canGo.append(neighbor)
            limits.append(neighbor)
    for node in limits :
        for neighbor in graph[node] :
            if weights[node][neighbor] == 0 :
                result.add((node, neighbor))
    return result


if __name__ == "__main__" :
    numNodes = int(input())
    numEdges = int(input())
    graph = [[] for _ in range (numNodes)] # liste d'adjacence
    residualGraph = [[] for _ in range (numNodes)]
    weights = [[0]*numNodes for _ in range (numNodes)]# matrice d'adjacence
    for _ in range (numEdges) :
        A, B, poids = map(int, input().split())
        graph[A].append(B) # graphe orienté
        weights[A][B] = poids
        weights[B][A] = poids
        residualGraph[A].append(B)
    source = int(input())
    sink = int(input())
    EdmondsKarp(graph, weights, source, sink)