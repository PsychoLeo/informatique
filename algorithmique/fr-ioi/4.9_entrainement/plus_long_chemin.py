import sys

def read():
    return sys.stdin.readline().strip()

def main():
    height, width = map(int, read().split())
    grid = [list(read()) for _ in range (height)]
    bestLen = 0
    bestPath = ""
    def longestPath(x, y, length, path) :
        nonlocal bestLen, bestPath
        if x == width-2 and y == height-1 and length >= bestLen :
            if len(path) > len(bestPath) :
                bestLen = length
                bestPath = path
            elif length == bestLen and path <= bestPath:
                bestLen = length
                bestPath = path
        moves = {(x+1, y):"E", (x-1, y):"O", (x, y+1):"S", (x, y-1):"N"}
        for X, Y in moves :
            if 0 <= X < width and 0 <= Y < height and grid[Y][X] == '.' :
                grid[Y][X] = '#'
                longestPath(X, Y, length+1, path+moves[(X, Y)])
                grid[Y][X] = '.'
    longestPath(0, 1, 0, "")
    print(bestLen)
    print(bestPath)

main()