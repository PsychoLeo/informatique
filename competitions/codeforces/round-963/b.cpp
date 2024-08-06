/*
* Author:  Léopold Bernard
* Created: 04/08/2024 16:30:50
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

int solve(int n, vi &a) {
	int parity = a[0] % 2;
	bool sameParity = true;
	int biggestPair = 0, biggestImpair = 0;
	int numPair = 0, numImpair = 0;
	vi pairs;
	vi impairs;
	for (int i=0; i<n; ++i) {
		if (a[i] % 2 != parity) sameParity = false;
		if (a[i] % 2 == 0) {
			chmax(biggestPair, a[i]);
			numPair++;
			pairs.pb(a[i]);
		}
		else {
			chmax(biggestImpair, a[i]);
			numImpair++;
			impairs.pb(a[i]);
		}
	}
	ll biggestFormedImpair = biggestImpair;
	sort(all(pairs));
	for (int i=0; i<numPair && pairs[i] < biggestFormedImpair; ++i) {
		// debug(pairs[i]);
		biggestFormedImpair += pairs[i];
	}
	// debug(biggestFormedImpair);
	if (sameParity) return 0;
	int numop = numPair + (biggestFormedImpair < biggestPair);
	return numop;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi a(n); for (int &x: a) cin >> x;
		cout << solve(n, a) << nl;
	}
	return 0;
}
