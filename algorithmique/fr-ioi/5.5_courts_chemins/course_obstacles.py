import sys
input = sys.stdin.readline
from heapq import heappop, heappush

def shortestPath () :
    toVisit = [(0, 0, 1)] #  distance à l'origine, x, y
    dist = [[float("inf")]*width for _ in range (height)]
    prec = [[None, None]*width for _ in range (height)]
    black = [[False]*width for _ in range (height)]
    dist[1][0] = 0 # distance à la source est nulle
    while toVisit :
        d, x, y = heappop(toVisit)
        if not black[y][x] :
            black[y][x] = True # On a visité ce noeud
            if y == height-1 and x == width-2:
                add = int(grid[y][x]) if grid[y][x].isnumeric() else 0
                return min(dist[y][x], d+add)
            for X, Y in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)] :
                if 0 <= X < width and 0 <= Y < height and grid[Y][X] != '#':
                    # Si on peut accéder à cette case
                    add = int(grid[y][x]) if grid[y][x].isnumeric() else 0
                    dist_node = d+add
                    if dist_node < dist[Y][X] :
                        dist[Y][X] = dist_node
                        heappush(toVisit, (dist_node, X, Y))

if __name__ == "__main__":
    height, width = map(int, input().split())
    grid = [list(input()) for _ in range (height)]
    print(shortestPath())