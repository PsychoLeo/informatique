/*
* Author:  Léopold Bernard
* Created: 29/11/2024 17:46:48
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

struct Node {
    ll sum, pf, sf, ans; // sum of the whole range, max prefix in range
};

int n, q, p;
vector<Node> tree;

Node combine(Node l, Node r) {
    Node res;
    res.sum = l.sum + r.sum;
    res.pf = max(l.pf, l.sum + r.pf);
    res.sf = max(r.sf, r.sum + l.sf);
    res.ans = max(max(l.ans, r.ans), l.sf + r.pf);
    return res;
}

void update(int i, Node v) {
    tree[i+p] = v;
    int j = (i + p)/2;
    while (j) {
        tree[j] = combine(tree[2*j], tree[2*j+1]);
        j /= 2;
    }
}

Node query(int v, int l, int r, int i, int j) {
    if (r <= i || l > j) return Node{0, 0, 0, 0};
    else if (i <= l && r <= j+1) return tree[v];
    int mid = (l + r)/2;
    return combine(query(2*v, l, mid, i, j), query(2*v+1, mid, r, i, j));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
    p = 1<<(32-__builtin_clz(n-1));
    tree.resize(2*p, Node{0, 0, 0, 0});
    for (int i=0; i<n; ++i) {
        Node res;
        int s; cin >> s;
        res.sum = s;
        res.pf = max(0, s);
        res.sf = max(0, s);
        res.ans = max(0, s);
        update(i, res);
    }
    while (q--) {
        int k; ll x; cin >> k >> x;
        --k; update(k, Node{x, max(0LL, x), max(0LL,x), max(0LL, x)});
        cout << query(1, 0, p, 0, n-1).ans << nl;
    }
	return 0;
}
