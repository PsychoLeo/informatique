def main() :
    l, h = map(int, input().split())
    grid = []
    for _ in range (h) :
        grid.append(list(input()))
    peutInverser(grid, h, l)

def peutInverser(grid, h, l):
    pred = set()
    moves = [(0, 0, l-1, h-1)] # black position / white position
    while moves : # while there are possible moves => DFS
        xb, yb, xw, yw = moves.pop()
        neighbors = (xb, yb) in [(xw, yw), (xw+1, yw), (xw-1, yw), (xw, yw-1), (xw, yw+1)]
        if neighbors : # if both pieces are neighbors
            print (1); return
        for x, y in [(xb+1, yb), (xb-1, yb), (xb, yb+1), (xb, yb-1)] :
            if 0 <= x < l and 0 <= y < h :
                for X, Y in [(xw+1, yw), (xw-1, yw), (xw, yw+1), (xw, yw-1)] :
                    if 0 <= X < l and 0 <= Y < h :
                        if ((X, Y) == (0, 0) and (x, y) == (l-1, h-1)) : # we have reached the goal
                            print (1); return # end the program
                        elif grid[Y][X] == grid[y][x] and ((x, y, X, Y) not in pred):
                            pred.add((x, y, X, Y))
                            moves.append((x, y, X, Y))
    print (0)

main()