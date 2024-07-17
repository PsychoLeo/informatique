import sys

def read() :
    return sys.stdin.readline().strip()

def main() :
    """
    Initialisation et remplissage de la grille
    """
    billes = [] # coordonnées x, y des billes
    lignes, colonnes = map(int, input().split())
    grid = []
    for i in range (lignes) :
        currLine = list(read())
        for j in range (colonnes) :
            if currLine[j] == 'x' :
                billes.append([j, i])
        grid.append(currLine)
    nCmd = int(read())
    commands = read()
    """
    Fin de l'initialisation
    """
    for k in range (nCmd) :
        # print (billes)
        # Printing grid to debug : 
        # for line in grid :
        #     print (''.join(line))
        for x, y in billes :
            grid[y][x] = '.'
        # print ()
        cmd = commands[k]
        i = 0
        if cmd == 'S' : # sud => descendre
            billes.sort(key = lambda e: e[1], reverse=True)
            while i < len(billes) :
                x, y = billes[i][0], billes[i][1]
                while grid[y+1][x] == '.' :
                    y += 1
                if grid[y+1][x] == 'O' :
                    del billes[i]
                else :
                    billes[i] = [x, y]
                    grid[y][x] = 'x'
                    i += 1
        elif cmd == 'E' : # est => droite
            billes.sort(key = lambda e: e[0], reverse=True)
            while i < len(billes) :
                x, y = billes[i][0], billes[i][1]
                while grid[y][x+1] == '.' :
                    x += 1
                if grid[y][x+1] == 'O' :
                    del billes[i]
                else :
                    billes[i] = [x, y]
                    grid[y][x] = 'x'
                    i += 1
        elif cmd == 'N' : # nord => monter
            billes.sort(key = lambda e: e[1])
            while i < len(billes) :
                x, y = billes[i][0], billes[i][1]
                while grid[y-1][x] == '.' :
                    y -= 1
                if grid[y-1][x] == 'O' :
                    del billes[i]
                else :
                    billes[i] = [x, y]
                    grid[y][x] = 'x'
                    i += 1
        else : # ouest => gauche
            billes.sort(key = lambda e: e[0])
            while i < len(billes) :
                x, y = billes[i][0], billes[i][1]
                while grid[y][x-1] == '.' :
                    x -= 1
                if grid[y][x-1] == 'O' :
                    del billes[i]
                else :
                    billes[i] = [x, y]
                    grid[y][x] = 'x'
                    i += 1
    print (len(billes))

main()