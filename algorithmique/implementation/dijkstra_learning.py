from heapq import heappop, heappush

def dijkstra (graph, weights, source=0, target=None) :
    pass



if __name__ == "__main__":
    numNodes = int(input())
    numEdges = int(input())
    graph = [[] for _ in range (numNodes)] # liste d'adjacence
    weights = [[0]*numNodes for _ in range (numNodes)]# matrice d'adjacence
    for _ in range (numEdges) :
        A, B, poids = map(int, input().split())
        graph[A].append(B)
        graph[B].append(A)
        weights[A][B] = poids
        weights[B][A] = poids
    source = int(input())
    target = int(input())
    print(dijkstra(graph, weights, source, target))