# Dijkstra's algorithm
def labyrinthe_demoniaque(a, n, m, paths, plateau):
    """
    a: ame du visiteur (int)
    n: longueur du labyrinthe (int)
    m: largeur du labyrinthe (int)
	plateau : 2D array des valeurs des ames prises à toutes les cases
    plateau: grille du labyrinthe (list[list[int]])
    Retourne une liste d'entiers correspondant au meilleur chemin
    Sinon, renvoie "IMPOSSIBLE"
    """
    for row in range(1, n):
        tmp = [] # temporary list to contain all paths
        for index in range(m):  # trouver le meilleur moyen d'arriver à chaque point de la ligne
            tmp.append(bestPredecessor(row, index, m, paths, plateau))
        paths = tmp.copy()
    return 'IMPOSSIBLE' if all([path[1] > a for path in paths]) else min([path for path in paths], key = lambda l : l[1])[0]

def bestPredecessor(r, i, m, paths, plateau):
    '''r: current row | i: index in the row | m : width of the row
    output : finding the best predecessor and modifying paths'''
    if i == 0:
        mini = bestWay(paths[0], paths[1]) # prendre celui qui utilise le moins d'âme (pour le plus à gauche)
    elif i == m - 1:
        mini = bestWay(paths[-1], paths[-2])  # prendre celui qui utilise le moins d'âme (pour celui le plus à droite)
    else:
        mini = bestWay(paths[i - 1], paths[i], paths[i + 1])  # celui qui utilise le moins d'âme (ceux au milieu)
    mini = [mini[0][:], mini[1]] # deep-copying mini
    mini[0].append(i) # adding the current position to the best path (to this position)
    mini[1] += plateau[r][i]  # adding the soul taken by the current position
    return mini # retourne le chemin avec le moins d'âme utilisée

def bestWay (*args) :
    '''Find the best way to get to to a point (2 or 3 ways as argument)'''
    best, l = args[0][1], args[0]
    for path in args :
        if path[1] < best :
            best, l = path[1], path.copy()
    return l

if __name__ == '__main__':
    a = int(input())
    n = int(input())
    m = int(input())
    plateau = [list(map(int, input().split())) for _ in range(n)]
    paths = [[[i], plateau[0][i]] for i in range(m)]
    result = labyrinthe_demoniaque(a, n, m, paths, plateau)
    if result == 'IMPOSSIBLE' :
        print (result)
    else :
        print(' '.join(map(str, labyrinthe_demoniaque(a, n, m, paths, plateau))))