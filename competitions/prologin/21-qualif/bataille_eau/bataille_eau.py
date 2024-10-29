import time
import pprint

# https://courses.ex-machina.ma/downloads/MIAGE2/S4/maths_pour_info/ALG_Fulkerson_Hongroise.pdf
# site ayant permis de comprendre l'algorithme de Ford-Fulkerson

# N'ayant aucune connaissance en théorie des graphes, j'ai effectué des recherches sur ce domaine
# Je suis arrivé à la conclusion qu'il fallait trouver le maxflow-mincut pour un "undirected" graphe
# En utilisant l'algorithme de Ford-Fulkerson, j'ai suivi les étapes du pseudo-code suivant :
# https://brilliant.org/wiki/ford-fulkerson-algorithm/#algorithm-pseudo-code
# flow = 0
# Initialize flows for each link
# while there is a path, p, from s -> t in residual network G_f:
#     residual_capacity(p) = min(residual_capacity(u, v) : for (u, v) in p)
#     flow = flow + residual_capacity(p)
#     for each edge (u, v) in p:
#         if (u, v) is a forward edge:
#             flow(u, v) = flow(u, v) + residual_capacity(p)
#         else:
#             flow(u, v) = flow(u, v) - residual_capacity(p)
# return flow


def minCut(n, m, l, r, t):
    """
    :param n: Le nombre de villes (int)
    :param m: Le nombre d'aqueducs entre les villes (int)
    :param l: Les aqueducs (list[list[int]])
    :param r: La ville de Rome (int)
    :param t: La ville de Tivoli (int)
    """
    count = 0
    pprint.pprint(l)
    aqueducs = adjacencyMatrix(n, l) # matrice d'adjacence représentant les chemins
    path = dfs(aqueducs, r, t) # chemin Rome -> Tivoli
    pprint.pprint(aqueducs)
    print (path)
    while path != [] :
        count += 1
        path = dfs(aqueducs, r, t)
        aqueducs = deleteAqueduc (aqueducs, path)
    # while path : # tant qu'il existe un chemin entre Rome et Tivoli
    #     for i in range(len(path)) :
    #         aqueducs[i][i+1] -= 1
    #         aqueducs[i+1][i] += 1
    #     break

def deleteAqueduc (graph, path):
    pass

def isPath (graph, start, end) :
    '''input : graph and source/sink
    output : if there is a way from source to sink using bfs'''
    pass

    

def dfs(graph, start, end):
    '''BFS search of the graph using adjacency matrix
    Searching a possible way from source to sink and return it'''
    linked_graph = {} # dictionnary of linked graph
    if isPath (linked_graph, start, end) :
        pass # implement DFS to find path with adjacency matrix
    else :
        return []


def adjacencyMatrix (n, l):
    '''returns the adjacency matrix of the list of links'''
    matrix = [[0]*n for _ in range (n)]
    for i in l :
        A, B = i[0], i[1]
        matrix[A][B] = 1 # completing adjacency matrix
        matrix[B][A] = 1 # undirected graph => no directed links between 2 nodes
    return matrix

def fromFile (path) :
    with open(path) as f :
        n = int(f.readline())
        m = int(f.readline())
        l = [list(map(int, f.readline().split())) for _ in range(m)]
        r = int(f.readline())
        t = int(f.readline())
    start = time.time()
    minCut(n, m, l, r, t)
    print(f'Time : {time.time()-start} seconds')
    # expected output : 1 \n 3 4


if __name__ == '__main__':
    file = 'y'
    start = time.time()
    if file == 'y' :
        fromFile('input_bataille_eau.txt')
    else :
        n = int(input())
        m = int(input())
        l = [list(map(int, input().split())) for _ in range(m)]
        r = int(input()) # changé en r car plus compréhensible (Rome)
        t = int(input())
        minCut(n, m, l, r, t)
    # print(f'Time : {time.time()-start} seconds')