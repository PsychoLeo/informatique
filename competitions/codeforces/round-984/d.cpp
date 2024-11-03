/*
* Author:  Léopold Bernard
* Created: 02/11/2024 16:04:43
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

bool isvalid(vvi &grid, vector<pii> &a, int i) {
	int mod = sz(a);
	return (grid[a[i].fi][a[i].se] == 1 && grid[a[(i+1)%mod].fi][a[(i+1)%mod].se] == 5 && grid[a[(i+2)%mod].fi][a[(i+2)%mod].se] == 4 && grid[a[(i+3)%mod].fi][a[(i+3)%mod].se] == 3);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >>m;
		vvi grid(n, vi(m));
		for (int i=0; i<n; ++i) {
			string s; cin >> s;
			for (int j=0; j<m; ++j) grid[i][j] = (s[j]-'0');
		}
		int ans = 0;
		for (int l=0; l<min(n, m)/2; ++l) {
			// for every traversal
			vector<pii> tocheck;
			for (int j=l; j<m-1-l; ++j) tocheck.pb(mp(l, j));
			for (int i=l; i<n-1-l; ++i) tocheck.pb(mp(i, m-1-l));
			for (int j=m-1-l; j>l; --j) tocheck.pb(mp(n-1-l, j));
			for (int i=n-1-l; i>l; --i) tocheck.pb(mp(i, l));
			for (int j=0; j<sz(tocheck); ++j) {
				if (isvalid(grid, tocheck, j)) ans++;
			}
		}
		cout << ans << nl;
	}
	return 0;
}
