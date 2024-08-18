/*
* Author:  Léopold Bernard
* Created: 18/08/2024 11:26:33
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

void printBinTree(int n, vi &tree) {
    for (int h=0; h<=n; ++h) {
        for (int i=(1<<h); i<(1<<(h+1)); ++i) {
            cout << tree[i] << " ";
        }
        cout << nl;
    }
}

int fillBinTree(int op, int i, vi &tree) {
    if (tree[i] == -1) {
        int left = fillBinTree(1-op, 2*i, tree);
        int right = fillBinTree(1-op, 2*i+1, tree);
        tree[i] = ((!op) ? (left ^ right) : (left | right));
    }
    return tree[i];
}

int solve(int p, int b, vi &tree) {
    int ans = b;
    int op = 1; // or -> 1, xor->0
    while (p > 1) {
        tree[p] = ans;
        if (op == 1) ans |= ((p%2) ? tree[p-1] : tree[p+1]);
        else ans ^= ((p%2) ? tree[p-1] : tree[p+1]);
        p /= 2; op = 1-op;
    }
    tree[1] = ans;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
    int p2 = (1<<n);
    vi tree(2*p2, -1);
    for (int i=0; i<p2; ++i) {
        cin >> tree[i+p2];
    }
    fillBinTree((n%2), 1, tree);
    // printBinTree(n, tree);
    for (int i=0; i<m; ++i) {
        int p, b; cin >> p >> b;
        cout << solve(p-1+p2, b, tree) << nl;
    }
	return 0;
}
