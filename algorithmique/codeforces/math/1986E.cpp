/*
* Author:  Léopold Bernard
* Created: 14/08/2024 17:15:06
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
#define rep(i, a, b) for(int i=a; i<(b); ++i)
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
#define INF 

ll mindist(int m, int k, vi &v) {
    // which index to remove will be optimal ?
    ll s = 0;
    for (int i=1; i<m; i+=2) {
        s += abs(v[i]-v[i+1]);
    }
    ll ans = s;
    for (int i=1; i<m; ++i) {
        // i index to remove
        if (i % 2) {
            s -= abs(v[i]-v[i+1]);
            s += abs(v[i-1]-v[i+1]);
        }
        else {
            s -= abs(v[i]-v[i-2]);
            s += abs(v[i-1]-v[i-2]);
        }
        chmin(ans, s);
    }
    return ans/k;
}

ll solve(int n, ll k, vll &a) {
    map<int, vi> congr;
    for (int x: a) {
        if (congr.find(x % k) == congr.end()) {
            congr[x%k] = {x};
        }
        else congr[x % k].pb(x);
    }
    int impaircnt = 0;
    for (auto it : congr) {
        if (sz(it.se) % 2) impaircnt++;
    }
    // debug(impaircnt);
    if (n % 2 && impaircnt > 1) return -1;
    else if ((n % 2 == 0) && impaircnt > 0) return -1;

    ll ans = 0;
    for (auto p : congr) {
        vi v = p.se;
        sort(all(v));
        int m = sz(v);
        if (m > 1) {
            if (m % 2) {
                ans += mindist(m, k, v);
            }
            else {
                for (int i=0; i<m-1; i+=2) {
                    ans += abs(v[i] - v[i+1]) / k;
                }
            }
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; ll k; cin >> n >> k;
        vll a(n); for (ll &x : a) cin >> x;
        cout << solve(n, k, a) << nl;
	}
	return 0;
}
