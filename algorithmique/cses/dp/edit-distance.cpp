/*
* Author:  Léopold Bernard
* Created: 02/12/2024 18:40:01
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

string s, t;
int n, m;
vvi dp;

void print() {
    for (auto v: dp) {
        for (auto x: v) cout << x << ' ';
        cout << nl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> t;
    n = sz(s); m = sz(t);
    dp.resize(n, vi(m, 0));
    dp[0][0] = (s[0] != t[0]);
    for (int i=1; i<n; ++i) {
        if (s[i] == t[0]) dp[i][0] = i;
        else dp[i][0] = i+1;
    }
    for (int j=1; j<m; ++j) {
        if (t[j] == s[0]) dp[0][j] = j;
        else dp[0][j] = j+1;
    }
    for (int i=1; i<n; ++i) {
        for (int j=1; j<m; ++j) {
            if (s[i] == t[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    // print();
    cout << dp[n-1][m-1] <<nl;
	return 0;
}
