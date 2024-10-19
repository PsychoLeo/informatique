/*
* Author:  Léopold Bernard
* Created: 19/10/2024 00:36:34
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

string s;
vvb vis;
int n = 7;
int ans;

map<char, pii> dir = {
    {'D', mp(1, 0)},
    {'U', mp(-1, 0)},
    {'L', mp(0, -1)},
    {'R', mp(0, 1)}
};

bool isPossible(int i, int j, int numMoves, char mv) {
    pii p = dir[mv];
    int di = p.fi, dj = p.se;
    if (i+di<0 || i+di >= n || j+dj<0 || j+dj>=n) return false;
    if (vis[i+di][j+dj]) return false;
    if (s[numMoves] != '?' && s[numMoves] != mv) return false;
    return true;
}



bool isconnexe() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (!vis[i][j]) 
        }
    }
}

void dfs(int i, int j, int numMoves) {
    if ((numMoves >= n*n-1) && (i == n-1) && (j == 0)) {
        ans++; return;
    }
    if (i == n-1 && j == 0) return;
    if (!isconnexe()) return;
    for (char mv : {'D', 'U', 'L', 'R'}) {
        if (isPossible(i, j, numMoves, mv)) {
            int di = dir[mv].fi, dj = dir[mv].se;
            vis[i][j] = true;
            dfs(i+di, j+dj, numMoves+1);
            vis[i][j] = false;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    ans = 0;
    vis.assign(n, vb(n, false));
    dfs(0, 0, 0);
    cout << ans << nl;
	return 0;
}
