def fastestPathBetween(self, a, b):
    """
    Input : a, b (int) => 2 positions
    Compute the fastest path
    Retourne le chemin et sa longueur PONDÉRÉE (cf Dijkstra) si possible
    => Sinon retourne None si aucun chemin ne mène à B
    """
    possible_starts = [] # possible paths from a => initializing path
    for i in range (self.n) :
        if self.adjMatrix[a][i] != 0 : # if path from starting point
            possible_starts.append (i)
    visited = [[a, i] for i in possible_starts] # initializing visited positions
    existPaths = True # if all paths are visited
    while existPaths :
        ephemere = [] # creating ephemere list that will replace visited
        numAppended = 0
        for path in visited : # for every current position
            for j in self.adjMatrix[visited[-1]] : # for adjacent nodes to current position
                if j != 0 and j not in visited :
                    ephemere.append (path+[j])
                    numAppended += 1
        visited = ephemere[:] + [l for l in visited if b in l] # copying ephemere into visited + lists that alreay contain b
        if numAppended == 0 : # if no modification was done => no more existing paths
            existPaths = False
    pathsToB = [i for i in visited if b in visited] # all paths to b
    if pathsToB == [] : # if no path from a to b exists
        return None
    else :
        pass # use function to get weight of a path


def weightPath (self, path) :
    '''
    Input : path (list of integers corresponding to path)
    Output : weight of the path (int)
    '''
    poids = 0
    for i in range(len(path)-1) :
        poids += self.adjMatrix[path[i]][path[i+1]]
    return poids                