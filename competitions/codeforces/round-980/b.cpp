/*
* Author:  Léopold Bernard
* Created: 20/10/2024 11:01:33
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
vi a;

ll solve() {
	sort(all(a));
	ll presses = 0;
	ll from_each = 0;
	ll fallen_cans = 0;
	for (int i=0; i<n; ++i) {
		// debug(i);
		// debug(from_each);
		// debug(fallen_cans);
		if (a[i] > from_each) {
			// we take from all machines >= i
			if (fallen_cans + (a[i] - from_each) * (n-i) >= k) return (presses + k - fallen_cans);
			presses += (a[i] - from_each) * (n-i) + 1;
			fallen_cans += (a[i] - from_each) * (n-i);
			from_each += a[i] - from_each;
		}
		else {
			presses++;
		}
	}
	return presses;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		a.resize(n); for (int &x: a) cin >> x;
		cout << solve() << nl;
	}
	return 0;
}
