import sys
input = sys.stdin.readline

def shapedPlots ():
    r = 0
    for i in range (h) :
        for j in range (w) :
            if grid[i][j] :
                r += shapes(i, j)
    return r

def shapes(i, j):
    up, right, left, down = 0, 0, 0, 0
    fixedI, fixedJ = i, j
    while i >= 0 and grid[i][fixedJ]:
        i -= 1
        up += 1
    while j < w and grid[fixedI][j] :
        j += 1
        right += 1
    i, j = fixedI, fixedJ # resetting  values
    while i < h and grid[i][fixedJ] :
        i += 1
        down += 1
    while j >= 0 and grid[fixedI][j] :
        j -= 1
        left += 1
    # print(f"(y={fixedI}, x={fixedJ}) : left={left} | right={right} | up={up} | down={down}")
    r = 0
    for dx, dy in [(left, up), (left, down), (right, up), (right, down)] :
        i = 2
        c1 = (dx >= 2*i and dy >= i)
        c2 = (dy >= 2*i and dx >= i)
        while c1 or c2 :
            r += c1 + c2
            i += 1
            c1 = (dx >= 2*i and dy >= i)
            c2 = (dy >= 2*i and dx >= i)
    return r


if __name__ == "__main__" :
    t = int(input())
    for i in range (t) :
        h, w = map(int, input().split())
        grid = [list(map(int, input().split())) for _ in range (h)]
        print(f"Case #{i+1}: {shapedPlots()}")