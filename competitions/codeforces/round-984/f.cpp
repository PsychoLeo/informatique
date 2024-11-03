/*
* Author:  Léopold Bernard
* Created: 03/11/2024 01:13:06
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

ll l, r, k;
int i;

ll nthBitCountInRange(int n, ll R) {
    return max(0LL, R%(1LL<<(n+1))-(1LL<<n)+1) + (1LL<<n)*(R / (1LL<<(n+1)));
}

ll xor_range(ll R) {
    ll ans = 0;
    ll v = nthBitCountInRange(0, R);
    for (int j=0; v > 0; ++j) {
        if (v % 2) ans |= (1LL<<j);
        v = nthBitCountInRange(j+1, R);
    }
    return ans;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        cin >> l >> r >> i >> k;
        ll ans = xor_range(r);
        // debug(ans);
        if (l-1 >= 0) ans ^= xor_range(l-1);
        ll m = (r-k) / (1LL<<i);
        ll p = (l-1-k) / (1LL<<i);
        //debug(m); debug(p);
        if (r >=k) {
            if (m % 2 == 0) ans ^= k;
            ans ^= (xor_range(m) << i);
            // debug(ans);
        }
        if (l-1>=k) {
            if (p % 2 == 0) ans ^= k;
            ans ^= (xor_range(p) << i);
        }
        cout << ans << nl;
	}
	return 0;
}
