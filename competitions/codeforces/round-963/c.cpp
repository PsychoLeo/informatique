/*
* Author:  Léopold Bernard
* Created: 04/08/2024 16:30:53
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

ll solve (int n, int k, vll &a) {
	sort(all(a));
	// if there is a result, it is in the range [an, an+k-1]
	ll lo = a[n-1], hi = a[n-1]+k-1;
	for (int i=n-2; i>=0; --i) {
		// cout << lo << " " << hi << nl;
		ll p = lo-a[i];
		p = p / (2 * k) + (p % (2 * k) != 0);
		ll left2 = a[i] + 2 * p * k;
		//debug(a[i]);
		//debug(p);
		// debug(left2);
		ll right2 = left2 + k - 1;
		ll left1 = left2 - 2 * k;
		ll right1 = right2 - 2 * k;
		if (left2 > hi && right1 < lo) return -1;
		else if (left2 <= hi) {
			lo = max(lo, left2);
		}
		else {
			hi = min(hi, right1);
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vll a(n); for (ll &x: a) cin >> x;
		cout << solve(n, k, a) << nl;
	}
	return 0;
}
