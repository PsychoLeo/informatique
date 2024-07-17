import sys

def read():
    return sys.stdin.readline().strip()

def main():
    height, width = map(int, read().split())
    grid = [list(read()) for _ in range (height)]
    sys.setrecursionlimit(height*width)
    plusGrandLaser(height, width, grid)

def plusGrandLaser(height, width, grid):
    directions = {'N':(0, -1), 'S':(0, 1), 'E':(1, 0), 'O':(-1, 0)}
    rightbar = {'N':'E', 'S':'O', 'E':'N', 'O':'S'}
    leftbar = {'N':'O', 'S':'E', 'E':'S', 'O':'N'}
    maxSize = 0 # taille maximale du rayon laser
    def distance (x, y, direc) : # distance parcourue à partir de cette position
        nonlocal maxSize
        dist = 0
        depart = (x, y) # position de départ
        boucle = True
        while 0 <= x < width and 0 <= y < height and ((x, y) != depart or boucle):
            boucle = False
            if grid[y][x] == '/' :
                if y+1 < height and direc == 'S':
                    distance(x, y+1, 'S')
                direc = rightbar[direc]
            elif grid[y][x] == '\\' :
                direc = leftbar[direc]
            dx, dy = directions[direc]
            x += dx
            y += dy
            dist += 1
        maxSize = max(maxSize, dist)
    for x in range (width) :
        distance(x, 0, 'S')
        distance(x, height-1, 'N')
    for y in range (height) :
        distance(0, y, 'E')
        distance(width-1, y, 'O')
    print (maxSize)

main()