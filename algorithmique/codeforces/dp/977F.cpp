/*
* Author:  Léopold Bernard
* Created: 03/08/2024 00:36:18
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

void dbarr(vi &v) {
    for (auto x: v) cout << x << " ";
    cout << nl;
}

vi solve(int n, vi &a) {
    vi dp(n, 1);
    vi pred(n, 0);
    for (int i=0; i<n; ++i) pred[i] = i;
    set<pii> pq = {mp(a[0], 0)};
    // dp[i] is the maximum result we can get using a[i]
    for (int i=1; i<n; ++i) {
        auto lo = pq.lower_bound(mp(a[i], -1));
        if (lo != pq.begin()) {
            lo = prev(lo);
            if (a[lo->se] == a[i]-1) {
                dp[i] = 1+dp[lo->se];
                pred[i] = lo->se;
            }
        }
        pq.emplace(mp(a[i], i));
    }
    int maxv = 1, maxind = 0;
    for (int i=0; i<n; ++i) {
        if (dp[i] > maxv) {
            maxv = dp[i];
            maxind = i;
        }
    }
    // dbarr(dp);
    // dbarr(pred);
    vi vals = {maxind+1};
    while (pred[maxind] != maxind) {
        maxind = pred[maxind];
        vals.pb(maxind+1);
    }
    reverse(all(vals));
    return vals;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
    vi a(n); for (int &x: a) cin >> x;
    vi ans = solve(n, a);
    cout << sz(ans) << nl;
    for (int x: ans) cout << x << " ";
    cout << nl;
	return 0;
}
