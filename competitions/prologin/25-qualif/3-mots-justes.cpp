/*
* Author:  Léopold Bernard
* Created: 28/10/2024 21:30:53
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

int n;
vi pfc;
vi sfc;
vll vals;
map<ll, int> v;

void print() {
    for (ll val: vals) cout << val << ' ';
    cout << nl;
}

ll compute(ll x) {
    ll s = 0;
    for (auto [val, cnt] : v) s += cnt*min(val, abs(val-x));
    return s;
}

ll solve() {
    sort(all(vals));
    // print();
    // int q = sz(vals);
    ll ans = 1e18;
    for (ll x: vals) {
        if (v.find(x) == v.end()) v[x] = 1;
        else v[x]++;
    }
    for (auto [x, c]: v) ans = min(ans, compute(x));
    // ll lo = 0, hi = vals[q-1];
    // while (hi-lo > 2) {
    //     ll m1 = (2*lo + hi) / 3;
    //     ll m2 = (lo + 2*hi) / 3;
    //     ll fm1 = compute(m1), fm2 = compute(m2);
    //     if (fm1 >= fm2) lo = m1;
    //     else hi = m2;
    // }
    // debug(lo); debug(hi);
    // ll ans = compute(lo);
    // for (int i=lo+1; i<=hi; ++i) ans = min(ans, compute(i));
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    int m = 26;
    int len = m*m;
    pfc.assign(len, 0); sfc.assign(len, 0);
    for (int i=0; i<n; ++i) {
        char c1, c2; cin >> c1 >> c2;
        // cout << c1 << ' ' << c2 << nl;
        pfc[(c1-'a')*m + (c2-'a')]++;
    }
    for (int i=0; i<n; ++i) {
        char c1, c2; cin >> c1 >> c2;
        sfc[(c1-'a')*m + (c2-'a')]++;
    }
    for (int i=0; i<len; ++i) {
        for (int j=0; j<len; ++j) {
            if (pfc[i] > 0 && sfc[j] > 0) {
                vals.pb(1LL*pfc[i]*sfc[j]);
            } 
        }
    }
    cout << solve() << nl;
	return 0;
}
