/*
* Author:  Léopold Bernard
* Created: 11/08/2024 14:10:16
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
#define rep(i, a, b) for(int i=a; i<(b); ++i)
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
#define INF 

ll solve(int n, int m, int k, int d, vvi &a) {
	// dp[i][j] = min we have to build if we put a bridge on j (in row i)
	// dp[i][j] = min(dp[i][j-1], dp[i][j], ..., dp[i][max(0, j-d)]) + a[i][j] + 1
	vector<vll> dp(n, vll(m, 0));
	for (int i=0; i<n; ++i) {
		map<ll, set<int>> prev;
		dp[i][0] = 1;
		prev[1] = {0};
		for (int j=1; j<m; ++j) {
			auto mx = prev.begin();
			ll v = a[i][j] + 1 + mx->first;
			dp[i][j] = v;
			if (j > d) {
				ll rm_val = dp[i][j-d-1];
				prev[rm_val].erase(j-d-1);
				if (sz(prev[rm_val]) == 0) prev.erase(rm_val);
			}
			if (prev.find(v) == prev.end()) prev[v].emplace(j);
			else prev[v] = {j};
		}
	}
	ll currsum = 0;
	for (int i=0; i<k; ++i) currsum += dp[i][m-1];
	ll ans = currsum;
	for (int i=k; i<n; ++i) {
		currsum += dp[i][m-1] - dp[i-k][m-1];
		chmin(ans, currsum);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k, d; cin >> n >> m >> k >> d;
		vvi a(n, vi(m));
		for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) cin >> a[i][j];
		cout << solve(n, m, k, d, a) << nl;
	}
	return 0;
}
