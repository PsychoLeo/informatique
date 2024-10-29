def trouver_k(n):
    """
    :param n: dimension du labyrinthe de Minos
    :type n: int
    """
    # TODO Retourne le nombre de chemins possibles dans le labyrinthe de Minos
    paths = ["D"] # Initialisation avec le premier chemin obligatoire
    longueur_path_final = (n-1)*2
    # Directions possibles : R pour Right ou D pour Down
    for step in range(1, longueur_path_final):
        new_paths = []
        for path in paths:
            x, y = path.count('R'), path.count('D') # en haut à gauche c (0,0)
            if 0 <= x < y and y < n-1: #  on n'est pas sur le bord droit ni en bas
                new_paths += [path+"D",path+"R"]
            elif y == n-1: # On est en bas
                new_paths += [path+"R"]
            elif x == y :
                new_paths += [path+"D"]
        paths = new_paths[:]
    # for path in paths:
    #     print(path)
    print(f"n={n}, k={len(paths)}")


for i in range (2, 15) :
    trouver_k(i)