/*
* Author:  Léopold Bernard
* Created: 18/08/2024 01:11:03
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

ll solve(int n, int m, int k, int w, vll &a) {
    ll ans = 0;
    vll timesCounted;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            // cb d'intervalles de taille k passent sur i, j ?
            // premier ? [0, k-1] ? dernier : [i, i+k-1] if j+k-1=n-1
            // interval is of the form [j, j+k-1] -> j+k-1=i -> 
            ll m1 = 1 + min(i, n-k) - max(0, i-k+1);
            ll m2 = 1 + min(j, m-k) - max(0, j-k+1);
            //cout << m1 * m2 << " ";
            timesCounted.pb(m1 * m2);
        }
        //cout << nl;
    }
    sort(all(timesCounted));
    sort(all(a));
    for (int i=w-1; i>=0; --i) {
        ans += a[i] * timesCounted[n*m-w+i];
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, m, k, w; cin >> n >> m >> k >> w;
        vll a(w); for (ll &x: a) cin >> x;
        cout << solve(n, m, k, w, a) << nl;
	}
	return 0;
}
