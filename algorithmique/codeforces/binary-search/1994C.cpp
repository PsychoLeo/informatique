/*
* Author:  Léopold Bernard
* Created: 29/07/2024 11:33:04
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

#define nl "\n"

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<(b); ++i)

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

int bin_search(vll &s, ll v, ll n, ll dep) {
	// find minimum index such that s[i] > v, if index doesn't exist, return n
	ll lo = dep, hi = n-1;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (s[mid] <= v) {
			lo = mid + 1;
		}
		else hi = mid;
	}
	if (lo == n-1 && s[lo] <= v) return n;
	return lo; 
}

void dbarr(vll &a) {
	for (ll x : a) cout << x << " ";
	cout << nl;
}

ll solve(ll n, ll x, vll &a) {
    vll s(n);
	ll somme = 0;
	for (int i=0; i<n; ++i) {
		somme += a[i];
		s[i] = somme;
	}
	// dbarr(s);
	vll nextz(n);
	for (int l=0; l<n; ++l) {
		ll to_reach = x + ((l == 0) ? 0 : s[l-1]);
		nextz[l] = bin_search(s, to_reach, n, l);
	}
	// dbarr(nextz);
	vll dp(n);
	for (int l=n-1; l>=0; --l) {
		ll nxt = nextz[l] + 1;
		dp[l] = nextz[l] - l + ((nxt < n) ? dp[nxt] : 0);
	}
	ll ans = 0;
	for (int i=0; i<n; ++i) {
		ans += dp[i];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        ll n, x; cin >> n >> x;
        vll a(n); rep(i, 0, n) cin >> a[i];
        cout << solve(n, x, a) << nl;
	}
	return 0;
}
