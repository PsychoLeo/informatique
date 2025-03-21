/*
* Author:  Léopold Bernard
* Created: 22/07/2024 13:59:09
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
#define debug(x) cout << #x << "=" << x << "\n";
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 

int solve(int c, vi &h) {
    vi dp(c+1, 0);
    dp[1] = h[1];
    for (int i=2; i<=c;++i) {
        int mxh = max(h[i], h[i-1]);
        int mn = min(h[i] + dp[i-1], mxh + dp[i-2]);
        if (i >= 3) mn = min(mn, max(mxh, h[i-2]) + dp[i-3]);
        dp[i] = mn;
    }
    return dp[c];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c, r, n; cin >> c >> r >> n;
    vi h(c+1, 0);
    rep(i, 0, n) {
        int ci, hi; cin >> ci >> hi;
        h[ci] = max(h[ci], hi);
    }
    cout << solve(c, h) << endl;
	return 0;
}
