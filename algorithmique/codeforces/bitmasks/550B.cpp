/*
* Author:  Léopold Bernard
* Created: 01/08/2024 21:49:05
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
#define INF 1000000000

int solve(int n, int l, int r, int x, vi &c) {
    int m = 0;
    for (int mask=0; mask < (1<<n); ++mask) {
        if (__builtin_popcount(mask) >= 2) {
            int mindiff = INF, maxdiff = -INF, sumdiff = 0;
            for (int i=0; i<n; ++i) {
                if (mask & (1<<i)) {
                    chmin(mindiff, c[i]);
                    chmax(maxdiff, c[i]);
                    sumdiff += c[i];
                }
            }
            if ((l <= sumdiff) && (sumdiff <= r) && (maxdiff-mindiff >= x)) ++m;
        }
    }
    return m;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, l, r, x; cin >> n >> l >> r >> x;
    vi c(n); rep(i, 0, n) cin >> c[i];
    cout << solve(n, l, r, x, c) << nl;
	return 0;
}
