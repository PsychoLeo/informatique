import sys
input = sys.stdin.readline
# print = sys.stdout.write
from heapq import heappush, heappop

def dijkstra ():
    toVisit = [(0, startNode-1)]
    black = [False]*nbNodes
    dist = [float("inf")]*nbNodes
    dist[startNode-1] = 0
    while toVisit :
        dist_node, node = heappop(toVisit)
        if not black[node] :
            print (str(dist[node]) + ' ' + str(node+1))
            black[node] = True
            for neighbor in listAdj[node] :
                dist_neighbor = dist_node + matrAdj[node][neighbor]
                if dist_neighbor < dist[neighbor] :
                    dist[neighbor] = dist_neighbor
                    heappush(toVisit, (dist_neighbor, neighbor))


if __name__ == '__main__':
    nbNodes, nbEdges, startNode = map(int, input().split())
    listAdj = [list() for _ in range (nbNodes)]
    matrAdj = [[0]*nbNodes for _ in range (nbNodes)]
    for _ in range (nbEdges) :
        A, B, w = map(int, input().split())
        listAdj[A-1].append(B-1)
        listAdj[B-1].append(A-1)
        matrAdj[A-1][B-1] = matrAdj[B-1][A-1] = w
    dijkstra()