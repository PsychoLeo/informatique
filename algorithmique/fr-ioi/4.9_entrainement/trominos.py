def trominos (n, x, y, rot) : # position + rotation
    if n <= 1 :
        dxH, dyH = orientationsHash[rot] # orientation du #
        dxA, dyA = orientationsAt[rot] # orientation du @
        l[y][x] = '*'
        l[y+dyH][x+dxH] = '#'
        l[y+dyA][x+dxA] = '@'
    else :
        trominos(n-1, x, y, rot) # celui-ci est toujours formé
        D, d = 2**n-1, 2**(n-2)
        if rot == 1 : # en haut à gauche
            trominos(n-1, x+d, y+d, 1)
            trominos(n-1, x+D, y, 3)
            trominos(n-1, x, y+D, 0)
        elif rot == 2 : # en bas à droite
            trominos(n-1, x-d, y-d, 2)
            trominos(n-1, x-D, y, 0)
            trominos(n-1, x, y-D, 3)
        elif rot == 3 : # en haut à droite
            trominos(n-1, x-d, y+d, 3)
            trominos(n-1, x, y+D, 2)
            trominos(n-1, x-D, y, 1)
        else : # en bas à gauche
            trominos(n-1, x+d, y-d, 0)
            trominos(n-1, x, y-D, 1)
            trominos(n-1, x+D, y, 2)

if __name__ == "__main__" :
    orientationsHash = [(1, 0), (0, 1), (0, -1), (-1, 0)]
    orientationsAt = [(0, -1), (1, 0), (-1, 0), (0, 1)]
    n = int(input())
    l = [['']*(2**n) for _ in range (2**n)]
    trominos(n, 0, 2**n-1, 0)
    for i in l:
        print(''.join(i))