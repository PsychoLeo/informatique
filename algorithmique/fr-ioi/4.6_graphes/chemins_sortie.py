import sys

r = 0

def input():
    return sys.stdin.readline().strip()

def main():
    h, w = map(int, input().strip().split())
    grid = []
    for i in range (h):
        grid.append(list(input()))
    cheminSortie(h, w, grid, 0, 1)

def cheminSortie(h, w, grid, x, y):
    global r
    if (x, y) != (w-2, h-1) :
        for X, Y in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)] :
            if 0 <= X < w and 0 <= Y < h :
                if grid[Y][X] == '.' :
                    grid[y][x] = '#'
                    cheminSortie(h, w, grid, X, Y)
                    grid[y][x] = '.'
    else :
        r += 1

main()
print (r)