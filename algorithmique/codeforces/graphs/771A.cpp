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
#define rep(i, a, b) for(int i=a; i<(b); ++i)

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
#define INF 

string solve(int n, vvi &adj) {
	int c = 0; // nombre de composantes connexes
	vb vis(n, false);
	vi component_size;
	vi component(n, 0);
	rep(i, 0, n) {
		if (!vis[i]) {
			int sz = 0;
			vi tovis = {i};
			while (!tovis.empty()) {
				int node = tovis.back();
				tovis.pop_back();
				vis[node] = true;
				component[node] = c;
				++sz;
				for (int neighb : adj[node]) {
					if (!vis[neighb]) {
						tovis.push_back(neighb);
						vis[neighb] = true;
					}
				}
			}
			component_size.push_back(sz);
			++c;
		}
	}
	rep(i, 0, n) {
		int compi = component[i];
		if ((int)adj[i].size() != component_size[compi]-1) return "NO";
	}
	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vvi adj(n, vi());
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << solve(n, adj) << "\n";
	return 0;
}
