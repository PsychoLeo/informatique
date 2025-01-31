/*
* Author:  Léopold Bernard
* Created: 30/07/2024 12:31:32
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
#define INF (ll)1e9

ll solve(ll n, ll k, vll &a, vll &b) {
    ll lo = 0, hi = INF;
    while (hi > lo) {
        ll mid = (hi+lo)/2;
        // debug(mid);
        ll nb_op = 0;
        for (int i=0; i<n; ++i) nb_op += max(0LL, (a[i]-mid)/b[i]);
        if (nb_op > k) lo = mid+1;
        else hi = mid;
    }
    debug(lo);
    // lo will contain the maximum value that can be a minimum for all the values of  
    ll nb_op = k;
    ll score = 0;
    for (int i=0; i<n; ++i) {
        ll m = max(0LL, (a[i]-lo)/b[i]);
        nb_op -= m;
        ll add_sc = m * a[i] - b[i] * m * (m-1) / 2;
        // debug(add_sc);
        score += add_sc;
        a[i] -= m * b[i];
    }
    priority_queue<pll> pq;
    for (int i=0; i<n; ++i) {
        pq.push(mp(a[i], i));
    }
    for (int j=0; j<nb_op; ++j) {
        pll p = pq.top();
        pq.pop();
        score += p.fi;
        // debug(p.fi);
        pq.push(mp(max(0LL, p.fi-b[p.se]), p.se));
    }
    return score;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        ll n, k; cin >> n >> k;
        vll a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        cout << solve(n, k, a, b) << nl;
	}
	return 0;
}
