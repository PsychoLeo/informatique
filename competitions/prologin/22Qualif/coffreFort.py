import sys

def read() :
    return sys.stdin.readline().strip()

def findCycles(G, n) :
    cycles = []
    vis = [False]*n
    pred = [-1]*n
    toVisit = [0]
    while toVisit :
        currNode = toVisit.pop()
        vis[currNode] = True
        for neighb in G[currNode] :
            if neighb != pred[currNode] :
                if vis[neighb] == True :
                    currCycle = []
                    node = currNode
                    while node != pred[neighb] :
                        currCycle.append(node)
                        node = pred[node]
                    cycles.append(currCycle)
                else :
                    toVisit.append(neighb)
                    pred[neighb] = currNode
    return cycles

if __name__ == "__main__" :
    n = int(input())
    m = int(input())
    r = int(input())
    sig = list(map(int, read().split()))
    adj = [[] for _ in range(n)]
    for i in range (m) :
        a, b = map(int, read().split())
        adj[a].append(b)
        adj[b].append(a)
    for i in range (r) :
        a, b = map(int, read().split())
        # Faire quelque chose avec les r
    cycles = findCycles(adj, n)
    for cycle in cycles :
        for node in cycle :
            print(node, end = " ")
        print()
