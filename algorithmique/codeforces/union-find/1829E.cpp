#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define mp make_pair 

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

vector<pii> getNeighbors(int n, int m, int i, int j, vector<vi> &g, vector<vb> &vis) {
    vector<pii> possibleMoves = {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)};
    vector<pii> result;
    for (pii p: possibleMoves) {
        int di = p.first; int dj = p.second;
        if ((0 <= i+di && i+di <n) && (0<=j+dj && j+dj<m) && !vis[i+di][j+dj] && (g[i+di][j+dj] != 0)) {
            vis[i+di][j+dj] = true;
            result.push_back(mp(i+di, j+dj));
        }
    }
    return result;
}

int dfs(int n, int m, int i, int j, vector<vi> &g, vector<vb> &vis) {
    int c = 0;
    vector<pii> toVisit = {make_pair(i, j)};
    while (!toVisit.empty()) {
        pair<int, int> p = toVisit.back();
        toVisit.pop_back();
        i = p.first; j = p.second;
        vis[i][j] = true;
        c += g[i][j];
        for (pii t: getNeighbors(n, m, i, j, g, vis)) {
                toVisit.push_back(t);
        }
    }
    return c;
}

int solve(int n, int m, vector<vi> & g) {
    vector<vb> vis(n, vb(m, false));
    int c = 0; 
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if ((!vis[i][j]) && (g[i][j] != 0)) {
                c = max(c, dfs(n, m, i, j, g, vis));
            }
        }
    }
    return c;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                int x; cin >> x; g[i][j] = x;
            }
        }
        cout << solve(n, m, g) << endl;
    }
}