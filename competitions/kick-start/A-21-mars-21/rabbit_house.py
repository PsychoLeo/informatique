from heapq import heappop, heappush

import sys
input = sys.stdin.readline

def rabbitHouse (row, col, grid):
    toVisit = []
    for i in range (row) :
        for j in range (col) :
            for y, x in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)] :
                if 0 <= x < col and 0 <= y < row :
                    if abs(grid[i][j]-grid[y][x]) > 1:
                        toVisit.append((i, j, y, x)) 
                        break
    r = 0
    while toVisit :
        i, j, y, x = toVisit.pop()
        if abs(grid[i][j]-grid[y][x]) > 1: 
            bestDeltaAdj = float("+inf")
            bestNewHeight = None
            for d in [-1, 1] :
                deltaAdj = 0
                newHeight = grid[y][x]+d
                for neighbY, neighbX in [(i+1, j), (i-1, j), (i, j-1), (i, j+1)] :
                    if 0 <= neighbX < col and 0 <= neighbY < row :
                        deltaAdj += abs(newHeight-grid[neighbY][neighbX])
                if deltaAdj < bestDeltaAdj :
                    bestNewHeight = newHeight
            
            
    return r



if __name__ == "__main__" :
    t = int(input())
    for i in range (t) :
        row, col = map(int, input().split())
        grid = [list(map(int, input().split())) for _ in range (row)]
        print(f"Case #{i+1}: {rabbitHouse(row, col, grid)}")