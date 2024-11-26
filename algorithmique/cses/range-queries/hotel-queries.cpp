/*
* Author:  Léopold Bernard
* Created: 26/11/2024 13:51:35
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

int n, m, p;
vll tree;

void update(int i, ll v) {
    tree[p+i] = v;
    int j = (p+i)/2;
    while (j > 0) {
        tree[j] = max(tree[2*j], tree[2*j+1]);
        j /= 2;
    }
}

int findSmallest(ll x, int node) {
    if (x > tree[node]) return 0;
    if (node >= p) return node;
    else if (tree[2*node] >= x) return findSmallest(x, 2*node);
    else return findSmallest(x, 2*node+1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    p = 1<<(32-__builtin_clz(n));
    tree.assign(2*p, 0);
    for (int i=0; i<n; ++i) {
        ll x; cin >> x; update(i, x);
    }
    while (m--) {
        ll r; cin >> r; int i = findSmallest(r, 1);
        cout << ((i == 0) ? 0 : i-p+1) << ' ';
        // debug(tree[i]-r);
        update(i-p, tree[i]-r);
    }
    cout << nl;
	return 0;
}
