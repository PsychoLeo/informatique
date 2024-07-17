def main() :
    l, h = map(int, input().split())
    grid = []
    for _ in range (h) :
        grid.append(list(input()))
    peutInverser(grid, h, l)

def peutInverser(grid, h, l):
    moves = [(0, 0, l-1, h-1)] # black position / white position
    whiteVis = [[False]*l for _ in range (h)] # car il nous est égal de savoir comment on est arrivé à une case
    blackVis = [[False]*l for _ in range (h)]
    while moves : # while there are possible moves => DFS
        # print(moves)
        xb, yb, xw, yw = moves.pop()
        for x, y in [(xb+1, yb), (xb-1, yb), (xb, yb+1), (xb, yb-1)] :
            if 0 <= x < l and 0 <= y < h :
                for X, Y in [(xw-1, yw), (xw+1, yw), (xw, yw-1), (xw, yw+1)] :
                    if 0 <= X < l and 0 <= Y < h :
                        neighbors = (x, y) in [(X, Y), (X+1, Y), (X-1, Y), (X, Y-1), (X, Y+1)] # if both pieces are neighbors
                        if ((X, Y) == (0, 0) and (x, y) == (l-1, h-1)) or neighbors : # or neighbors: # we have reached the goal
                            print (1); return # end the program
                        elif grid[Y][X] == grid[y][x] and (not whiteVis[Y][X] or not blackVis[y][x]) :
                            whiteVis[Y][X] = True
                            blackVis[y][x] = True
                            moves.append((x, y, X, Y))
    print (0)

main()