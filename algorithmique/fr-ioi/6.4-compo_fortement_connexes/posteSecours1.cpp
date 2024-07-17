#include <cstdio>
#include <vector>

using namespace std;

int nbInter, nbChemins;
vector<vector<int>> adj; // liste d'adj du graphe
vector<int> nbAccess;

void fillArrays() {
    scanf("%d %d", &nbInter, &nbChemins);
    for (int i=0; i<nbInter; i++) {
        vector<int> l;
        adj.push_back(l);
    }
    // Take input
    for (int i=0; i<nbChemins; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--; B--;
        adj[A].push_back(B);
    }
}

int nbAccessibles(int node, vector<bool> vis) {
    // printf("%d\n", node+1);
    if (nbAccess[node] != -1) {
        return nbAccess[node];
    }
    int score = 0;
    vis[node] = true;
    for (int neighb: adj[node]) {
        // printf("Neighbor of %d: %d\n", node+1, neighb+1);
        if (!vis[neighb]) {
            score += 1 + nbAccessibles(neighb, vis);
            vis[neighb] = false;
        }
    }
    nbAccess[node] = score;
    return score;
}   

int main() {
    fillArrays();
    // for (int i=0; i<nbInter; i++) {
    //     nbAccess.push_back(-1);
    // }

    // for (int i=0; i<nbInter; i++) {
    //     if (nbAccess[i] == -1) {
    //         vector<bool> visited(nbInter);
    //         fill(visited.begin(), visited.end(), false);
    //         nbAccessibles(i, visited);
    //     }
    // }
    // int count = 0;
    // vector<int> res;
    // for (int i=0; i<nbInter; i++) {
    //     if (nbAccess[i] >= nbInter-1) {
    //         res.push_back(i+1);
    //         count++;
    //     }
    // }
    // for (int i=0; i<nbInter; i++) {
    //     printf("Intersection %d: %d acces\n", i+1, nbAccess[i]);
    // }
    // printf("%d\n", count);
    // for (int e: res) {
    //     printf("%d ", e);
    // }
    // printf("\n");
}