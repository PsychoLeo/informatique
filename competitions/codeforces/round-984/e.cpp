/*
* Author:  Léopold Bernard
* Created: 02/11/2024 16:04:46
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

int n, k, q;
vvi a;

pii intersection(int a1, int b1, int a2, int b2) {
	if (a2 > b1 || a1 > b2) return mp(-1, -1);
	return mp(max(a1, a2), min(b1, b2));
}

void print() {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<k; ++j) cout << a[i][j] << ' ';
		cout << nl;
	}
}

void solve() {
	int m; cin >> m;
	int left=0, right=n-1;
	while (m--) {
		int r, c; char o;
		cin >> r >> o >> c; --r;
		int lo=0, hi=n-1, mid;
		//cout << left+1 << ' ' << right+1 << nl;
		//cout << o << nl;
		if (o == '<') {
			while (lo+1 < hi) {
				mid = (lo + hi) / 2;
				if (a[mid][r] < c) lo = mid;
				else hi = max(mid-1, lo);
				// cout << lo << ' ' << hi << nl;
			}
			if (lo+1 < n && a[lo+1][r] < c) lo++;
			pii p = intersection(left, right, 0, lo);
			left = p.fi; right = p.se;
			if (a[lo][r] >= c || p.fi == -1) {
				cout << -1 << nl;
				return;
			}
		}
		else {
			while (lo < hi) {
				mid = (lo + hi) / 2;
				if (a[mid][r] > c) hi = mid;
				else lo = min(mid+1, hi);
			}
			pii p = intersection(left, right, lo, n-1);
			left = p.fi; right = p.se;
			if (a[lo][r] <= c || p.fi == -1) {
				//debug(mid);
				//debug(a[mid][r]);
				//debug(c);
				cout << -1 << nl;
				return;
			}
		}
	}
	cout << left+1 << nl; // left+1
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> q;
	a.resize(n, vi(k));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<k; ++j) {
			cin >> a[i][j];
			if (i > 0) a[i][j] |= a[i-1][j];
		}
	}
	// print();
	while (q--) solve();
	return 0;
}