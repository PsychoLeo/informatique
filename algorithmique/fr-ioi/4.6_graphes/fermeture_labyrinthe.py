def main():
    nbNodes, nbAretes = map(int, input().split())
    pred = [[] for _ in range (nbNodes)]
    graph = [[] for _ in range (nbNodes)]
    for i in range (nbAretes) :
        A, B = map(int, input().split())
        pred[B-1].append(A-1)
        graph[A-1].append(B-1)
    for i in range (nbNodes) :
        if not pred[i] : # s'il n'a aucun prédecesseur, c'est notre noeud de départ
            # print (i)
            fermetureLabyrinthe(nbNodes, nbAretes, graph, pred, i)
            return 
    print (-1)
        
    
def fermetureLabyrinthe (nbNodes, nbAretes, graph, pred, initialNode) :
    toVisit = [initialNode]
    marked = [False]*nbNodes
    marked[initialNode] = True
    print (initialNode+1, end = ' ')
    while toVisit :
        node = toVisit.pop()
        # canDelete = True
        for neighbor in graph[node] :
            if not marked[neighbor] :
                if all([marked[i] for i in pred[neighbor]]) :
                    toVisit.append(neighbor)
                    marked[neighbor] = True
                    print (neighbor+1, end=' ')

main()