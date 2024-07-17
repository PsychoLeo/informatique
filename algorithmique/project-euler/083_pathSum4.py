from heapq import heappop, heappush

def dijkstra(G):
    """
    Finds shortest path in the matrix using dijkstra's algorithm
    Returns the total weight of the path
    """
    toVisit = []
    heappush(toVisit, (G[0][0], 0, 0)) # departure point
    visited = [[False]*sz for _ in range (sz)]
    end = sz-1
    while toVisit :
        w, y, x = heappop(toVisit)
        visited[y][x] = True
        for dy, dx in moves :
            if 0 <= y+dy < sz and 0 <= x+dx < sz : # if move is legal
                if y+dy == x+dx == end : # we have reached the end
                    return w+G[end][end]
                elif not visited[y+dy][x+dx] :
                    heappush(toVisit, (w+G[y+dy][x+dx], y+dy, x+dx))

if __name__ == "__main__" :
    sz = 80
    moves = [(-1, 0), (1, 0), (0, 1), (0, -1)]
    M = [list(map(int, input().split())) for _ in range (sz)] # adjacency matrix
    print(dijkstra(M))