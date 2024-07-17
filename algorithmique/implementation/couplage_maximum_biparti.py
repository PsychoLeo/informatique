import sys
input = sys.stdin.readline
print = sys.stdout.write 

def augment(u,bigraph, match, visited):
    """
    Algo récursif pour trouver un chemin augmentant et modifier match
    visited list[bool] --> si le noeud a été visité ou non
    u (int) --> noeud
    bigraph list[list[int]] --> Ils contient toutes les connexions de chacun des noeuds de gauche 
    match = list[int] --> Pour chaque point de droite, on a son précédent, ou None si aucun
    
    return True ou False
    True s'il a trouvé un chemin augmentant et False sinon
    """
    #* v est à droite
    #* u est à gauche
    for v in bigraph[u] : # pour chaque voisin du noeud actuel
        # marqué ou non ?
        if not visited[v] :
            visited[v] = True # Il est marqué
            # Soit v est libre --> dans ce cas on peut l'associer avec u
            # Soit on arrive à associer le prédécesseur de v avec un autre noeud grâce à augment
            if match[v] is None or augment(match[v], bigraph, match, visited) :
                match[v] = u
                return True
    return False


def max_bipartite_matching(n,m,bigraph):
    """
    n (int) --> nombre de noeuds dans la partie gauche
    m (int) --> nombre de noeuds dans la partie droite
    bigraph list[list[int]] --> Ils contient toutes les connexions de chacun des noeuds de gauche 
    return match = list[int] --> Pour chaque point de droite, on a son précédent, ou None si aucun
    """
    match = [None] * m
    # Pour tous les points chercher un chemin augmentant

    # Pour chaque point u
    # On regarde s'il y a un chemin augementant partant de u, à l'aide de la fonction augment
    for u in range(len(bigraph)):
        visited = [False]*m 
        augment(u, bigraph, match, visited)
    return match


if __name__ == "__main__":
    n,m = map(int, input().split()) # Nombre de noeuds à gauche et à droite
    g = []
    # On a n lignes, sur chacune de ces lignes on a les noeuds qui sont liés à droite
    for _ in range(n):
        g.append(list(map(int, input().split())))
    for v,u in enumerate(max_bipartite_matching(n,m,g)):
        print("%d <==> %d\n" %(u,v))