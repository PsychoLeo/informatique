/*
* Author:  Léopold Bernard
* Created: 20/10/2024 02:00:58
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
#define INF (ll)1e18

ll n, K;
vll h;
vector<vll> dp;

void print() {
    for (int i=0; i<=K; ++i) {
        for (int j=0; j<n; ++j) {
            if (dp[i][j] == INF) cout << "F ";
            else cout << dp[i][j] << ' ';
        }
        cout << nl;
    }
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> K; 
	h.resize(n); for (ll &x: h) cin >> x;
    sort(all(h));
    dp.assign(K+1, vll(n, +INF));
    // for (ll x: h) cout << x << ' '; 
    // cout << nl;
    for (int i=0; i<n; ++i) dp[0][i] = 0;
    for (int k=1; k<=K; ++k) {
        for (int i=1; i<n; ++i) {
            if (2*k <= i+1) {
                dp[k][i] = min(dp[k][i-1], h[i]-h[i-1]+ ((i>=2) ? dp[k-1][i-2] : 0));
            }
        }
    }
    // print();
    cout << dp[K][n-1] << nl;
	return 0;
}
