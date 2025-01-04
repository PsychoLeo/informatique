/*
* Author:  Léopold Bernard
* Created: 28/11/2024 18:01:46
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
vll vals, sal;
vector<array<ll, 3>> queries;
vll tree;

void print() {
    for (int i=0; i<2*p; ++i) {
        cout << tree[i] << ' ' ;
        if ((i & (i+1)) == 0) cout << nl;
    }
}

ll count(int node, int l, int r, int i, int j) {
    // a, b included, l included, r excluded
    if (r <= i || l > j) return 0;
    else if (i <= l && r<= j+1) return tree[node];
    int mid = (r + l)/2;
    return count(2*node, l, mid, i, j) + count(2*node+1, mid, r, i, j);
}

void update(int i, int delta) {
    int nj = (i + p)/2;
    tree[i+p] += delta;
    while (nj > 0) {
        tree[nj] = tree[2*nj] + tree[2*nj+1];
        nj /= 2;
    }
}

void solve() {
    for (auto u: queries) {
        if (u[0] == 0) {
            // we have a ! query, ie two next elements are k and x
            int k = u[1]-1;
            ll x = u[2];
            ll old_x = sal[k];
            sal[k] = x;
            // find the index of old_x in vals :
            int j = lower_bound(all(vals), old_x) - vals.begin();
            if (vals[j] != old_x) debug(old_x);
            update(j, -1);
            int m = lower_bound(all(vals), x) - vals.begin();
            if (vals[m] != x) debug(x);
            update(m, 1);
        }
        else {
            // we have a ? query, ie two next elements are a and b
            ll a = u[1], b = u[2];
            int i = lower_bound(all(vals), a) - vals.begin();
            int j = upper_bound(all(vals), b) - vals.begin()-1;
            cout << count(1, 0, p, i, j) << nl;
        }
    }
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
    for (int i=0; i<n; ++i) {
        ll x; cin >> x; vals.pb(x);
        sal.pb(x);
    }
    for (int i=0; i<q; ++i) {
        char c; ll a, b; 
        cin >> c >> a >> b;
        queries.pb({(c=='?'), a, b});
        if (c == '!') vals.pb(b);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    // for (int x: vals) cout << x << nl;
    p = 1<<(32-__builtin_clz(sz(vals)-1));
    tree.assign(2*p, 0);
    for (int x: sal) {
        int m = lower_bound(all(vals), x) - vals.begin();
        if (vals[m] != x) debug(x);
        update(m, 1);
    }
    solve();
	return 0;
}
