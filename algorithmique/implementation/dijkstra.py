from collections import deque
import time, queue, sys, random
import networkx as nx
import matplotlib.pyplot as plt
from heapq import heappop, heappush

def read() :
    """Handle input => 4x faster than input() method"""
    return sys.stdin.readline().strip()


def Dijkstra(n, graph, source=0, sink=None):
    """
    graph : adjacency matrix of the graph (2D array)
    n : number of nodes in the graph (int)
    source : index of the source node (int)
    sink : index of the sink node (int)
    => Dijkstra algorithm : given a weighted, directed graph 
    Finds the shortest path from source to sink in O(|E|*log|V|)
    """
    if sink == None : 
        sink = n-1 # setting default value for sink
    pred = [None]*n # predecessors
    costs = [float("inf")]*n; costs[source] = 0
    toVisit = [(0, source)]; visited = set()
    while toVisit :
        mini = min(toVisit)
        dist, current = mini # take the smallest value
        toVisit.remove(mini) # remove the first element (the one with lowest cost)
        visited.add(current) # we have now visited it
        neighbors = [i for i in range(n) if graph[current][i] > 0] # search all its neighbors
        # maybe try with something other than adjacency matrix (dictionnary)
        for i in neighbors :
            neighborCost = dist + graph[current][i] # cost to get to this node
            if i not in visited : # if we have not studied it yet
                toVisit.append((neighborCost, i)) # we need to visit it
            if neighborCost < costs[i] : # if this is better than the cost we have found before
                costs[i] = neighborCost # update its cost
                pred[i] = current # update its (best) predecessor
    print(costs[sink])
    bestPath = [sink]
    while bestPath[-1] != source :
        bestPath.append(pred[bestPath[-1]])
    print (bestPath[::-1])
    
def dijkstra(graph, weight, source=0, target=None):
    """
    Fonctionne pour les graphes directionnels comme les graphes non directionnels
    param: graph : liste des voisins de chaque noeud = liste d'adjacence
    graph[node] ==> liste de tous les voisins de node
    param: weight: matrice d'adjacence
    """
    n = len(graph) # Le nombre de sommets
    assert all(weight[u][v] >= 0 for u in range (n) for v in graph[u]) # Dijkstra fonctionne seulement pour des poids positifs
    dist = [float("inf")]*n # Distance vers chaque noeud/sommet à partir de la source
    black = [False]*n # Les noeuds étant marqués sont traités (liste des noeuds dont on connait la distance minimale à la source)
    pred = [None]*n # Liste des prédecesseurs 
    dist[source] = 0 # On commence à la source => pour pouvoir initialiser l'algorithme
    gray = [(0, source)] # liste des sommets à traiter avec leur distance 
    while gray: # Tant qu'on a des sommets à traiter
        distance, node = heappop(gray) # Retourne le noeud dont la distance est la plus petite
        # => ce qui rend la complexité O(NlogN) au lieu de O(n^2) => les opérations heappop et heappush sont en log(N) de complexité
        if not black[node]: # Si le sommet n'a pas été traité, i.e. que sa distance n'a pas été définitivement prise
            black[node] = True # Il est NOIR (donc il a été traité)
            if node == target: # SI on est arrivé jusqu'à l'objectif
                break # on a trouvé la solution
            for neighbor in graph[node]: # Pour chaque voisin du noeud
                dist_neighbor = distance + weight[node][neighbor] # Distance entre la source et le neighbour en passant par node   SOURCE --> NODE --> NEIGHBOR
                if dist_neighbor < dist[neighbor] :
                	dist[neighbor] = dist_neighbor
                	pred[neighbor] = node
                	heappush(gray, (dist_neighbor, neighbor))
    return dist, pred


def AdjacencyMatrix (edges, numNodes) :
    """
    Returns the adjacency matrix from nodes that link themselves
    (Weighted, directed graphs)
    """
    matrix = [[0]*numNodes for _ in range (numNodes)]
    for a, b, weight in edges :
        matrix[a][b] = weight # as directed graph
    return matrix


def main(numNodes) :
    """Test Dijkstra algorithm implementation"""
    start = time.time()
    nx_graph = nx.DiGraph()
    nx_graph.add_weighted_edges_from(edges)
    print(nx.dijkstra_path(nx_graph, source, sink)) # nx module to compare results
    print(f"Time (networkx) : {time.time()-start} seconds")
    start = time.time()
    graph = AdjacencyMatrix(edges, numNodes)
    Dijkstra(numNodes, graph, source, sink) # finding best path from source to sink
    print(f"Time : {time.time()-start} seconds")


def generateGraph (numNodes, maxVal):
    """
    maxWeight : maximum weight for each vertice (int)
    numNodes : number of nodes in graph (int)
    numVertices : number of vertices in graph (int)
    """
    edges = []
    G = nx.gnp_random_graph(numNodes, 0.1, directed=True)
    DiG = nx.DiGraph([(u, v, {"weight":random.randint(1, maxVal)}) for (u, v) in G.edges() if u<v])
    return DiG, DiG.edges.data("weight")


if __name__ == "__main__" :
    randomGraph = False # if graph will be generated randomly
    if randomGraph :
        numNodes = 1000
        maxVal = 1000
        source, sink = 0, numNodes-1 # default values
        nx_graph, edges = generateGraph(numNodes, maxVal) # generating random graph
    else :
        numNodes = int(read()) # number of nodes
        numEdges = int(read()) # number of edges
        # input format : nodeA, nodeB, A-B weight
        edges = [tuple(map(int, read().split())) for _ in range (numEdges)]
        source, sink = int(read()), int(read()) # source / sink nodes
    main(numNodes) # running code
