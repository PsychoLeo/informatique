#include <stdio.h>
#include <vector>
#define size 1000
#define tMax 500
#define inf 1000*1000*1000

using namespace std;

// TODO Global variables
vector<vector<int>> adj(size, vector<int>());
int weight[size][size];
int nbNodes, nbEdges, depNode, time;
int dp[tMax+1][size];

void fillWeights () {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            weight[i][j] = 0;
        }
    }
}

void fillDp () {
    for (int i=0; i<tMax+1; i++) {
        for (int j=0; j<size; j++) {
            dp[i][j] = -inf;
        }
    }
}

int maxPoints () {
    dp[0][depNode] = 0; // only place we have access to
    for (int i=0; i<time; i++) {
        for (int j=0; j<nbNodes; j++) {
            if (dp[i][j] > -inf) { // if we have access to it
                for (int neighbor: adj[j]) {
                    if (dp[i][j] + weight[j][neighbor] > dp[i+1][neighbor]) {
                        // We have found a better path (more points to get) for this neighbor
                        dp[i+1][neighbor] = dp[i][j] + weight[j][neighbor];
                    }
                }
            }
        }
    }
    int max = -inf;
    for (int j=0; j<nbNodes; j++) {
        if (dp[time][j] > max) {
            max = dp[time][j];
        }
    }
    return max;
}

int main() {
    fillWeights(); // fill weight with 0
    fillDp(); // fill dp with -inf
    scanf("%d %d %d %d", &nbNodes, &nbEdges, &depNode, &time);
    depNode--;
    for (int i=0; i<nbEdges; i++) {
        int A, B, w;
        scanf("%d %d %d", &A, &B, &w);
        A--;
        B--;
        weight[A][B] = w;
        adj[A].push_back(B);
    }
    for (int i=0; i<nbNodes; i++) {
        adj[i].push_back(i); // on peut rester sur une case
    }
    printf("%d\n", maxPoints());
}