def carreGraphe (g) :
    '''
    Input : graphe G = (S, A) (liste d'adjacence)
    Output : graphe G' = (S, A') tel que (u, v) in A' ssi il existe un chemin d'au plus 2 arcs entre u et v
    Complexité : O(A² * S)
    
    Idée : connaître toutes les suites de 3 noeuds du graphe ?
    '''
    n = len(g)
    suites3 = []
    for node in range (n) :
        for adj_first in g[node] :
            for adj_second in g[adj_first] :
                suites3.append((node, adj_first, adj_second))
    l = [[] for _ in range (n)]
    for a, b, c in suites3 :
        l[a].append(b)
        l[a].append(c)
    return l

g = [[1], [2], [3], [1]]
print(carreGraphe(g))

# https://github.com/gzc/CLRS/blob/master/C22-Elementary-Graph-Algorithms/22.1.md
# https://walkccc.me/CLRS/Chap22/22.1/
