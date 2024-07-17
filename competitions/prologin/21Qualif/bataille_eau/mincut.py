# Returns the min-cut of the given graph
def minCut(self, source, sink):
    # This array is filled by BFS and to store path
    parent = [-1] * (self.ROW)
    max_flow = 0  # There is no flow initially
    # Augment the flow while there is path from source to sink
    print (self.BFS(source, sink))
    while self.BFS(source, sink):
        # Find minimum residual capacity of the edges along the
        # path filled by BFS. Or we can say find the maximum flow
        # through the path found.
        path_flow = float("Inf")
        s = sink
        while (s != source):
            path_flow = min(path_flow, self.graph[parent[s]][s])
            s = parent[s]
        # Add path flow to overall flow
        max_flow += path_flow
        # update residual capacities of the edges and reverse edges
        # along the path
        v = sink
        while v != source:
            u = parent[v]
            self.graph[u][v] -= path_flow
            self.graph[v][u] += path_flow
            v = parent[v]

    visited = len(self.graph) * [False]

    # print the edges which initially had weights
    # but now have 0 weight
    n, result = 0, [] # number of paths to delete
    for i in range(self.ROW):
        for j in range(self.COL):
            if self.graph[i][j] == 0 and self.org_graph[i][j] > 0 and visited[i]:
                result.append(str(i) + ' ' + str(j))
                n += 1 # adding one to the final variable
    print (n)
    print('\n'.join(result))