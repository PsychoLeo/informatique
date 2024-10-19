import sys
sys.setrecursionlimit(1000*1000)
input = sys.stdin.readline

nxt_dir = {
    (0, '\\'): 3,
    (1, '\\'): 2,
    (2, '\\'): 1, 
    (3, '\\'): 0,
    (0, '/'):2,
    (1, '/'): 3,
    (2, '/'): 0,
    (3, '/'): 1, 
    (0, '.'): 0, 
    (1, '.'): 1,
    (2, '.'): 2,
    (3, '.'): 3
}

def nextPos(i, j, dir) :
    if dir == 0 :
        return (i-1, j)
    elif dir == 1:
        return (i+1, j)
    elif dir == 2 :
        return (i, j+1)
    return (i, j-1)

def dist(depi, depj, i, j, dir) :
    if i < 0 or i >= l or j < 0 or j >= c :
        return 0
    if d[i][j][dir] > 0 :
        pass
    else :
        nxtdir = nxt_dir[(dir, grid[i][j])]
        (ni, nj) = nextPos(i, j, nxtdir)
        if ni < 0 or ni >= l or nj < 0 or nj >= c:
            d[i][j][dir] = 1
        elif ni == depi and nj == depj :
            d[i][j][dir] = 1
        else : 
            d[i][j][dir] = 1 + dist(depi, depj, ni, nj, nxtdir)
    return d[i][j][dir]

def solve() :
    maxdist = 0
    for i in range (l) :
        for j in range (c) :
            for dir in range(4) :
                maxdist = max(maxdist, dist(i, j, i, j, dir))
    return maxdist


if __name__ == "__main__" :
    l, c = list(map(int, input().split()))
    grid = [None for _ in range(l)]
    for i in range (l) :
        grid[i] = input().strip()
    d = [[[0]*4 for _ in range(c)] for _ in range(l)]
    print(solve())