/*
* Author:  Léopold Bernard
* Created: 13/10/2024 11:34:00
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

struct UF {

    int n;
    vi size;
    vi parent;

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets(int a, int b) { // union avec prise en compte des tailles
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int find_set(int v) { // find avec compression de chemin
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

};


int n, m;
vector<pll> p;
vector<pll> d;
vector<int> req;
vector<tuple<ll, ll, ll>> edges;
UF points;

void solve() {
    req.assign(m, 1);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (i != j) {
                pll pi = p[i], pj = p[j];
                ll dist2 = (pi.fi-pj.fi) * (pi.fi-pj.fi) + (pi.se-pj.se) * (pi.se-pj.se);
                edges.pb(mt(dist2, i, j));
            }
        }
    }
    sort(all(edges));
    int j=0;
    for (pll pair: d) {
        while (j<(int)edges.size() && get<0>(edges[j]) <= (pair.fi) * (pair.fi)) {
            points.union_sets(get<1>(edges[j]), get<2>(edges[j]));
            ++j;
        }
        req[pair.se] = points.size[points.find_set(0)];
    }
    for (int i=0; i<m; ++i) {
        cout << n-req[i] << nl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    ll x, y, dist;
    points.n = n;
    for (int i=0; i<n; ++i) {
        points.parent.pb(i);
        points.size.pb(1);
        cin >> x >> y;
        p.pb(mp(x, y));
    }
    cin >> m;
    for (int i=0; i<m; ++i) {
        cin >> dist;
        d.pb(mp(dist, 1LL*i));
    }
    sort(all(d));
    solve();
	return 0;
}
