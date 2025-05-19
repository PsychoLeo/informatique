/*
* Author:  Léopold Bernard
* Created: 18/04/2025 19:43:41
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

int n, m, p;
vvi dp;
vector<pii> bonus;
vvi mv;

void print() {
    cout << "DP : " << nl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) cout << dp[i][j] << " ";
        cout << nl;
    }

    cout << "Bonus : " << nl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) cout << v[i][j] << " ";
        cout << nl;
    }

    cout << "Moves : " << nl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) cout << mv[i][j] << " ";
        cout << nl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
    dp.resize(n, vi(m, -INF));
    dp[0][p] = 0;
    bonus.resize(n);
    mv.resize(n, vi(m, -2));
    for (int i=1; i<n; ++i) {
        int j, v;
        bonus[i] = mp(j, v);
    }
    for (int i=1; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            int mx = -INF, mvi = -2;
            for (int dj : {0, 1, -1}) {
                if (0 <= j+dj && j+dj <m) if (dp[i-1][j+dj] > mx) {
                    mx = dp[i-1][j+dj];
                    mvi = -dj;
                }
            }
            dp[i][j] = mx + (bonus[i].fi == j ? bonus[i].se : 0);
            mv[i][j] = mvi;
        }
    }
    print();
    int mxv = -INF, mxi = -INF;
    vi ans;
    for (int j=0; j<m; ++j) {
        if (dp[n-1][j] > mxv) {
            mxv = dp[n-1][j];
            mxi = j;
        }
    }
    int j = mxi;
    for (int i=n-1; i>0; --i) {
        ans.pb(mv[i][j]);
        j += mv[i][j];
        // debug(j);
    }
    reverse(all(ans));
    for (int x: ans) cout << x << " " ;
    cout << nl;
	return 0;
}
