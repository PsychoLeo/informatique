import sys

def read():
    return sys.stdin.readline().strip()

def eulerian_tour_undirected():
    """Eulerian tour on an undirected graph
    :param graph: directed G in listlist format, cannot be listdict
    :assumes: graph is eulerian
    :returns: eulerian cycle as a vertex list
    :complexity: `O(|V|+|E|)`
    """
    # P = [] # resulting tour
    Q = [0] # vertices to be explored, start at 0
    R = [] # path from start node
    next_ = [0] * len(G) # initialize next_ to 0 for each node
    # seen = [set() for _ in G] # mark backward arcs
    while Q:
        start = Q.pop() # explore a cycle from start node
        node = start # current node on cycle
        while next_[node] < len(G[node]): # visit all allowable arcs
            neighbor = G[node][next_[node]] # traverse an arc
            next_[node] += 1 # mark arc traversed
            # if neighbor not in seen[node]: # not yet traversed
                # seen[neighbor].add(node) # mark backward arc
            # G[node].remove(neighbor)
            G[neighbor].remove(node)
            R.append(neighbor) # append to path from start
            node = neighbor # move on
        while R:
            Q.append(R.pop()) # add to Q the discovered cycle R
        print(start+1, end = ' ') # resulting path P is extended
    print()
    # print(' '.join(map(str, P)))

def allPairDegrees():
    for i in G :
        if len(i) % 2 :
            return False
    return True

if __name__ == "__main__" :
    nbNodes, nbEdges = map(int, read().split())
    G = [list() for _ in range (nbNodes)]
    for i in range (nbEdges) :
        A, B = map(int, read().split())
        G[A-1].append(B-1)
        G[B-1].append(A-1)
    if allPairDegrees() : # and isConnexe():
        eulerian_tour_undirected()
    else :
        print (-1)