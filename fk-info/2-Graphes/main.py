from Graphe import Graph, Arete


if __name__ == '__main__':
    n=int(input())
    m=int(input())
    connections = [list(map(int, input().split())) for _ in range(m)]
    listeAretes = [Arete(connection[0], connection[1], connection[2]) for connection in connections]
    graph = Graph(n, m, listeAretes)
    print(graph)
    print(graph.arbreCouvrantCoutMinimalPrimBis())