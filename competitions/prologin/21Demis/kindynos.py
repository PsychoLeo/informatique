import sys

def read():
    return sys.stdin.readline().strip()

def main():
    d = int(read())
    grid = []
    for i in range (d) :
        grid.append(list(read()))
    print(countPossible(d, grid))

def countPossible (d, grid):
    r = 0
    for i in range (d):
        for j in range (d) :
            if grid[i][j] == 'I' :
                for I, J in [(i+1, j+1), (i+1, j), (i+1, j-1), (i, j+1), (i,j-1), \
                    (i-1, j+1), (i-1, j), (i-1, j-1)] :
                    if 0 <= I < d and 0 <= J < d and grid[I][J] == '.':
                        r += 1
            elif grid[i][j] == 'C' :
                for I in range (i-2, i+3) :
                    for J in range (j-2, j+3) :
                        if (I, J) != (i, j) and 0 <= I < d and 0 <= J < d and grid[I][J] == '.' :
                            r += 1
            elif grid[i][j] == 'T' :
                for I, J in [(i+1, j), (i-1, j)] :
                    if 0 <= I < d and 0 <= J < d and grid[I][J] == '.':
                        r += 1
    return r

main()