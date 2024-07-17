import sys

def read():
    return sys.stdin.readline().strip()

def main():
    h, l, libres = map(int, read().split())
    graph = [list(map(int, read().split())) for _ in range (h)]
    # graph[0][0] = 1
    parcourir(graph, h, l, libres)

def parcourir (graph, h, l, libres): 
    i = 0
    x, y = 0, -1
    while (x, y) != (l-1, h-1) :
        for X, Y in [(x+1, y), (x-1, y), (x, y-1), (x, y+1)] :
            if 0 <= X < l and 0 <= Y < h and graph[Y][X] == 0:
                graph[Y][X] = 1
                i += 1
                if i % (libres+1) == 0 :
                    print (Y, X)
                x, y = X, Y
                break

main()