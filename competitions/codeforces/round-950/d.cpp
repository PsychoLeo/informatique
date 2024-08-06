/*
* Author:  Léopold Bernard
* Created: 05/08/2024 11:13:37
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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

bool solve(int n, vi &a) {
	if (n < 3) return true;
	vi gcdarr(n-1);
	for (int i=0; i<n-1; ++i) {
		gcdarr[i] = gcd(a[i], a[i+1]);
	}
	vb prefix_incr(n, false); // if increasing from beginning to i (i included)
	vb suffix_incr(n, false); // if increasing from i to the end (i included)
	prefix_incr[0] = true;
	for (int i=1; i<n-1; ++i) {
		if (gcdarr[i] < gcdarr[i-1]) break;
		prefix_incr[i] = true;
	}
	suffix_incr[n-1] = true;
	suffix_incr[n-2] = true;
	for (int i=n-3; i>=0; --i) {
		if (gcdarr[i] > gcdarr[i+1]) break;
		suffix_incr[i] = true;
	}
	if (suffix_incr[1] || prefix_incr[n-3]) return true;
	// cout << "Hello" << nl;
	for (int i=1; i<n-1; ++i) {
		// i = index of element to discard in a
		// removing i in a <=> removing (i-1, i) in gcdarr and replacing it with gcd(a[i-1], a[i+1])
		int g = gcd(a[i-1], a[i+1]);
		bool isincr_lr;
		if (i == 1) isincr_lr = suffix_incr[i+1];
		else isincr_lr = (prefix_incr[i-2] && suffix_incr[i+1]);
		bool isincr_mid;
		if (i == 1) isincr_mid = (g <= gcdarr[i+1]);
		else if (i == n-2) isincr_mid = (gcdarr[i-2] <= g);
		else isincr_mid = (gcdarr[i-2] <= g && g <= gcdarr[i+1]);
		// cout << "On remplace " << gcdarr[i-1] << " , " << gcdarr[i] << " par " << g << nl;
		// debug(gcdarr[i+1]);
		if (isincr_lr && isincr_mid) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vi a(n);
		for (int &x:a) cin >> x;
		cout << (solve(n, a) ? "YES" : "NO") <<nl;
	}
	return 0;
}
