#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 500
#define fo(k, n) for(int k=0; k<n; k++)
#define inf 1000*1000*1000

using namespace std;

int nbNodes, nbEdges;
int w[MAX][MAX] = {};

void floydWarshall() {
    fo (k, nbNodes) {
        fo (u, nbNodes) {
            fo (v, nbNodes) {
                w[u][v] = min(w[u][v], w[u][k] + w[k][v]);
            }
        }
    }
}

void fillArray() {
    fo (i, MAX) {
        fo (j, MAX) {
            if (i != j) {
                w[i][j] = +inf;
            }
        }
    }
}

void printArray() {
    fo (i, nbNodes) {
        fo (j, nbNodes) {
            if (j == nbNodes-1) {
                printf("%d\n", w[i][j]);
            }
            else {
                printf("%d ", w[i][j]);
            }
        }
    }
}

int main() {
    scanf("%d %d", &nbNodes, &nbEdges);
    fillArray();
    for (int i=0; i<nbEdges; i++) {
        int A, B, wg;
        scanf("%d %d %d", &A, &B, &wg);
        A--; B--;
        w[A][B] = wg;
        w[B][A] = wg;
    }
    floydWarshall();
    printArray();
}