/*
* Author:  Léopold Bernard
* Created: 13/03/2025 14:23:03
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

int n, m;

int compute(ll ri, ll x, ll xi) {
	ll v = ri*ri - (x-xi)*(x-xi);
	if (v < 0) return 0;
	ll a = (ll)sqrt(v);
	return 2*a+1;
}

ll solve() {
	vll x(n), r(n);
	ll ans = 0;
	for (int i=0; i<n; ++i) cin >> x[i];
	for (int i=0; i<n; ++i) cin >> r[i];
	map<ll, ll> c;
	for (int i=0; i<n; ++i) {
		for (int xj = x[i]-r[i]; xj <= x[i]+r[i]; ++xj) {
			ll cc = compute(r[i], xj, x[i]);
			if (c.find(xj) == c.end()) c[xj] = cc;
			else c[xj] = max(c[xj], cc);
		}
	}
	for (auto [v, cnt] : c) ans += cnt;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << solve() << nl;
	}
	return 0;
}
