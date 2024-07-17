# Python program for finding min-cut in the given graph
# Complexity : (E*(V^3))
# Total augmenting path = VE and BFS with adj matrix takes :V^2 times
import numpy as np
# This class represents a directed graph using adjacency matrix representation
class Graph:
 
    def __init__(self,graph):
        self.graph = graph # residual graph
        self.org_graph = [i[:] for i in graph]
        self.ROW = len(graph)
        self.COL = len(graph[0])
    
    def __repr__(self):
        return str(np.matrix(self.graph))
 
    '''Returns true if there is a path from source 's' to sink 't' in
    residual graph. Also fills parent[] to store the path '''
    def BFS(self,s, t, parent):
 
        # Mark all the vertices as not visited
        visited =[False]*(self.ROW)
 
        # Create a queue for BFS
        queue=[]
 
        # Mark the source node as visited and enqueue it
        queue.append(s)
        visited[s] = True
 
         # Standard BFS Loop
        while queue:
 
            #Dequeue a vertex from queue and print it
            u = queue.pop(0)
 
            # Get all adjacent vertices of the dequeued vertex u
            # If a adjacent has not been visited, then mark it
            # visited and enqueue it
            for ind, val in enumerate(self.graph[u]):
                if visited[ind] == False and val > 0 :
                    queue.append(ind)
                    visited[ind] = True
                    parent[ind] = u
 
        # If we reached sink in BFS starting from source, then return
        # true, else false
        return True if visited[t] else False
 
 
    # Returns tne maxFlow of the given graph
    def maxFlow(self, source, sink):
 
        # This array is filled by BFS and to store path
        parent = [-1]*(self.ROW)
 
        max_flow = 0 # There is no flow initially
 
        # Augment the flow while there is path from source to sink
        while self.BFS(source, sink, parent) :
 
            # Find minimum residual capacity of the edges along the
            # path filled by BFS. Or we can say find the maximum flow
            # through the path found.
            path_flow = float("Inf")
            s = sink
            while(s !=  source):
                path_flow = min (path_flow, self.graph[parent[s]][s])
                s = parent[s]
 
            # Add path flow to overall flow
            max_flow +=  path_flow
 
            # update residual capacities of the edges and reverse edges
            # along the path
            v = sink
            while(v !=  source):
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]
 
        # # print the edges which initially had weights
        # # but now have 0 weight
        # for i in range(self.ROW):
        #     for j in range(self.COL):
        #         if self.graph[i][j] == 0 and self.org_graph[i][j] > 0:
        #             print(str(i) + " - " + str(j))
        return max_flow

    def findVerticesToDelete(self,source, visited, vertices_to_delete):
        visited[source]=True
        for i in range(self.ROW):
            if self.graph[i][source]!=0 and self.graph[source][i]==0 and not visited[i]: # Si un point peut accéder à la source mais que la source ne peut pas l'accéder, cette liaison est à supprimer
                vertices_to_delete.append((source, i))
            if self.graph[source][i]!=0 and not visited[i]:# Si elle est accessible et n'a pas été visité, on y va
                self.findVerticesToDelete(i,visited, vertices_to_delete) # On répète le processus pour ce voisin

 
def bataille_eau(n, m, l, h, t):
    """
    :param n: Le nombre de villes
    :type n: int
    :param m: Le nombre d'aqueducs entre les villes
    :type m: int
    :param l: Les aqueducs
    :type l: list[list[int]]
    :param h: La ville de Rome
    :type h: int
    :param t: La ville de Tivoli
    :type t: int
    """
    # TODO Afficher le nombre minimal d'aqueducs qu'il faudrait couper pour
    # isoler totalement les villes de Rome et de Tivoli, ainsi qu'une
    # proposition des aqueducs à détruire.

    # il faut d'abord établir la matrice d'adjacence du graphe
    graph = [[0 for _ in range(n)] for _ in range(n)]
    for aqueduc in l:
        graph[aqueduc[0]][aqueduc[1]]=1
        graph[aqueduc[1]][aqueduc[0]]=1
 
    g = Graph(graph)
    # print(g)
    source = h
    sink = t
    mf = g.maxFlow(source, sink)
    # print(g)
    # print(mf)
    if mf !=0: # Si il y a des arrêtes à supprimer
        visited_cities = [False]*n
        vertices_to_delete = []
        g.findVerticesToDelete(source, visited_cities, vertices_to_delete)
        for a,b in vertices_to_delete:
            if not visited_cities[b]:#Si b n'a jamais été visité c bien le bon chemin
                print(a,b)

def fromFile (filepath) :
    '''
    input : filepath (string of the file containing input)
    output : None | executing program with file
    '''
    with open(filepath, 'r') as f:
        n = int(f.readline())
        m = int(f.readline())
        l = [list(map(int, f.readline().split())) for _ in range(m)] # Connections des aqueducs
        h = int(f.readline())# Rome
        t = int(f.readline())# Tivoli
   
    bataille_eau(n, m, l, h, t)

if __name__ == '__main__':
    # n = int(input())# Nombre de villes
    # m = int(input())# Nombre d'aqueducs
    # l = [list(map(int, input().split())) for _ in range(m)] # Connections des aqueducs
    # h = int(input())# Rome
    # t = int(input())#Tivoli
    # bataille_eau(n, m, l, h, t)
    fromFile('input_bataille_eau.txt')