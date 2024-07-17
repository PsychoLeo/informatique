def connectedComponents (width, height, graph, free='#') :
    nbConnected = 0
    for i in range (height) :
        for j in range (width) :
            if graph[i][j] == free :
                nbConnected += 1
                dfs (graph, width, height, i, j, free, str(nbConnected))
    for row in graph :
        print (''.join(row))

def dfs (graph, width, height, y, x, free, marker) :
    toGo = [(x, y)]
    while toGo :
        x, y = toGo.pop()
        graph[y][x] = marker
        for X, Y in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)] :
            if 0 <= X < width and 0 <= Y < height and graph[Y][X] == free :
                toGo.append((X, Y))

if __name__ == "__main__" :
    width, height = int(input()), int(input())
    l = []
    for _ in range (height) :
        l.append(list(input()))
    connectedComponents(width, height, l)