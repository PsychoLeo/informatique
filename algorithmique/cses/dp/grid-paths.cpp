/*
* Author:  Léopold Bernard
* Created: 01/12/2024 23:54:28
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
vector<vector<char>> grid;
vector<vll> dp; 


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    grid.resize(n, vector<char>(n));
    dp.resize(n, vll(n, 1));
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cin >> grid[i][j];
    for (int i=1; i<n; ++i) {
        dp[i][0] = ((dp[i-1][0] == 0 || grid[i][0] == '*') ? 0 : 1);
    }
    for (int j=1; j<n; ++j) {
        dp[0][j] = ((dp[0][j-1] == 0 || grid[0][j] == '*') ? 0 : 1);
    }
    for (int i=1; i<n; ++i) {
        for (int j=1; j<n; ++j) {
            if (grid[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    if (grid[0][0] == '*') cout << 0 << nl;
    else cout << dp[n-1][n-1] << nl;
	return 0;
}
