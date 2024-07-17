import time

def labyrinthe_demoniaque(a, n, m, plateau):
    """
    :param a: ame du visiteur
    :type a: int
    :param n: longueur du labyrinthe
    :type n: int
    :param m: largeur du labyrinthe
    :type m: int
    :param plateau: grille du labyrinthe
    :type plateau: list[list[int]]
    """
    # TODO Retourne une liste d'entiers correspondant au meilleur chemin
    # permettant de sortir du labyrinthe en conservant un maximum de son âme,
    # sachant que le visiteur augmente sa coordonnée n à chaque case et ne peut
    # revenir en arrière. Si aucun chemin n'est possible, afficher "IMPOSSIBLE"
    paths = [[i] for i in range(m)] # liste contenant tous les chemins et initalisée
    for y in range(1,n):
        new_pathes = []
        for path in paths:
            last_step = path[-1]
            if last_step==0:
                new_pathes += [path+[0], path+[1]]
            elif 1<=last_step<=n-2:
                new_pathes += [path+[last_step-1], path+[last_step], path+[last_step+1]]
            elif n-1==last_step:
                new_pathes += [path+[n-2], path+[n-1]]
        paths = new_pathes[:]
    
    # Déterminons le coût de chaque chemin:
    cost_of_paths = [cost_of_path(path, plateau) for path in paths]
    # for path, cost in zip(paths, cost_of_paths):
        # print(f"PATH = {path} ; COST = {cost}")
    minimum = min(cost_of_paths)
    if minimum <= a:
        print(*paths[cost_of_paths.index(minimum)])
    else:
        print("IMPOSSIBLE")



def cost_of_path(path, plateau):
    """
    return the cost of a path
    """
    cost = 0
    for y, x in enumerate(path):
        cost+=plateau[y][x]
    return cost


def labyrinthe_demoniaque2(a, n, m, plateau):
    """
    :param a: ame du visiteur
    :type a: int
    :param n: longueur du labyrinthe
    :type n: int
    :param m: largeur du labyrinthe
    :type m: int
    :param plateau: grille du labyrinthe
    :type plateau: list[list[int]]
    """
    # TODO Retourne une liste d'entiers correspondant au meilleur chemin
    # permettant de sortir du labyrinthe en conservant un maximum de son âme,
    # sachant que le visiteur augmente sa coordonnée n à chaque case et ne peut
    # revenir en arrière. Si aucun chemin n'est possible, afficher "IMPOSSIBLE"
    paths = [(plateau[0][i],[i]) for i in range(m)] # liste contenant tous les chemins et initalisée avec le coût au début
    for y in range(1,n):
        print(y)
        new_pathes = []
        for cost, path in paths:
            last_step = path[-1]
            if last_step==0:
                children_paths = [path+[0], path+[1]]
            elif 1<=last_step<=n-2:
                children_paths = [path+[last_step-1], path+[last_step], path+[last_step+1]]
            elif n-1==last_step:
                children_paths = [path+[n-2], path+[n-1]]
            new_pathes += [(cost+plateau[y][child_path[-1]],child_path) for child_path in children_paths if cost+plateau[y][child_path[-1]]<=a]
        # Il faut comparer les chemins menant au même endroite avec leur coût et garder le moins cher
        bests_paths=[]
        for x in range(m):
            all_paths_to_x = [path for path in new_pathes if path[1][-1]==x]
            if len(all_paths_to_x)>0:
                best_path = min(all_paths_to_x)
                bests_paths.append(best_path)
        paths = bests_paths[:]
    
    # *Déterminons le coût de chaque chemin:
    # for cost, path in paths:
    #     print(f"PATH = {path} ; COST = {cost}")
    if len(paths)!=0: #Alors il y a une solution
        print(*min(paths)[1])
    else: 
        print("IMPOSSIBLE")
    


if __name__ == '__main__':
    # a = int(input())
    # n = int(input())
    # m = int(input())
    # plateau = [list(map(int, input().split())) for _ in range(n)]
    with open("big_labyrinthe.txt", "r") as f:
        a = int(f.readline())
        n = int(f.readline())
        m = int(f.readline())
        plateau = [list(map(int, f.readline().split())) for _ in range(n)]
        # print(plateau)
        # for _ in range(n):
        #     line = list(map(int, f.readline().split()))
        #     plateau.append(line)
    # start = time.time()
    # labyrinthe_demoniaque(a, n, m, plateau)
    # print(f"DURÉE 1 = {time.time()-start}")
    start = time.time()
    labyrinthe_demoniaque2(a, n, m, plateau)
    print(f"DURÉE 2 = {time.time()-start}")