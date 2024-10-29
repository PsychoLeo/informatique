"""
Dans le cadre de la résolution du problème 4 : bataille eau, 
pour lequel nous utiliserons la solution au problème min-st-cut,
nous utilisons l'algorithme Edmonds-Karp, qui est plus rapide que celui de Ford-Fulkerson 
(notamment pour revenir à la source lorsque l'on parvient au sink dans la fonction BFS)

Désolé pour certains commentaires en anglais, je trouve qu'ils permettent de mieux expliquer
certains termes et qu'il est important de s'entraîner à parler anglais dans le domaine de la programmation
"""
import sys

def read() : # lire plus rapidement le input
    return sys.stdin.readline().strip()

class Graph: # classe de représentation d'un graphe

    def __init__(self, graph):
        self.graph = graph # residual graph (adjacency matrix)
        self.ROW = len(graph) # uppercase for constants
        self.COL = len(graph[0])

    def BFS(self, source, sink):
        '''input : graph and source/sink
        output : way (if it exists) from source to sink using breadth first search
        Edmonds-Karp uses 'enhanced' BFS => keeps track of predecessors
        '''
        visited = {source:None} # de la forme {actuel:predecesseur}
        queue = [source]
        while queue :
            # print (queue)
            current = queue.pop()
            for i in range (self.COL) :
                if i not in visited and self.graph[current][i] > 0 :
                    queue.append(i)
                    visited[i] = current
                    if i == sink : # if we have found the sink
                        result, currentNode = [sink], sink
                        while currentNode != source :
                            currentNode = visited[currentNode]
                            result.append(currentNode)
                        return result[::-1] # manière la plus rapide d'inverser une liste
                        # même si je pensais que c'était reversed(), il s'avère que c'est [::-1] (Stack Overflow)
        return False

    def toDelete(self, source, visited, delete):
        """
        Finds the links between nodes to delete when there is no more
        path from source to sink
        """
        self.visited[source] = True
        for i in range(self.ROW):
            if self.graph[i][source]!=0 and self.graph[source][i]==0 and not self.visited[i]:
                self.delete.append((source, i))
            if self.graph[source][i]!=0 and not self.visited[i]:
                self.toDelete(i,self.visited, self.delete)

    def EdmondsKarp (self, source, sink) :
        '''
        Returns the minimum cut to separate source from sink
        Print each one of these cuts
        '''
        isPath = self.BFS(source, sink)
        if not isPath : # if no path from source to sink at the beginning
            print(0); return None
        while isPath : # as long as there is a path from source to sink
            for i in range (len(isPath)-1) :
                self.graph[isPath[i]][isPath[i+1]] -= 1
            isPath = self.BFS(source, sink)
        # Printing them out
        self.visited = [False]*n; self.delete = []
        self.toDelete(source, self.visited, self.delete)
        print (len(self.delete))
        for villeA, villeB in self.delete :
            if not self.visited[villeB] : # if town not visited
                print(villeA,villeB)
        return None


def adjacencyMatrix (n, m, l):
    '''returns the adjacency matrix of the list of links'''
    matrix = [[0]*n for _ in range (n)]
    for i in l :
        A, B = i[0], i[1]
        matrix[A][B] = 1 # completing adjacency matrix
        matrix[B][A] = 1 # undirected graph => no directed links between 2 nodes
    # pprint.pprint (matrix) # print matrix nicely
    return matrix


if __name__ == '__main__':
    n = int(read())
    m = int(read())
    l = [list(map(int, read().split())) for _ in range(m)]
    h = int(read())
    t = int(read())
    g = Graph(adjacencyMatrix(n, m, l))
    g.EdmondsKarp(h, t)