/*
* Author:  Léopold Bernard
* Created: 26/11/2024 12:06:24
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


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
    vvi grid(n+1, vi(n+1, 0));
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            char c; cin >> c;
            if (c == '*') grid[i][j]++;
            grid[i][j] += grid[i][j-1] + grid[i-1][j] - grid[i-1][j-1];
        }
    }
    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << grid[y2][x2] - grid[y2][x1-1] - grid[y1-1][x2]+ grid[y1-1][x1-1] << nl;
    }
	return 0;
}
