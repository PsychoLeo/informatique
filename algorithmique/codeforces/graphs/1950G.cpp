/*
* Author:  Léopold Bernard
* Created: 18/08/2024 17:01:05
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

vvi connectedComponents(int n, vvi &adj) {
    vvi ans;
    vb visited(n, false);
    for (int i=0; i<n; ++i) {
        if (!visited[i]) {
            vi tovis = {i};
            vi component;
            while (sz(tovis) > 0) {
                int node = tovis.back();
                tovis.pop_back();
                component.pb(node);
                visited[node] = true;
                for (int neighb : adj[node]) {
                    if (!visited[neighb]) {
                        tovis.pb(neighb);
                        visited[neighb] = true;
                    }
                }
            }
            ans.pb(component);
        }
    }
    return ans;
}

void dfs(int v, int numvis, int cmpsz, vvi &adj, vb &vis, int &minrmv) {
    vis[v] = true;
    ++numvis;
    minrmv = min(minrmv, cmpsz-numvis);
    for (int u: adj[v]) {
        if (!vis[u]) dfs(u, numvis, cmpsz, adj, vis, minrmv);
    }
    vis[v] = false;
    --numvis;
}

int minRemove(int n, vi &comp, vvi &adj) {
    int ans = n;
    // debug(ans);
    vb vis(n, false);
    int minrmv = INF;
    for (int i=0; i<sz(comp); ++i) {
        int dep = comp[i];
        dfs(dep, 0, sz(comp), adj, vis, minrmv);
    }
    // debug(minrmv);
    return ans+minrmv-sz(comp);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        map<pair<string, string>, vi> equiv;
        for (int i=0; i<n; ++i) {
            string a, b; cin >> a >> b;
            pair<string, string> p = mp(a, b);
            if (equiv.find(p) == equiv.end()) {
                equiv[p] = {i};
            }
            else equiv[p].pb(i);
        }
        vvi adj(n, vi());
        for (auto it = equiv.begin(); it != equiv.end(); ++it) {
            for (int x: it->se) for (int y: it->se) if (x != y) {
                adj[x].pb(y); adj[y].pb(x);
            }
            for (auto it2 = next(it); it2 != equiv.end(); ++it2) {
                if (it->fi.fi == it2->fi.fi || it->fi.se == it2->fi.se) {
                    for (int x: it->se) {
                        for (int y: it2->se) {
                            adj[x].pb(y);
                            adj[y].pb(x);
                        }
                    }
                }
            }
        }
        int res = INF;
        for (vi comp : connectedComponents(n, adj)) {
            // cout << "n : " << n << ", taille comp : " << sz(comp) << nl;
            res = min(res, minRemove(n, comp, adj));
        }
        cout << res << nl;
	}
	return 0;
}
