/*
* Author:  Léopold Bernard
* Created: 02/12/2024 18:59:11
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

int a, b;
int m;
vvi dp;

void print() {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<m; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
    m = 1+max(a, b);
    dp.resize(m, vi(m, INF));
    // dp[i][j] = min(min(x)(dp[i-x][j] + dp[x][j]), min(y)(dp[i][j-y]+dp[i][y]);
    for (int i=0; i<m; ++i) dp[i][0] = dp[0][i] = 0;
    for (int i=1; i<m; ++i) {
        for (int j=i; j<m; ++j) {
            int mn = INF;
            for (int x=1; x<=i; ++x) mn = min(mn, 1+dp[i-x][j] + dp[x][j]);
            for (int y=1; y<=j; ++y) {
                if (j-y <= i && y <= i) mn = min(mn, 1+dp[j-y][i] + dp[y][i]);
                else if (j-y<=i && y >i) mn = min(mn, 1+dp[j-y][i] + dp[i][y]); 
                else if (j-y>i && y<=i) mn = min(mn, 1+dp[i][j-y] + dp[y][i]);
                else if (j-y>i && y >i) mn = min(mn, 1+dp[i][j-y] + dp[i][y]);
            }
            dp[i][j] = mn;
            if (i == j) dp[i][j] = 0;
        }
    }
    // print();
    cout << dp[min(a, b)][max(a, b)] << nl;
	return 0;
}
