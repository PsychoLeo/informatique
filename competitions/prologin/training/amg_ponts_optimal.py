import sys
from math import sqrt
import random
from heapq import heappop, heappush

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    villes = list(map(int, read().split()))
    tousDiviseurs = [diviseurs(i) for i in villes]
    graph = [[i for i in range (n) if i!=j] for j in range (n)]
    adjMatr = [[0]*n for _ in range (n)] # matrice d'adjacence
    # isPrime = erath(int(1e6)) # tableau des nombres premiers de 1 à 10^6
    for i in range (n) :
        for j in graph[i] :
            if not adjMatr[i][j] :
                adjMatr[i][j] = max(tousDiviseurs[i] & tousDiviseurs[j])
                adjMatr[j][i] = adjMatr[i][j]
    # for row in adjMatr :
    #     print (row)
    print (kruskal(graph, adjMatr))

# def erath (n) :
#     isPrime = [True]*n
#     isPrime[1] = False
#     for i in range (4, n, 2) :
#         isPrime[i] = False
#     for i in range (3, n, 2) :
#         for j in range (2*i, n, i) :
#             isPrime[i] = False
#     return isPrime

# def gcd(a, b):
#     # Algorithme d'Euclide
#     if b :
#         return gcd(b, a%b)
#     else :
#         return a


class UnionFind:
    """
    Maintains a partition of {0, ..., n-1}
    """
    def __init__(self, n):
        self.up_bound = list(range(n))
        self.rank = [0] * n

    def find(self, x_index):
        """
        :returns: identifier of part containing x_index
        :complex_indexity: O(inverse_ackerman(n))
        """
        if self.up_bound[x_index] == x_index:
            return x_index
        self.up_bound[x_index] = self.find(self.up_bound[x_index])
        return self.up_bound[x_index]

    def union(self, x_index, y_index):
        """
        Merges part that contain x and part containing y
        :returns: False if x_index, y_index are already in same part
        :complexity: O(inverse_ackerman(n))
        """
        repr_x = self.find(x_index)
        repr_y = self.find(y_index)
        if repr_x == repr_y:       # already in the same component
            return False
        if self.rank[repr_x] == self.rank[repr_y]:
            self.rank[repr_x] += 1
            self.up_bound[repr_y] = repr_x
        elif self.rank[repr_x] > self.rank[repr_y]:
            self.up_bound[repr_y] = repr_x
        else:
            self.up_bound[repr_x] = repr_y
        return True


def kruskal(graph, weight):
    """
    Minimum spanning tree by Kruskal
    :param graph: undirected graph in listlist or listdict format
    :param weight: in matrix format or same listdict graph
    :returns: list of edges of the tree
    :complexity: O(E*log E)
    """
    n = len(graph)
    u_f = UnionFind(n)
    edges = []
    for u in range (n):
        for v in graph[u]:
            edges.append((weight[u][v], u, v))
    edges.sort(reverse=True)
    # min_span_tree = []
    r = 0
    for w_idx, u_idx, v_idx in edges:
        if u_f.union(u_idx, v_idx):
            # min_span_tree.append((u_idx, v_idx))
            r += w_idx
    return r


def diviseurs (n) :
    i = 2
    r = {1, n}
    while i <= sqrt(n) :
        if not n%i :
            r.add(n//i)
            r.add(i)
        i += 1
    return r

main()