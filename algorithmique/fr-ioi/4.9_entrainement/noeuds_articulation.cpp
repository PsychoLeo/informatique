#include <cstdio>
#include <vector>

using namespace std;

#define vi vector<int>
#define ll long long ll
#define pb push_back
#define MAX 1000

int nbNodes, nbEdges;
vector<vi> adj(MAX, vi(0, 0));

int main() {
    scanf("%d %d", &nbNodes, &nbEdges);
    for (int i=0; i<nbEdges; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--; B--;
        adj[A].pb(B);
        adj[B].pb(A);
    }
}