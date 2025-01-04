/*
* Author:  Léopold Bernard
* Created: 18/10/2024 23:03:19
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

int n = 8;
vvi grid(8, vi(8, 0));
int ans;

bool reaches(pii p1, pii p2) {
    int lig1 = p1.fi, col1 = p1.se;
    int lig2 = p2.fi, col2 = p2.se;
    if (lig1 == lig2) return true;
    if (abs(lig1-lig2) == abs(col1-col2)) return true;
    return false;
}

void solve(int col, vector<pii> placed) {
    if (col == n) {
        ans++;
        return;
    }
    for (int lig=0; lig<n; ++lig) {
        if (grid[lig][col] == 0) {
            pii currQueen = mp(lig, col);
            bool works = true;
            for (pii p: placed) {
                if (reaches(p, currQueen)) {
                    works = false;
                    break;
                }
            }
            if (works) {
                placed.pb(currQueen);
                solve(col+1, placed);
                placed.pop_back();
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            char c;
            cin >> c; if (c == '*') grid[i][j] = 1;
        }
    }
    solve(0, vector<pii>());
    cout << ans << nl;
	return 0;
}
