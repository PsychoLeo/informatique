import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    l = []
    for i in range (n):
        l.append(list(map(int, read().split())))
    pathFinder(n, l)
    
def pathFinder (n, l):
    # Sorte d'algorithme de Dijkstra
    A = [[0]*n for _ in range (n)]
    A[0][0] = l[0][0]
    for i in range (n):
        for j in range (n):
            if i == 0 :
                A[i][j] = l[i][j] + A[i][j-1]
            if j == 0 :
                A[i][j] = l[i][j] + A[i-1][j]
            else :
                A[i][j] = l[i][j] + max(A[i-1][j], A[i][j-1])
    print (A[-1][-1])

main()