/*
* Author:  Léopold Bernard
* Created: 01/11/2024 23:05:22
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

int n, m; 
vector<vector<pii>> dp;

void print() {
    for (int i=0; i<=m; ++i) {
        for (int j=0; j<=m; ++j) {
            cout << '(' << dp[i][j].fi << ',' << dp[i][j].se << ')' << ' ';
        }
        cout << nl;
    }
}

int solve() {
    int ans = 0;
    int i = 0;
    for (int iter = 0; iter <= n; ++iter) {
        int r = 0; if (iter < n) cin >> r;
        if (r == 0) {
            for (int j=1; j<=m; ++j) dp[i][j].fi += dp[i][j-1].fi;
            for (int j=m-1; j>=0; --j) dp[i][j].se += dp[i][j+1].se;
            ++i;
        }
        else if (r > 0) {
            if (r <= i) dp[i][r].fi++;
        }
        else {
            r = abs(r);
            if (r <= i) dp[i][i-r].se++;
        }
    }
    print();
    for (int k=0; k<=m; ++k) {
        int s = 0;
        for (int j = 0; j<=m; ++j) s += dp[j][k].fi + dp[j][k].se;
        ans = max(ans, s);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    dp.assign(m+1, vector<pii>(m+1, mp(0, 0)));
    cout << solve() << nl;
	return 0;
}
