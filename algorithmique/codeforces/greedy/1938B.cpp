/*
* Author:  Léopold Bernard
* Created: 19/08/2024 14:02:33
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

string solve(int n, int m, vvi &a) {
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<m-1; ++j) {
            // cout << a[i][j] << nl;
            int v = a[i][j];
            a[i][j] = 0;
            a[i][m-1] = (a[i][m-1] + v) % 3;
            a[n-1][j] = (a[n-1][j] + v) % 3;
            a[n-1][m-1] = (a[n-1][m-1] + 3 - v) % 3;
        }
        if (a[i][m-1]) return "NO";
    }
    for (int j=0; j<m; ++j) if (a[n-1][j]) return "NO";
    return "YES";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, m; cin >> n >> m;
        vvi a(n, vi(m, 0));
        for (int i=0; i<n; ++i) {
            string s; cin >> s;
            for (int j=0; j<m; ++j) {
                a[i][j] = (s[j] - '0');
            }
        }
        for (int i=0; i<n; ++i) {
            string s; cin >> s;
            for (int j=0; j<m; ++j) {
                int x = (s[j] - '0'); a[i][j] = (a[i][j] - x + 3) % 3;
                // cout << a[i][j] << " ";
            }
            // cout << nl;
        }
        cout << solve(n, m, a) << nl;
	}
	return 0;
}
