#include <stdio.h>
#include <vector>
#include <algorithm>

#define SIZE 10000

using namespace std;


vector<vector<pair<int, int>>> pred(SIZE);
int nbNodes, nbEdges, bestScore;
int dist[SIZE]; // distance de 0 à chaque noeud

int kayak (int node) {
    if (dist[node] > 0) { // on a déjà trouvé le chemin pour ce noeud
        return dist[node];
    }
    else {
        int maxDist = 0;
        for (pair<int, int> p: pred[node]) {
            int predNode = p.first, predDist = p.second; 
            maxDist = max(maxDist, predDist+kayak(predNode));
        }
        dist[node] = maxDist;
        return maxDist;
    }
}

int main() {
    fill(dist, dist+SIZE, -1);
    dist[0] = 0;
    scanf("%d %d",&nbNodes, &nbEdges);
    for (int i=0; i<nbEdges; i++) {
        int depNode, endNode, w;
        scanf("%d %d %d", &depNode, &endNode, &w);
        pred[endNode-1].push_back(make_pair(depNode-1, w));
    }
    // printArray();
    printf("%d\n", kayak(nbNodes-1));
}