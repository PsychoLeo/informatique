/*
* Author:  Léopold Bernard
* Created: 14/10/2024 21:25:02
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <random>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define nl "\n"

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvl;

#define DEBUG true
#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF (int)1e9

int n, m, k;
vvb used;
vvi adj;
vvi pred;

void dfs1() {
    vi tovis = {0};
    vb vis(n, false);
    while (!tovis.empty()) {
        bool found = false;
        int u = tovis.back();
        tovis.pop_back();
        vis[u] = true; // le noeud considéré est sur notre chemin
        if (u == n-1) return;
        for (int v: adj[u]) {
            if (!used[u][v] && !vis[v]) {
                found = true;
                used[u][v] = true;
                tovis.push_back(v);
                break;
            }
        }
        if (!found) {
            // on doit prendre un autre chemin à un moment, donc on ne doit pas passer par le noeud u
            for (int v: pred[u]) {
                if (used[v][u] && v != 0) {
                    used[v][u] = false;
                    tovis.push_back(v);
                    break;
                }
            }
        }
    }
}

void dfs2() {
    int u = 0;
    vi ans = {0};
    while (u != n-1) {
        for (int v: adj[u]) if (used[u][v]) {
            used[u][v] = false;
            u = v;
        }
        ans.pb(u);
    }
    cout << ans.size() << nl;
    for (int v: ans) cout << v+1 << nl;
}

void printgrid() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) cout << (int)used[i][j] << ' ';
        cout << nl;
    }
}

void solve() {
    // printgrid();
    for (int i=0; i<k; ++i) {
        dfs1();
        // printgrid();
        // cout << nl;
    }
    // printgrid();
    for (int i=0; i<k; ++i) {
        dfs2();
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
    used.assign(n, vb(n, false));
    adj.assign(n, vi());
    pred.assign(n, vi());
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        pred[v].pb(u);
    }
    solve();
	return 0;
}
