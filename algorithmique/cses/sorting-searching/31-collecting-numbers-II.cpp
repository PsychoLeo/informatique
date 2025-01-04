/*
* Author:  Léopold Bernard
* Created: 19/10/2024 12:58:11
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
    vi ind(n+2);
    vi a(n+2); 
    ind[0] = -INF; ind[n+1] = INF;
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        ind[x] = i;
        a[i] = x;
    }
    int ans = 0;
    for (int i=1; i<=n; ++i) {
        ans++;
        while (i < n && ind[i] < ind[i+1]) ++i;
    }
    // cout << ans << nl;
    while (m--) {
        int i, j; cin >> i >> j;
        int vi = a[i], vj = a[j];
        swap(a[i], a[j]);
        if (vi > vj) swap(vi, vj);
        // on a vi <= vj
        int delta = 0;
        if (ind[vi] < ind[vi+1] && ind[vj] > ind[vi+1]) delta++;
        else if (ind[vi] > ind[vi+1] && ind[vj] < ind[vi+1]) delta--;
        if (ind[vi-1] < ind[vi] && ind[vi-1] > ind[vj]) delta++;
        else if (ind[vi-1] > ind[vi] && ind[vi-1] < ind[vj]) delta--;
        if (ind[vj] < ind[vj+1] && ind[vi] > ind[vj+1]) delta++;
        else if (ind[vj] > ind[vj+1] && ind[vi] < ind[vj+1]) delta--;
        if (ind[vj-1] < ind[vj] && ind[vj-1] > ind[vi]) delta++;
        else if (ind[vj-1] > ind[vj] && ind[vj-1] < ind[vi]) delta--;
        if (vi == vj-1) {
            if (delta < 0) delta = -1;
            else if (delta > 0) delta = 1;
        }
        ans += delta;
        swap(ind[vi], ind[vj]);
        cout << ans << nl;
    }
	return 0;
}
