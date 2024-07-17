import sys

def read():
    return sys.stdin.readline().strip()

def main():
    h, w = map(int, read().split())
    y, x = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range (h)]
    libertes(h, w, x, y, grid)

def libertes (h, w, x, y, grid):
    color = grid[y][x]
    positions = [(x, y)]
    toVisit = [(x, y)]
    visited = [[False]*w for _ in range (h)]
    visited[y][x] = True
    while toVisit :
        x, y = toVisit.pop()
        for X, Y in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)] :
            if 0 <= X < w and 0 <= Y < h :
                if not visited[Y][X] and grid[Y][X] == color :
                    positions.append((X, Y))
                    toVisit.append((X, Y))
                    visited[Y][X] = True
    ################################################
    visited = [[False]*w for _ in range (h)]
    r = 0
    for x, y in positions :
        if not visited[y][x] :
            for X, Y in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)] :
                if 0 <= X < w and 0 <= Y < h:
                    if not visited[Y][X] and grid[Y][X] == 2 :
                        r += 1
                        visited[Y][X] = True
    # print (color)
    print (r)


main()