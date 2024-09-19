/*
* Author:  Léopold Bernard
* Created: 19/09/2024 15:34:07
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

ll compute (ll n, ll k, ll i) {
	ll x1 = k * (i + 1) + i * (i + 1)/2;
	ll x2 = k * (n-i-1) + (n-i-1)*(n+i)/2;
	return abs(x1-x2);
}

ll solve(ll n, ll k) {
	ll lo = 0, hi = n-1, mid = (hi + lo)/2;
	if (n == 2) return 1;
	while (hi >= lo) {
		mid = (lo + hi) / 2;
		ll a = compute(n, k, mid-1);
		ll b = compute(n, k, mid);
		ll c = compute(n, k, mid+1);
		// debug(mid);
		// debug(b);
		if (a >= b && b <= c) return b;
		if (a <= b && b < c) hi = mid-1;
		else lo = mid+1;
	}
	return compute(n, k, mid);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		cout << solve(n, k) << nl;
	}
	return 0;
}
