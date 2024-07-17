#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define ull unsigned long long int
#define vi vector<int>
#define pii pair<int, int>
#define mod 1'671'404'011

/*
Algorithme et idée :

==> On remarque que les cycles dans le graphe peuvent être réduits à un seul noeud (dont le signal vaut le produit des signaux du cycle).
Une fois tous les cycles réduits en noeuds, il nous reste un graphe sans cycles, qui est un arbre (c'est ici que commence le PB4).

==> Dans l'arbre, le chemin entre 2 noeuds est unique. En choisissant arbitrairement une racine pour notre arbre, on peut avec un algorithme de complexité logarithmique trouver à chaque fois le chemin entre deux noeuds (on remonte les prédecesseurs dans l'abre de manière à toujours être à la même profondeur et lorsque l'on trouve un noeud en commun, on a trouvé l'intersection, donc un chemin). On multiplie ensuite les poids des noeuds (qui sont parfois des anciens cycles), ce qui nous donne le résultat

Mon algorithme a une complexité O(R*N) 
NB : cette complexité ne fonctionne pas, mais je suis en train d'essayer de trouver une complexité convenable O(R*log(N))
*/

vector<int> buildTree(vector<vector<int>> G, int n) {
    /*
    Construction de l'arbre par parcours DFS en O(N + M) = O(N) car N = M+1
    */
    bool visited[n] = {false};
    vector<int> toVisit = {0}; // parcours DFS
    vector<int> tree(n); // tree[0] = 0 (on considère que 0 est la racine)
    while (!toVisit.empty()) {
        int currNode = toVisit.back();
        toVisit.pop_back();
        visited[currNode] = true;
        for (int neighb : G[currNode]) {
            if (!visited[neighb]) {
                tree[neighb] = currNode; // construction de l'arbre
                toVisit.push_back(neighb);
            }
        }
    }
    return tree;
}

int findDepth(int depth[], vector<int> tree, int node) {
    /*
    Fonction récursive pour trouver la profondeur de tous les points dans notre arbre. Complexité O(N)
    */
    if (tree[node] == 0) { // si on est à la racine
        depth[node] = 1;
        return 1;
    }
    else if (depth[node] != -1) { // si on a déjà visité
        return depth[node];
    }
    depth[node] = 1 + findDepth(depth, tree, tree[node]); 
    return depth[node];
}

int findSignalLin(int A, int B, vi tree, int sig[], int depth[]) {
    /*
    Algorithme en O(N) pire cas pour trouver le produit des signaux des puces entre deux puces A et B
    https://cp-algorithms.com/graph/lca.html
    */
    ull prod = 1;
    while (depth[B] > depth[A]) { // on part de la même profondeur
        prod = (prod * sig[B]) % mod;
        B = tree[B];
    }
    while (depth[A] > depth[B]) {
        prod = (prod * sig[A]) % mod;
        A = tree[A];
    }
    while (A != B) { // tant que l'on a pas un prédecesseur commun
        prod = (((prod * sig[A]) % mod) * sig[B]) % mod;
        A = tree[A];
        B = tree[B];
    }
    prod = (prod * sig[A]) % mod;
    return (int)prod;
}

int main() {
    int n, m, r; // noeuds, arêtes, requêtes
    scanf("%d %d %d", &n, &m, &r);
    int sig[n]; // signaux
    for (int i=0; i<n; i++) {
        scanf("%d", &sig[i]);
    }
    vector<vector<int>> adj(n, vector<int>()); // liste d'adjacence
    for (int i=0; i<m; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    vector<int> tree = buildTree(adj, n); // arbre
    int depth[n]; // liste des profondeurs de chaque noeud
    fill(depth, depth+n, -1);
    depth[0] = 0; // racine de notre arbre
    for (int i=1; i<n; i++) {
        if (depth[i] == -1) { // si le point n'a pas été visité
            findDepth(depth, tree, i);
        }
    }
    for (int i=0; i<r; i++) {
        int a, b; // requêtes
        scanf("%d %d", &a, &b);
        printf("%d\n", findSignalLin(a, b, tree, sig, depth));
    }
}