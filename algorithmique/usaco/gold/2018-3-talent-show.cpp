/*
* Author:  Léopold Bernard
* Created: 01/04/2025 23:00:50
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
#include <fstream>

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

int n, W;
const int Wm = 1e6+1005;
const int Nm = 255;
vi w;
vi t;
int dp[Nm][Wm];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream cin("talent.in");
	ofstream cout("talent.out");
    cin >> n >> W;
    w.resize(n+1, 0); t.resize(n+1, 0);
    for (int i=1; i<=n; ++i) {
        int wi, ti; cin >> wi >> ti;
        w[i] = wi; t[i] = ti;
    }
    for (int i=0; i<Nm; ++i) for (int j=0; j<Wm; ++j) dp[i][j] = 0;
    for (int i=1; i<=n; ++i) {
        for (int wi=0; wi<Wm; ++wi) dp[i][wi] = dp[i-1][wi];
        for (int wi=w[i]; wi<Wm; ++wi) dp[i][wi] = max(dp[i][wi], dp[i-1][wi-w[i]] + t[i]);
    }
    ld ans = 0;
    for (int wi=W; wi<Wm; ++wi) ans = max(ans, (ld)(1000*dp[n][wi])/(ld)wi);
    ll ansLL = (ll)ans;
    cout << ansLL << nl;
	return 0;
}
