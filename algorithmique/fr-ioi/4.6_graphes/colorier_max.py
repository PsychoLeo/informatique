import sys

def read():
    return sys.stdin.readline().strip()

def main():
    height, width = map(int, read().split())
    grid = []
    for i in range (height) :
        grid.append(list(read()))
    print(connectedComponents(width, height, grid))

def connectedComponents (w, h, grid):
    r = 0
    for y in range (h) :
        for x in range (w) :
            if grid[y][x] == '.' :
                grid = DFS(w, h, x, y, grid)
                r += 1
    return r

def DFS (w, h, x, y, grid):
    toVisit = [(x, y)]
    while toVisit :
        x, y = toVisit.pop()
        grid[y][x] = '#'
        for X, Y in [(x, y+1), (x, y-1), (x+1, y), (x-1, y)]:
            if 0 <= X < w and 0 <= Y < h and grid[Y][X] == '.' :
                toVisit.append((X, Y))
    return grid

main()
