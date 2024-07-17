"""
Coded by SLG-CLUB
Date: 23/01/2021


ENONCE DU PROBLEME: 

Algorithme:
Complexité temporelle: O(|E|*log|V|) ou E est l'ensemble des sommets du graphe et V est l'ensemble des arrêtes
COmplexité mémoire: 
Principe:

"""
import sys
from heapq import heappush, heappop


def cin():
    return sys.stdin.readline().strip()

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
                if dist_neighbor < dist[neighbor]:
                    # On change dist, pred, et gray
                    dist[neighbor] = dist_neighbor # On enregistre la nouvelle distance
                    pred[neighbor] = node # On enregistre le predecesseur
                    heappush(gray, (dist_neighbor, neighbor))
    return dist, pred
                


if __name__ == '__main__':
    n=int(cin())
    m=int(cin())
    T =int(cin())
    connections = [list(map(int, cin().split())) for _ in range(m)]

    # Creation des liste adjacences et matrice adjacences
    matriceAdja= [[0]*n for _ in range(n)]
    graphe = [[] for _ in range(n)]
    for a,b,weight in connections:
        graphe[a].append(b)
        graphe[b].append(a)
        matriceAdja[a][b]=weight
        matriceAdja[b][a]=weight
    dist, pred = dijkstra(graphe, matriceAdja, source=0, target = T)
    q = T
    chemin = [T]
    while q!=0:
        q=pred[chemin[-1]]
        chemin.append(q)
    print(chemin[::-1])



