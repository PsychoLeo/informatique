/*
* Author:  Léopold Bernard
* Created: 26/09/2024 10:30:00
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

int smallestWithOnes(int x, int y) {
    int b = 1;
    while ((x | b) <= y) {
        x |= b; b *= 2;
    }
    return x;
}

int minPow2(int n) {
    // smallest power of 2 >= n
    int p = 1;
    while (p < n) {
        p *= 2;
    }
    return p;
}

pii combine(pii p1, pii p2) {
    int x1 = p1.fi, y1 = p1.se, x2 = p2.fi, y2 = p2.se;
    int a = (x1 | x2), b = (x1 | y2), c = (y1 | x2), d = (y1 | y2);
    int cnt = __builtin_popcount(a);
    int x = a;
    for (int v: {b, c, d}) {
        int newcnt = __builtin_popcount(v);
        if (newcnt > cnt) {
            cnt = newcnt;
            x = v;
        }
    }
    return mp(x, max({a, b, c, d}));
}

int binExp(int a, int n) {
    int ans = 1;
    while (n) {
        if (n % 2) ans = (ans * a);
        a = (a * a);
        n /= 2;
    }
    return ans;
}

void print_pair(pii p) {
    cout << '(' << p.fi << ',' << p.se << ')' << " ";
}

struct BinTree {
    int n;
    vector<pii> tree;
    int p;

    void print() {
        for (int i=0; (1<<i)<=p; ++i) {
            for (int j=(1<<i); j<(1<<(i+1)); ++j) {
                cout << '(' << tree[j].fi << ',' << tree[j].se << ')' << ' ';
            }
            cout << nl;
        }
    }

    void init(int nn, vector<pii> &ntr) {
        n = nn;
        p = minPow2(n);
        tree.resize(2*p, mp(0, 0));
        for (int i=0; i<n; ++i) {
            tree[p+i] = ntr[i];
        }
        for (int i=p-1; i>0; --i) {
            tree[i] = combine(tree[2*i], tree[2*i+1]);
        }
    }

    pii maxv(int l, int r, int i, int j, int node) {
        if (j <= l || i >= r) return mp(0, 0);
        else if (i >= l && j <= r) return tree[node];
        else {
            int mid = (i + j) / 2;
            pii left = maxv(l, r, i, mid, 2*node);
            pii right = maxv(l, r, mid, j, 2*node+1);
            return combine(left, right);
        }
    }

    int query(int l, int r) {
        return maxv(l, r, 0, p, 1).se;
    }

};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        vector<pii> a(n);
        for (int i=0; i<n; ++i) {
            int x, y; cin >> x >> y;
            x = smallestWithOnes(x, y);
            a[i] = mp(x, y);
        }
        BinTree tr;
        tr.init(n, a);
        tr.print();
        // cout << tr.tree[2].fi << " " << tr.tree[2].se << nl;
        int q; cin >> q;
        while (q--) {
            int l, r; cin >> l >> r; --l;
            // convention : l included, r excluded
            cout << tr.query(l, r) << " ";
        }
        cout << nl;
	}
	return 0;
}
