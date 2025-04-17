/*
* Author:  Léopold Bernard
* Created: 25/03/2025 20:07:46
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

vector<vector<char>> v;
int h, w;
vvb vis;

pii possib(pii p) {
    int x = p.fi, y = p.se;
    for (pii d: {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)}) {
        int dx = d.fi, dy = d.se;
        if (0 <= x+dx && x+dx < h && 0<=y+dy && y+dy<w && v[x+dx][y+dy] != '.') {
            if (!vis[x+dx][y+dy]) return mp(x+dx, y+dy); 
        }
    }
    return mp(-1, -1);
}

void dfs() {
    vis.resize(h, vb(w, false));
    vector<pii> tovis = {mp(0, 0)};
    while (!tovis.empty()) {
        pii p = tovis.back();
        tovis.pop_back();
        int x = p.fi, y = p.se;
        if (vis[x][y]) continue;
        vis[x][y] = true;
        v[x][y] = '.';
        pii nxt = possib(p);
        if (nxt.fi == -1) break;
        tovis.pb(nxt);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w;
    v.resize(h, vector<char>(w));
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cin >> v[i][j];
        }
    }
    dfs();
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cout << v[i][j];
        }
        cout << nl;
    }
	return 0;
}
