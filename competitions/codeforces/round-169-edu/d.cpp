/*
* Author:  Léopold Bernard
* Created: 15/08/2024 16:23:49
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
#define INF (int)1e9

map<string, int> type = {
	{"BG", 0},
	{"BR", 1}, 
	{"BY", 2}, 
	{"GR", 3}, 
	{"GY", 4}, 
	{"RY", 5}
};

vvi to_search = {
	{1, 2, 3, 4},
	{2, 3, 5, 0},
	{4, 5, 0, 1}, 
	{4, 5, 0, 1},
	{2, 3, 5, 0},
	{1, 2, 3, 4}
};



int mindist(int x, int y, vi &v) {
	// if there is an element between indexes x and y, return |x-y| else the closest to x or y
	auto it = lower_bound(all(v), x);
	int minv = INF;
	if (it != v.end()) {
		chmin(minv, abs(x-*it) + abs(y-*it));
	}
	if (it != v.begin()) {
		it--;
		chmin(minv, abs(x-*it) + abs(y-*it));
	}
	return minv;
}

void solve(int q, vvi &a, vector<string> &city) {
	for (int i=0; i<q; ++i) {
		int x, y; cin >> x >> y;
		--x; --y;
		if (x > y) swap(x, y);
		int t1 = type[city[x]];
		int t2 = type[city[y]];
		auto it = find(all(to_search[t1]), t2);
		if ((it != to_search[t1].end()) || (t1 == t2)) {
			cout << abs(y-x) << nl;
		}
		else {
			// binary search for 
			bool allempty = true;
			int ans = INF;
			for (int v : to_search[t1]) {
				if (sz(a[v]) == 0) continue;
				allempty = false;
				chmin(ans, mindist(x, y, a[v]));
			}
			if (allempty) cout << -1 << nl;
			else cout << ans << nl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vvi a(6, vi());
		vector<string> city;
		for (int i=0; i<n; ++i) {
			string s; cin >> s;
			a[type[s]].pb(i);
			city.pb(s);
		}
		solve(q, a, city);
	}
	return 0;
}
