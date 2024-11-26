/*
* Author:  Léopold Bernard
* Created: 25/11/2024 13:06:19
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

ll n, k, q;
vector<vll> a;

void print() {
    for (int j=0; j<k; ++j) {
        for (int i=0; i<n; ++i) {
            cout << a[j][i] << ' ';
        }
        cout << nl;
    }
}

void solve() {
    int m; cin >>m;
    ll lo = 0, hi = n-1;
    while (m--) {
        ll r, c; char sgn; cin >> r >> sgn >> c; --r;
        // debug(i);
        if (sgn == '>') {
            ll i = lower_bound(all(a[r]), c+1) - a[r].begin();
            // debug(i);
            lo = max(lo, i); // find first value strictly greater than c
        }
        else {
            ll i = lower_bound(all(a[r]), c) - a[r].begin()-1;
            //debug(i);
            hi = min(hi, i); // find last value strictly less than c
        }
    }
    if (lo <= hi) cout << lo+1 << nl;
    else cout << -1 << nl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> q;
    a.resize(k, vll(n));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<k; ++j) {
            cin >> a[j][i];
            if (i > 0) a[j][i] |= a[j][i-1];
        }
    }
    // print();
    while (q--) solve();
	return 0;
}
