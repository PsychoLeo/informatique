# Function for Depth first search
# Traversal of the graph
def dfs(self, graph, s, visited):
    visited[s] = True
    for i in range(len(graph)):
        if graph[s][i] > 0 and not visited[i]:
            self.dfs(graph, i, visited)