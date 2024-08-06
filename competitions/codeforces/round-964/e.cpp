/*
* Author:  Léopold Bernard
* Created: 06/08/2024 19:06:33
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
#define MAX (ll)(2e5+5)

ll dp[MAX]; // dp[i] = number of /3 operations it takes to get i down to 0
ll dpsum[MAX]; // dpsum[i] = number of operations it takes to get all numbers from 0 to i (included) down to 0

void fill() {
	dp[0] = 0;
	dpsum[0] = 0;
	for (int i=1; i<MAX; ++i) {
		dp[i] = dp[i/3] + 1;
		dpsum[i] = dpsum[i-1] + dp[i]; 
	}
}

void print() {
	for (int i=MAX-20; i<MAX; ++i) cout << dp[i] << " ";
	cout << nl;
}

ll solve(int l, int r) {
	ll ans = 0;
	int x = l;
	while (x) {
		ans += 2;
		x /= 3;
	}
	// cout << dpsum[l] << endl;
	return (ans + dpsum[r] - dpsum[l]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	fill();
	// print();
	while (t--) {
		int l,r; cin >> l >> r;
		cout << solve(l, r) << nl;
	}
	return 0;
}
