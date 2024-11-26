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

void print() {
	for (int i=0; i<k; ++i) {
		for (int j=0; j<n; ++j) cout << a[i][j] << ' ';
		cout << nl;
	}
}

int solve() {
	int m; cin >> m;
	int L=0, R=n-1;
	while (m--) {
		int r, c; char o;
		cin >> r >> o >> c; --r;
		if (o == '<') {
			int nr = lower_bound(all(a[r]), c)-a[r].begin();
            R = min(R, nr);
		}
		else {
			int nL = upper_bound(all(a[r]), c)-a[r].begin();
            L = max(L, nL);
		}
	}
	return (L > R) ? -1 : L+1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> q;
	a.resize(k, vi(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<k; ++j) {
			cin >> a[j][i];
			if (i > 0) a[j][i] |= a[j][i-1];
		}
	}
	// print();
	while (q--) cout << solve() << nl;
	return 0;
}