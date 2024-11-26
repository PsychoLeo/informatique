/*
* Author:  Léopold Bernard
* Created: 26/11/2024 14:26:29
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

int n, p;
vll tree;

void print() {
    for (int i=1; i<2*p; ++i) {
        cout << tree[i] << ' ';
        if ((i & (i+1)) == 0) cout << nl;
    }
    cout << nl;
}

void update(int node, int l, int r, int i, int j, int u) {
    if (r <= i || l > j) return;
    if (i <= l && r <= j+1) {
        tree[node] += u;
        return;
    }
    if (node >= p) {
        tree[node]+= u;
        return;
    }
    int mid = (r+l)/2;
    update(2*node, l, mid, i, j, u);
    update(2*node+1, mid, r, i, j, u);
}

int find(int i) {
    int ans = i;
    int j = (i+p)/2;
    while (j > 0) {
        ans += tree[j];
        j /= 2;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    p = 1<<(32-__builtin_clz(n));
    tree.resize(2*p, 0);
    vi x(n);
    for (int i=0; i<n; ++i) cin >> x[i];
    // print();
    for (int i=0; i<n; ++i) {
        int j; cin >> j; --j;
        int nj = find(j); cout << x[nj] << ' ';
        update(1, 0, p, j, n-1, 1);
        // print();
    }
    cout << nl;
	return 0;
}
