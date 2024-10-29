import sys

def parcours (dep) :
    node = dep
    path = []
    while visited[node] == -1 :
        visited[node] = 2
        path.append(node)
        node = nxt[node]
    # ici node est le départ d'un cycle si visited[node] = 2
    if visited[node] == 2 :
        visited[node] = 1
        v = nxt[node]
        while v != node :
            visited[v] = 1
            v = nxt[v]
    for v in path :
        if visited[v] == 2 :
            visited[v] = 0


def calculer_dist(i) :
    if visited[i] == 1 :
        d = 1
        node = nxt[i]
        while node != i :
            node = nxt[node]
            d += 1
        nb_redirections[i] = d
        node = nxt[i]
        while node != i :
            nb_redirections[node]
            node = nxt[node]
    else :
        d = 0
        node = i
        while visited[node] != 1 :
            d += 1
            node = nxt[node]
        d += nb_redirections[node]
        node = i
        while visited[node] != 1 :
            nb_redirections[node] = d
            d -= 1
            node = nxt[node]

def fill_redirections () :
    for i in range (n) :
        if nb_redirections[i] == None and visited[i] == 1 :
            calculer_dist(i)
    for i in range (n) :
        if nb_redirections[i] == None and visited[i] == 0 :
            calculer_dist(i)

def greve_generale () :
    for i in range (n) :
        if visited[i] == -1 :
            parcours(i)
    # on a désormais visited[v] = 1 si v est dans
    # un cycle et 0 sinon
    fill_redirections()

if __name__ == "__main__" :
    n = int(input())
    visited = [-1]*n
    nb_redirections = [None]*n
    convertInt = lambda x: int(x)-1
    nxt = list(map(convertInt, sys.stdin.readline().split()))
    greve_generale()
    print(*nb_redirections)