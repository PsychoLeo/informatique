/*
* Author:  Léopold Bernard
* Created: 17/12/2024 10:10:47
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

struct node {
    int mx, mn, mult, add;
};

int n, q, p;
vector<node> tree;

void mult(int v, int l, int r, int i, int j, int m) {
    // i, j inclus, l inclus, r exclu
    if (l>j || r<= i) return;
    else if (l<=i && j<=r+1) {
        tree[v].mult *= m;
    }
    else {
        int mid = (l+r)/2;
        mult(2*v, l, mid, i, j, m);
        mult(2*v+1, mid, r, i, j, m);
    }
}

void add(int v, int l, int r, int i, int j, int m) {
    // i, j inclus, l inclus, r exclu
    if (l>j || r<= i) return;
    else if (l<=i && j<=r+1) {
        tree[v].add += m;
    }
    else {
        int mid = (l+r)/2;
        add(2*v, l, mid, i, j, m);
        add(2*v+1, mid, r, i, j, m);
    }
}

int query(int v, int l, int r, int i, int j) {

}

void push(int v) {
    int m = tree[v].mult;
    int a = tree[v].add;
    // on effectue la multiplication
    tree[v].mx *= m;
    tree[v].mn *= m;
    if (m != 1) swap(tree[v].mx, tree[v].mn);
    tree[v].mult = 1;
    // on la propage
    if (v < p) {
        tree[2*v].mult *= m;
        tree[2*v+1].mult *= m;
    }
    // on effectue l'addition
    tree[v].mx += a;
    tree[v].mn += a;
    // on propage l'addition
    if (v < p) {
        tree[2*v].add += a;
        tree[2*v+1].add += a;
    }
    tree[v].add = 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
    p = (1<< (31-__builtin_clz(n)));
    tree.assign(2*p, node{0, 0, 1, 0});
    while (q--) {
        int type; cin >> type;
        if (type == 0) { // multiplication
            int a, b, m; cin >> a >> b >> m;
            mult(1, 0, p, a, b, m);
        }
        else if (type == 1) { // ajout
            int a, b, m; cin >> a >> b >> m;
            add(1, 0, p, a, b, m);
        }
        else {
            int a, b; cin >> a >> b;
            cout << query(1, 0, p, a, b) << nl;
        }
    }
	return 0;
}
