#include <queue>
#include <stdio.h>
#define MAX_NODES 1000
#define MAX_EDGES 10000
#define inf 1000*1000

using namespace std;

int nbNodes, nbEdges, depNode, endNode;
int w[MAX_NODES][MAX_NODES] = {};
vector<vector<int>> adj(MAX_NODES, vector<int>(0));

void dijkstra () {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toVisit;
    toVisit.push(make_pair(0, depNode));
    int pred[nbNodes]; // pour retourner le chemin à la fin
    int dist[nbNodes];
    fill(dist, dist+nbNodes, inf);
    dist[depNode] = 0;
    bool black[nbNodes] = {false};
    while (!toVisit.empty()) {
        pair<int, int> p = toVisit.top();
        toVisit.pop();
        int dist_node = p.first, node = p.second;
        if (!black[node]) {
            black[node] = true;
            if (node == endNode) {
                break;
            }
            for (int neighbor: adj[node]) {
                int dist_neighbor = dist_node + w[node][neighbor];
                if (dist_neighbor < dist[neighbor]) {
                    dist[neighbor] = dist_neighbor;
                    pred[neighbor] = node;
                    toVisit.push(make_pair(dist_neighbor, neighbor));
                }
            }
        }
    }
    vector<int> r;
    int currNode = endNode;
    while (currNode != depNode) {
        r.push_back(currNode+1);
        currNode = pred[currNode];
    }
    r.push_back(depNode+1);
    printf("%d %d\n", dist[endNode], (int)r.size());
    for (int i=(int)r.size()-1; i>=0; i--) {
        printf("%d ", r[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d %d %d", &nbNodes, &nbEdges, &depNode, &endNode);
    depNode--;
    endNode--;
    for (int i=0; i<nbEdges; i++) {
        int A, B, weight;
        scanf("%d %d %d", &A, &B, &weight);
        A--;
        B--;
        w[A][B] = w[B][A] = weight;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dijkstra();
}