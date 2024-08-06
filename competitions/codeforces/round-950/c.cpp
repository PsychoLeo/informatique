/*
* Author:  Léopold Bernard
* Created: 05/08/2024 11:13:34
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

bool solve(int n, int m, vi&a, vi&b, vi &d) {
	int numop = 0;
	map<int, int> cnt;
	for (int x : d) {
		if (cnt.find(x) == cnt.end()) {
			cnt[x] = 1;
		}
		else {
			cnt[x]++;
		}
	}
	for (int i=0; i<n; ++i) {
		if (a[i] != b[i]) {
			numop++;
			if (cnt.find(b[i]) == cnt.end() || cnt[b[i]] == 0) {
				return false;
			}
			else {
				cnt[b[i]]--;
			}
		}
	}
	bool found = false;
	for (int i=0; i<n; ++i) {
		if (b[i] == d[m-1]) found = true;
	}
	return found;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi a(n); for (int &x: a) cin >> x;
		vi b(n); for (int &x: b) cin >> x;
		int m; cin >> m;
		vi d(m); for (int &x: d) cin >> x;
		cout << (solve(n, m, a, b, d) ? "YES" : "NO") << nl;
	}
	return 0;
}
