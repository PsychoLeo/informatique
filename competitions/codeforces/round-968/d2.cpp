/*
* Author:  Léopold Bernard
* Created: 25/08/2024 16:33:26
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

ll sndMissingVal(int n, vi &a) {
	int missingcnt = 0;
	// for (int x : a) cout << x << " ";
	// cout << nl;
	if (a[0] > 1) return 1LL;
	if (a[0] == 1) missingcnt = 1;
	for (int i=1; i<n; ++i) {
		if (a[i] > a[i-1] + 1) {
			missingcnt++;
			if (missingcnt == 2) return a[i-1]+1;
			if (a[i] > a[i-1] + 2) return a[i-1]+2;
		}
	}
	if (missingcnt == 0) return a[n-1]+2;
	return a[n-1]+1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        ll ans = 0;
		int n, m; cin >> n >> m;
        vi vals;
		for (int i=0; i<n; ++i) {
			int li; cin >> li;
			vi a(li); for (int &x: a) cin >> x;
			sort(all(a)); 
			ll snd = sndMissingVal(li, a);
			// debug(snd);
            vals.pb(snd);
		}
        sort(all(vals));
        for (int i=0; i<n; ++i) ans += max(i, vals[n-1-i]);
		ans += 1LL * (m - n +1) * (m + n)/2;
        cout << ans << nl;
	}
	return 0;
}
