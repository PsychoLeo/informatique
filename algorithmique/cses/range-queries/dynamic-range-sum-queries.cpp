/*
* Author:  Léopold Bernard
* Created: 25/11/2024 22:30:06
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

int n, q, p;
vll tree;

int msb(int x) {
    //assert(x>0);
    return 1<<(31-__builtin_clz(x));
}

void update(ll v, int i) {
    tree[p+i] = v;
    int j = (p+i)/2;
    while (j > 0) {
        tree[j] = tree[2*j] + tree[2*j+1];
        j /= 2;
    }
}

ll query(int node, int l, int r, int i, int j) {
    if (r <= i || l > j) return 0;
    // debug(node);
    if (i <= l && r <= j+1) return tree[node];
    int mid = (r+l)/2;
    return query(2*node, l, mid, i, j) + query(2*node+1, mid, r, i, j);
}

void print() {
    for (int i=1; i<2*p; ++i) {
        cout << tree[i] << ' ';
        if ((i & (i+1)) == 0) cout << nl;
    }
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
    p = 2*msb(n);
    tree.resize(2*p, 0);
    for (int i=0; i<n; ++i) {
        ll x; cin >> x; update(x, i);
    }
    //print();
    //debug(p);
    while (q--) {
        int query_type; cin >> query_type;
        if (query_type == 1) {
            int i; cin >> i; --i;
            ll v; cin >> v;
            update(v, i);
        }
        else {
            int i, j; cin >> i >> j;
            --i; --j;
            cout << query(1, 0, p, i, j) << nl;
        }
    }
	return 0;
}
