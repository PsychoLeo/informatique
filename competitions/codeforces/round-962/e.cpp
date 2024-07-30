/*
* Author:  Léopold Bernard
* Created: 26/07/2024 16:21:17
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
#define debug(x) cout << #x << "=" << x << "\n";
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 

ll solve(string &s) {
	// Algorithm in O(n log n)
	int n = sz(s);
	vi delta(n+1, 0); // delta[i] = (n0[i] - n1[i])
	rep(i, 1, n+1) delta[i] = delta[i-1] + ((s[i-1] == '0') ? 1 : -1);
	vector<pii> delta_with_index;
	rep(i, 1, n+1) delta_with_index.pb(mp(delta[i], i));
	sort(all(delta_with_index));
	// rep(i, 0, n) cout << delta_with_index[i].fi << " " << delta_with_index[i].se << endl;
	ll c = 0;
	for (int i=0; i<n;) {
		int d = delta_with_index[i].fi;
		// debug(d);
		int j = i+1;
		for (; j < n && delta_with_index[j].fi == d; ++j);
		ll S = 0;
		// debug(S);
		for (int k=i; k<j; ++k) {
			int x = delta_with_index[k].se;
			c = (c+(n+1-x)*S) % MOD;
			S += x+1;
			// cout << "l : " << l << " | (n+1-r) : " << n+1-delta_with_index[k+1].se << endl;
		}
		i = j;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		cout << solve(s) << "\n";
	}
	return 0;
}
