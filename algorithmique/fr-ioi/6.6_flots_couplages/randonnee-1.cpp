/*
* Author:  Léopold Bernard
* Created: 08/10/2024 21:31:05
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


#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF (int)1e9

bool augment(int n, int p, vvi &adj, vb &paired, vvb &mk, int dep) {
    vi tovis = {dep};
    unordered_set<int> vis;
    vi pred(n, -1);
    pred[dep] = dep;
    while (!tovis.empty()) {
        int u = tovis.back();
        tovis.pop_back();
        if (!paired[u] && (u >= p)) {
            debug(u);
            paired[u] = true;
            mk[pred[u]][u-p] = true;
            u = pred[u];
            while (pred[u] != u) {
                mk[u][pred[u]-p] = false;
                u = pred[u];
                mk[pred[u]][u-p] = true;
                u = pred[u];
            }
            paired[u] = true;
            return true; // found augmenting path
        }
        vis.emplace(u);
        for (int v: adj[u]) {
            if ((vis.find(v) == vis.end()) && ((u<p) || mk[v][u-p])) {
                // debug(v); debug(u);
                vis.emplace(v);
                tovis.push_back(v);
                pred[v] = u;
            }
        }
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p, v, m; cin >> p >> v >> m;
    int n = p+v;
    int cnt = 0;
    vvi adj(n, vi());
    vb paired(n, false);
    vvb mk(p, vb(v, false));
    for (int i=0; i<m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b+p);
        adj[b+p].push_back(a);
        if (!paired[a] && !paired[b+p]) {
            paired[a] = true;
            paired[b+p] = true;
            mk[a][b] = true;
            cnt++;
        }
    }
    debug(cnt);
    for (int i=0; i<p; ++i) {
        if (!paired[i] && augment(n, p, adj, paired, mk, i)) {
            cnt++;
        }
    }
    cout << cnt << nl;
	return 0;
}
