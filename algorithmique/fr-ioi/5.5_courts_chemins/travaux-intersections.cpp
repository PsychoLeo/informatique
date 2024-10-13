/*
* Author:  Léopold Bernard
* Created: 13/10/2024 11:11:03
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

int n, m;
vector<vector<pii>> adj;
vvi d;

void printGrid() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (d[i][j] >= INF) cout << ". ";
            else cout << d[i][j] << " ";
        }
        cout << nl;
    }
}

void solve() {
    for (int u=0; u<n; ++u) d[u][u] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
        printGrid();
        cout << nl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    adj.assign(n, vector<pii>(n));
    d.assign(n, vi(n, +INF));
    int u, v, x;
    for (int i=0; i<m; ++i) {
        cin >> u >> v >> x;
        --u; --v;
        adj[u].pb(mp(v, x));
        d[u][v] = x;
    }
    solve();
	return 0;
}
