/*
* Author:  Léopold Bernard
* Created: 19/10/2024 21:27:12
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
vi score;
vvi adj;
vi dist;
vll pf;
vector<pii> distances;

void bfs() {
    vb vis(n, false);
    deque<pii> tovis = {mp(0, 0)};
    while (!tovis.empty()) {
        pii p = tovis.front();
        int u = p.fi, d = p.se;
        tovis.pop_front();
        dist[u] = d;
        vis[u] = true;
        distances.pb(mp(u, d));
        for (int v: adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                tovis.push_back(mp(v, d+1));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
    score.assign(n, 0);
    adj.assign(n, vi());
    dist.assign(n, +INF);
    pf.assign(k+1, 0);
    for (int &x: score) cin >> x;
    for (int i=0; i<m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs();
    pf[0] = score[0];
    int j = 1;
    for (int i=1; i<=k; ++i) {
        pf[i] = pf[i-1];
        while (j < n && distances[j].se <= i) {
            pf[i] += score[distances[j].fi];
            ++j;
        }
    }
    ll ans = 0;
    for (int i=0; i<n; ++i) if (dist[i] <= k) {
        ans = (ans + 1LL * score[i] * pf[k-dist[i]]) % MOD;
    }
    cout << ans << nl;
	return 0;
}
