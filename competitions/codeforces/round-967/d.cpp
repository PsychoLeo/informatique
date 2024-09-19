/*
* Author:  Léopold Bernard
* Created: 21/08/2024 00:35:35
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

int minPow2(int x) {
	// find minimum power of 2 superior to x
	if (__builtin_popcount(x) == 1) return x;
	return 1 << (32 - __builtin_clz(x));
}

struct MinSegTree {
	int n, m;
	vi tree;

	void display() {
		int maxh = __builtin_ctz(m);
		for (int h=0; h<maxh; ++h) {
			for (int i=(1<<h); i<(1<<(h+1)); ++i) cout << tree[i] << " ";
			cout << nl;
		}
	}

	int update(int i) {
		if (i < m/2) tree[i] = min(update(2*i), update(2*i+1));
		return tree[i];
	}

	void fillTree(int size, vi &v) {
		n = size;
		m = 2 * minPow2(n);
		tree.resize(m, INF);
		for (int i=0; i<n; ++i) {
			tree[i+m/2] = v[i];
		}
		update(1);
	}

	int minv(int v, int tl, int tr, int l, int r) {
		// find min between indexes a and b
		if (l > r) return INF;
		if (tl == l && tr == r) return tree[v];
		int tm = (tl + tr) / 2;
		return min(minv(2*v, tl, tm, l, min(r, tm)), minv(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
};

struct MaxSegTree {
	int n, m;
	vi tree;

	int update(int i) {
		if (i < m/2) tree[i] = max(update(2*i), update(2*i+1));
		return tree[i];
	}

	void display() {
		int maxh = __builtin_ctz(m);
		for (int h=0; h<maxh; ++h) {
			for (int i=(1<<h); i<(1<<(h+1)); ++i) cout << tree[i] << " ";
			cout << nl;
		}
	}

	void fillTree(int size, vi &v) {
		n = size;
		m = 2*minPow2(n);
		tree.resize(m, 0);
		for (int i=0; i<n; ++i) {
			tree[i+m/2] = v[i];
		}
		update(1);
	}

	int maxv(int v, int tl, int tr, int l, int r) {
		// find min between indexes a and b
		if (l > r) return -INF;
		if (tl == l && tr == r) return tree[v];
		int tm = (tl + tr) / 2;
		return max(maxv(2*v, tl, tm, l, min(r, tm)), maxv(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
};

int findNextLast(int i, vi &a, vi &cnt, vi &currcnt, vi &nxtlast) {
	int x = a[i];
	currcnt[x]++;
	if (currcnt[x] == cnt[x]) nxtlast[i] = i;
	else nxtlast[i] = findNextLast(i+1, a, cnt, currcnt, nxtlast);
	return nxtlast[i];
}

vi solve(int n, vi &a, vi &cnt) {
	vi nxtlast(n);
	vi currCnt(n+1, 0);
	for (int i=0; i<n; i=findNextLast(i, a, cnt, currCnt, nxtlast)+1);
	// for (int x: nxtlast) cout << x << " ";
	// cout << nl;
	vvi ind(n+1);
	for (int i=0; i<n; ++i) {
		ind[a[i]].pb(i);
	}
	// for (int i=0; i<=n; ++i) if (sz(ind[i])) {
	// 	cout << i << " : ";
	// 	for (int x: ind[i]) cout << x << " ";
	// 	cout << nl;
	// } 
	MinSegTree mint = MinSegTree();
	MaxSegTree maxt = MaxSegTree();
	mint.fillTree(n, a); maxt.fillTree(n, a);
	int m = 2*minPow2(n);
	// maxt.display();
	// mint.display();
	vi ans;
	vb visited(n+1, false);
	int iter = 0; // number of iterations
	for (int i=0; i<n;) {
		int j = nxtlast[i];
		while (j+1 < n && visited[a[j]]) {
			j = nxtlast[j+1];
			// debug(j);
		}
		if (j >=n) break;
		// debug(j);
		int v = (iter % 2) ? mint.minv(1, 0, m/2-1, i, j) : maxt.maxv(1, 0, m/2-1, i, j);
		if (!visited[v]) {
			visited[v] = true;
			// debug(v);
			// cout << sz(ind[v]) << nl;
			// for (int x: ind[v]) cout << x << " ";
			// cout << nl;
			auto it = lower_bound(all(ind[v]), i);
			// debug(v);
			ans.pb(v); i = (*it)+1;
			iter++;
		}
		else ++i;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi a(n), cnt(n+1, 0);
		for (int i=0; i<n; ++i) {
			int x; cin >> x; a[i] = x; cnt[x]++;
		}
		vi ans = solve(n, a, cnt);
		cout << sz(ans) << nl;
		for (int v : ans) cout << v << " ";
		cout << nl;
	}
	return 0;
}
