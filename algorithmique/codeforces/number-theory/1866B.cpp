/*
* Author:  Léopold Bernard
* Created: 31/07/2024 15:09:26
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

#define MOD 998244353

ll solve (vector<pii> &p) {
    ll c = 1;
    for (pii x : p) {
        if (x.fi > x.se) c = (c * 2) % MOD;
        else if (x.fi < x.se) return 0;
    }
    return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
    vi pa(n); rep(i, 0, n) cin >> pa[i];
    vi ea(n); rep(i, 0, n) cin >> ea[i];
    int m; cin >> m;
    vi pb(m); rep(i, 0, m) cin >> pb[i];
    vi eb(m); rep(i, 0, m) cin >> eb[i];
    vector<pii> p;
    int i=0, j=0;
    while (i < n || j < m) {
        if (i == n) {
            p.pb(mp(0, eb[j]));
            ++j;
        }
        else if (j == m) {
            p.pb(mp(ea[i], 0));
            ++i;
        }
        else {
            if (pa[i] == pb[j]) {
                p.pb(mp(ea[i], eb[j])); 
                ++i; ++j;
            }
            else if (pa[i] < pb[j]) {
                p.pb(mp(ea[i], 0)); 
                ++i;
            }
            else {
                p.pb(mp(0, eb[j]));
                ++j;
            }
        }
    }
    // for (pii x : p) cout << x.fi << " " << x.se << nl;
    cout << solve(p) << nl;
	return 0;
}
