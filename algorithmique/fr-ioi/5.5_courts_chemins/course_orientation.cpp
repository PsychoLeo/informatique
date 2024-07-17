#include <string>
#include <stdio.h>
#include <vector>

#define NODES 1000
#define EDGES 10*1000
#define inf 1000*1000*1000

using namespace std;

vector<vector<int>> adj(NODES, vector<int>(0, 0));
int w[NODES][NODES];
int nbNodes, nbEdges;

void bellmanFord() {
    int dist[nbNodes];
    fill(dist, dist+nbNodes, +inf);
    int pred[nbNodes] = {};
    dist[0] = 0; // distance to source (always 0) is 0
    for (int i=0; i<nbNodes+2; i++) {
        bool changed = false;
        for (int node=0; node<nbNodes; node++) {
            for (auto neighbor: adj[node]) {
                int alt = dist[node] + w[node][neighbor];
                if (alt < dist[neighbor]) {
                    dist[neighbor] = alt;
                    pred[neighbor] = node;
                    changed = true;
                }
            }
        }
        if (!changed) {
            printf("%d\n", dist[nbNodes-1]);
            return;
        }
    }
    printf("ERREUR\n");
}

int main() {
    scanf("%d %d", &nbNodes, &nbEdges);
    for (int i=0; i<nbEdges; i++) {
        int A, B, weight;
        scanf("%d %d %d", &A, &B, &weight);
        A--; B--;
        w[A][B] = weight;
        adj[A].push_back(B);
    }
    bellmanFord();
}