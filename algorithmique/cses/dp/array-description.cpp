/*
* Author:  Léopold Bernard
* Created: 02/12/2024 11:25:30
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
vll x;
vector<vll> dp; // dp[i][v] = number of arrays matching x[0...i] and having arr[i] = v

void print() {
    for (int i=0; i<n; ++i) {
        for (int v=0; v<=m; ++v) {
            cout << dp[i][v] << ' ';
        }
        cout << nl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    x.resize(n);
    for (ll &xi: x) cin >> xi;
    dp.resize(n, vll(m+1, 0));
    if (x[0] == 0) for (int v=1; v<=m; ++v) dp[0][v] = 1;
    else dp[0][x[0]] = 1;
    for (int i=1; i<n; ++i) {
        for (int v=1; v<=m; ++v) {
            if (x[i] && x[i] != v) dp[i][v] = 0;
            else dp[i][v] = ((v>=1) ? dp[i-1][v-1] : 0) + dp[i-1][v] + ((v<m) ? dp[i-1][v+1] : 0);
            dp[i][v] %= MOD;
        }
    }
    // print();
    cout << sum(dp[n-1]) % MOD << nl;
	return 0;
}
