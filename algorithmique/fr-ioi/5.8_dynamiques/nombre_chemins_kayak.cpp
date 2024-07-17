#include <stdio.h>
#include <vector>
#define SIZE 10000

using namespace std;

int nbNodes, nbEdges, nbPaths;
vector<vector<int>> pred(SIZE);
int diffPaths[SIZE]; // different paths leading to each point

int differentPaths (int node) {
    if (diffPaths[node] != 0) {
        return diffPaths[node];
    }
    else {
        int sum = 0;
        for (int predNode: pred[node]) {
            sum += differentPaths(predNode);
        }
        diffPaths[node] = sum;
        return sum;
    }
}

int main() {
    fill(diffPaths, diffPaths+SIZE, 0);
    diffPaths[0] = 1;
    scanf("%d %d", &nbNodes, &nbEdges);
    for (int i=0; i<nbEdges; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        pred[B-1].push_back(A-1);
    }
    printf("%d\n", differentPaths(nbNodes-1));
}