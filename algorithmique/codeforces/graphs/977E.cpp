#include <iostream>
#include <vector>

using namespace std;

#define MAX 2*100000+5
#define pii pair<int, int>

bool vis[MAX] = {false};
int degre[MAX] = {0};

int solve(int n, vector<vector<int>> &adj) {
    int c = 0;
    for (int node=0; node<n; ++node) {
        if (!vis[node]) {
            vector<int> toVisit = {node};
            int isCycle = 1;
            while (!toVisit.empty()) {
                int currNode = toVisit.back();
                vis[currNode] = true;
                toVisit.pop_back();
                if (degre[currNode] != 2) {
                    isCycle = 0;
                }
                for (int neighb: adj[currNode]) {
                    if (!vis[neighb]) toVisit.push_back(neighb);
                }
            }
            c += isCycle;
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for (int i=0; i<m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        degre[a]++; degre[b]++;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    cout << solve(n, adj) << endl;
}