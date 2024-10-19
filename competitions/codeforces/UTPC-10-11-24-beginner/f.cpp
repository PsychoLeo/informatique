/*
* Author:  Léopold Bernard
* Created: 16/10/2024 20:31:06
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

int n, k;
vi d;
int lo, hi;

bool isRealisable(int r) {
	int lastPlaced = d[0] + r;
	int numPlaced = 1;
	for (int i=0; i<n; ++i) {
		if (abs(d[i] - lastPlaced) > r) {
			lastPlaced = d[i] + r;
			numPlaced++;
			if (numPlaced > k) return false;
		}
	}
	return true;
}

void solve() {
	lo = 0; hi = INF;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (isRealisable(mid)) {
			hi = mid;
		}
		else {
			lo = mid+1;
		}
	}
	cout << lo << nl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	d.assign(n, 0);
	for (int &x: d) cin >> x;
	sort(all(d));
	solve();
	return 0;
}
