import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    adjMatr = []
    for i in range (n):
        adjMatr.append(list(map(int, read().split())))
    print (nbTriangles(n, adjMatr))
    
def nbTriangles (n, adjMatr):
    listAdj = []
    r = 0
    for i in range (n):
        l = []
        for j in range (n) :
            if adjMatr[i][j] :
                l.append(j)
        listAdj.append(l)
    visited = [[[False]*n for _ in range (n)] for i in range (n)]
    for i in range (n) :
        for j in range (len(listAdj[i])-1) :
            if listAdj[j] in listAdj[j+1] and not \
                visited[j][listAdj[j]][listAdj[j+1]] :
                r += 1
                visited[j][listAdj[j]][listAdj[j+1]] = True
                visited[j][listAdj[j+1]][listAdj[j]] = True
                visited[listAdj[j]][listAdj[j+1][j]] = True
                visited[listAdj[j]][j][listAdj[j+1]] = True
                visited[listAdj[j+1]][listAdj[j]][j] = True
                visited[listAdj[j+1]][j][listAdj[j]] = True
    return r




main()