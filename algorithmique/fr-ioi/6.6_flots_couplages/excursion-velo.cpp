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

#define DEBUG true
#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF (int)1e9

bool augment(int p, vvi &adj, vb &paired, vvb &mk, int dep) {
    vi tovis = {dep};
    unordered_set<int> vis;
    while (!tovis.empty()) {
        int u = tovis.back();
        tovis.pop_back();
        if (!paired[u] && (u >= p)) return true; // found augmenting path
        vis.emplace(u);
        for (int v: adj[u]) {
            if ((vis.find(v) == vis.end()) && ((u<p) || mk[v][u-p])) {
                // debug(v); debug(u);
                vis.emplace(v);
                tovis.push_back(v);
            }
        }
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p, v, m; cin >> p >> v >> m;
    int n = p+v;
    vvi adj(n, vi());
    vb marked(n, false);
    vvb mk(p, vb(v, false));
    for (int i=0; i<m; ++i) {
        int a, b, cp; cin >> a >> b >> cp;
        adj[a].push_back(b+p);
        adj[b+p].push_back(a);
        mk[a][b] = (bool)cp;
        if (cp == 1) {
            marked[a] = true;
            marked[b+p] = true;
        }
    }
    bool found = false;
    for (int i=0; i<p; ++i) {
        if (!marked[i] && augment(p, adj, marked, mk, i)) {
            cout << "NON" << nl;
            // debug(i);
            found = true;
            break;
        }
    }
    if (!found) cout << "OUI" << nl;
	return 0;
}
