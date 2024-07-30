/*
* Author:  Léopold Bernard
* Created: 30/07/2024 11:43:00
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

// #define DEBUG true
#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 

ll solve(vi &a, vi &b, int d) {
    auto it = upper_bound(a.begin(), a.end(), d);
    int i = it - a.begin() - 1;
    // cout << "d : " << d <<nl;
    // cout << "a_i : " << a[i] << nl;
    // cout << "b_i : " << b[i] << nl;
    // debug(i);
    if (d == a[i]) return b[i];
    ld t = (ld)b[i] + (ld)(b[i+1]-b[i]) * (d-a[i]) / (a[i+1]-a[i]);
    return (ll)t;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, k, q; cin >> n >> k >> q;
        int d;
        vi a(k+1, 0), b(k+1, 0);
        rep(i, 0, k) cin >> a[i+1];
        rep(i, 0, k) cin >> b[i+1];
        rep(i, 0, q) {
            cin >> d;
            cout << solve(a, b, d) << " ";
        }
        cout << nl;
	}
	return 0;
}
