/*
* Author:  Léopold Bernard
* Created: 14/10/2024 22:24:56
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

int n, m;
vvi adj;
vvi pred;
map<pii, int> f;
map<pii, int> c;

vb vis;
vi sgn;
vi tovis;
vi pred_path;
vb marked;

bool augment() {
    for (int i=0; i<n; ++i) {
        vis[i] = false;
        sgn[i] = 1;
        pred_path[i] = -1;
    }
    tovis = {0};
    while (!tovis.empty() && pred_path[n-1] == -1) {
        int u = tovis.back();
        tovis.pop_back();
        if (!vis[u]) {
            for (int v: adj[u]) {
                if ((pred_path[v] == -1) && (f[mp(u, v)] < c[mp(u, v)])) {
                    tovis.pb(v);
                    pred_path[v] = u;
                }
            }
            for (int v: pred[u]) {
                if ((pred_path[v] == -1) && (f[mp(v, u)] > 0)) {
                    tovis.pb(v);
                    pred_path[v] = u;
                    sgn[v] = -1;
                }
            }
        }
        vis[u] = true;
    }
    return (pred_path[n-1] != -1);
}

void printFlow() {
    for (int u=0; u<n; ++u) {
        for (int v: adj[u]) {
            cout << u+1 << ' ' << v+1 << ' ' << f[mp(u, v)] << ' ' << c[mp(u, v)] << nl;
        }
    }
}

int ford_fulkerson() {
    vis.assign(n, false);
    sgn.assign(n, 1);
    pred_path.assign(n, -1);
    int u, v;
    // printFlow();
    while (augment()) {
        u = n-1;
        // while (u > 0) {
        //     cout << u << ' ';
        //     u = pred_path[u];
        // }
        // cout << nl;
        int delta = +INF;
        while (u != 0) {
            v = pred_path[u];
            if (sgn[u] == -1) delta = min(delta, f[mp(u, v)]);
            else delta = min(delta, c[mp(v, u)] - f[mp(v, u)]);
            u = v;
        }
        // debug(delta);
        u = n-1;
        while (u != 0) {
            v = pred_path[u];
            if (sgn[u] == -1) f[mp(u, v)] -= delta;
            else f[mp(v, u)] += delta;
            u = v;
        }
    }
    int ans = 0;
    for (int a: adj[0]) {
        ans += f[mp(0, a)];
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m; 
    adj.assign(n, vi());
    pred.assign(n, vi());
    for (int i=0; i<m; ++i) {
        int u, v, cap; cin >> u >> v >> cap;
        --u; --v;
        adj[u].pb(v);
        pred[v].pb(u);
        f[mp(u, v)] = 0;
        c[mp(u, v)] = cap;
    }
    cout << ford_fulkerson() << nl;
	return 0;
}
