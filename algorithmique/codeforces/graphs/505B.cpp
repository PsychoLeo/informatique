/*
* Author:  Léopold Bernard
* Created: 07/10/2024 23:19:10
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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T> long long sum(const T& a){ return accumulate(a.begin(), a.end(), 0LL); }
template<class T> auto min(const T& a){ return *min_element(a.begin(), a.end()); }
template<class T> auto max(const T& a){ return *max_element(a.begin(), a.end()); }


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

bool dfs(int node, int goal, int c, vb &vis, vector<vvi> &adj) {
    if (node == goal) return true;
    vis[node] = true;
    for (int v: adj[node][c]) {
        if (!vis[v]) if (dfs(v, goal, c, vis, adj)) return true;
    }
    return false;
}

int solve(int n, int m, int u, int v, vector<vvi> &adj) {
    int ans = 0;
    vb vis(n, false);
    for (int c=0; c<m; ++c) {
        if (dfs(u, v, c, vis, adj)) ans++;
        for (int i=0; i<n; ++i) vis[i] = false;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
    vector<vvi> adj(n, vvi(m, vi()));
    for (int i=0; i<m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b; --c;
        adj[a][c].pb(b);
        adj[b][c].pb(a);
    }
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v; --u; --v;
        cout << solve(n, m, u, v, adj) << nl;
    }
	return 0;
}
