/*
* Author:  Léopold Bernard
* Created: 14/10/2024 08:40:49
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

int l, c;
vector<vector<char>> grid;
vector<vvi> d;

map<pair<int, char>, int> nxt_dir = {
    {mp(0, '\\'), 3},
    {mp(1, '\\'), 2},
    {mp(2, '\\'), 1}, 
    {mp(3, '\\'), 0},
    {mp(0, '/'), 2},
    {mp(1, '/'), 3},
    {mp(2, '/'), 0},
    {mp(3, '/'), 1}, 
    {mp(0, '.'), 0}, 
    {mp(1, '.'), 1},
    {mp(2, '.'), 2},
    {mp(3, '.'), 3}
};

/*
Direction vers laquelle il va :
0 : Nord
1 : Sud
2 : Est
3 : Ouest
*/

pii nextPos(int i, int j, int dir) {
    if (dir == 0) return mp(i-1, j);
    else if (dir == 1) return mp(i+1, j);
    else if (dir == 2) return mp(i, j+1);
    else return mp(i, j-1);
}

int dist(pii dep, int i, int j, int dir) {
    if (i < 0 || i >= l || j < 0 || j >= c) return 0;
    if (d[i][j][dir] > 0);
    else {
        int nxtdir = nxt_dir[mp(dir, grid[i][j])];
        pii p = nextPos(i, j, nxtdir);
        if (p.fi < 0 || p.fi >= l || p.se < 0 || p.se >= c) d[i][j][dir] = 1;
        else if (p.fi == dep.fi && p.se == dep.se) d[i][j][dir] = 1;
        else d[i][j][dir] = 1 + dist(dep, p.fi, p.se, nxtdir);
    }
    return d[i][j][dir];
}

int solve() {
    int maxdist = 0;
    for (int i=0; i<l; ++i) {
        for (int j=0; j<c; ++j) {
            for (int dir=0; dir<4; ++dir)
            maxdist = max(maxdist, dist(mp(i,j), i, j, dir));
        }
    }
    return maxdist;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> c;
    grid.assign(l, vector<char> (c));
    for (int i=0; i<l; ++i) {
        for (int j=0; j<c; ++j) cin >> grid[i][j];
    }
    d.assign(l, vvi(c, vi(4, 0)));
    cout << solve() << nl;
	return 0;
}
