/*
* Author:  Léopold Bernard
* Created: 11/08/2024 11:05:45
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

vll solve(int n, int m, vi &a, vi &b) {
	vb categ(n+m+1);
	vi p, t;
	vi chg(n+m+1, -1);
	bool changed = false;
	for (int i=0; i<n+m; ++i) {
		if (a[i] > b[i] && sz(p) < n) {
			p.pb(i); categ[i] = 0;
		}
		else if (a[i] > b[i]) {
			t.pb(i); categ[i] = 1;
			if (!changed) for (int j: p) chg[j] = i;
			changed = true;
		}
		else if (a[i] < b[i] && sz(t) < m) {
			t.pb(i); categ[i] = 1;
		}
		else if (a[i] < b[i]) {
			p.pb(i); categ[i] = 0;
			if (!changed) for (int j : t) chg[j] = i;
			changed = true;
		}
	}
	ll s = 0;
	for (int i=0; i<n+m; ++i) {
		s += 1LL * ((categ[i] == 0) ? a[i] : b[i]);
	}
	vll ans;
	for (int i=0; i<n+m; ++i) {
		ll si = s;
		bool c = categ[i];
		si -= 1LL * (c ? b[i] : a[i]);
		int j = chg[i];
		if (j == -1) si += (c ? b[n+m] : a[n+m]);
		else {
			bool cj = categ[j];
			si += abs(a[j] - b[j]);
			si += (cj ? b[n+m] : a[n+m]);
		}
		ans.pb(si);
	}
	ans.pb(s);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vi a(n+m+1);
		vi b(n+m+1);
		for (int i=0; i<n+m+1; ++i) cin >> a[i];
		for (int i=0; i<n+m+1; ++i) cin >> b[i];
		for (ll x : solve(n, m, a, b)) cout << x << " ";
		cout << nl;
	}
	return 0;
}
