/*
* Author:  Léopold Bernard
* Created: 01/08/2024 16:28:08
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

ll closest(ll n, ll b) {
    if ((n & b) == b) return n;
    if (n <= b) return b;
    ll lo = n, hi = n;
    ll p = 1;
    while (p < b) {
        lo = (lo | p);
        hi = hi - (hi & p);
        p *= 2;
    }
    hi = (hi | b);
    p = b;
    while ((lo & p) != p) {
        lo = (lo | p);
        p *= 2;
    }
    lo = lo - p;
    if (n-lo <= hi-n) return lo;
    return hi;
}

ll solve (ll n, ll m) {
    ll b = 1;
    ll r = n;
    while (b <= (ll)1e18) {
        ll xb = closest(n, b);
        if (abs(n-xb) <= m) r = (r | b);
        b *= 2;
    }
    return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
    // cout << closest(8, 1) << " " << closest(8, 2) << " " << closest(8, 4) << nl;
	while (t--) {
        ll n, m; cin >> n >> m;
        cout << solve(n, m) << nl;
	}
	return 0;
}
