/*
* Author:  Léopold Bernard
* Created: 20/10/2024 11:01:40
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
#define INF (ll)1e18

ll n;
vll a;
vll b;
vll pf;
vector<vector<pll>> adj;
vll d;

void dijkstra() {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(mp(0LL, 0LL));
    d.assign(n, +INF);  // Reset the distance vector
    d[0] = 0LL;

    while (!pq.empty()) {
        pll p = pq.top();
        pq.pop();
        ll u = p.se, dist = p.fi;

        // Skip if this distance is already higher than the stored one
        if (dist > d[u]) continue;

        for (pll p2 : adj[u]) {
            ll v = p2.fi, distv = p2.se;
            if (d[v] > d[u] + distv) {
                d[v] = d[u] + distv;
                pq.push(mp(d[v], v));
            }
        }
    }
}

void init() {
	pf.resize(n+1);
	pf[0] = 0LL;
	for (int i=1; i<=n; ++i) {
		pf[i] = pf[i-1] + a[i-1];
	}
	adj.assign(n, vector<pll>());
	for (int i=0; i<n; ++i) {
		if (b[i] > i) adj[i].pb(mp(b[i], a[i]));
		if (i > 0) adj[i].pb(mp(i-1, 0));
	}
}

ll solve() {
	init();
	dijkstra();
	ll ans = 0;
	for (int i=0; i<n; ++i) {
		// debug(i);
		// debug(pf[i+1]);
		// debug(d[i]);
		ans = max(ans, pf[i+1]-d[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		a.resize(n);
		b.resize(n);
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) {
			ll x; cin >> x; --x; b[i] = x;
		}
		cout << solve() << nl;
	}
	return 0;
}
