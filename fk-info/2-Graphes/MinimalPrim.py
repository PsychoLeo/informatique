def arbreCouvrantCoutMinimalPrim(self):
    """
    Trouve l'arbre couvrant de coût minimal
    Pour cela, on s'inspire de l'algorithme de Prim
    """
    pointsArbre = [0] # On part du point 0
    aretesArbre = [] # Arêtes de l'arbre final
    while len(pointsArbre) < self.n : # Tant que l'arbre ne recouvre pas le graphe
        visited, mini = [], float("+inf")
        for i in pointsArbre :
            for j in range (len(self.adjMatrix[i])) :
                if j not in visited and self.adjMatrix[i][j] > 0 and self.adjMatrix[i][j] < mini :
                    mini = self.adjMatrix[i][j]
                    best, best_node = j, (i, j)
                    visited.append(j)
        pointsArbre.append(best) # liste des meilleurs voisins
        aretesArbre.append(best_node) # liste des meilleurs nodes
    return pointsArbre, aretesArbre