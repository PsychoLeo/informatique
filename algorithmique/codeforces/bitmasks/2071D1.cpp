/*
* Author:  Léopold Bernard
* Created: 13/03/2025 14:55:53
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

ll n, l, r;
vi a;

int compute(ll i) {
	if (i <= n) return (a[i] ^ a[i-1]);
	if (i > n && i <= 2*n) return a[i/2];
	if (i/2 % 2) return a[n];
	else return (a[n] ^ compute(i/2));
}


int solve() {
	a.clear();
	a.resize(n+1, 0);
	int last = 0;
	for (int i=1; i<=n; ++i) {
		cin >> a[i]; a[i] ^= a[i-1];
		if (n % 2 == 0 && i == (n+1)/2) last = a[i];
	}
	if (n % 2 == 0) {
		++n; 
		a.pb(last);
	}
	return compute(l);
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> l >> r; 
		cout << solve() << nl;
	}
	return 0;
}
