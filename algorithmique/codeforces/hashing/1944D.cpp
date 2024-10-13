/*
* Author:  Léopold Bernard
* Created: 22/09/2024 18:28:55
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

const int p = 31;
const int mod = 1e9+7;

vll pf;
vll sf;
vll invp;

ll binexp(ll a, int n) {
    ll ans = 1;
    while (n) {
        if (n % 2) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return ans;
}

void init_vectors(int n, string &s) {
    pf.assign(n+1, 0);
    sf.assign(n+1, 0);
    invp.assign(n+1, 1);
    ll inv = binexp(p, mod-2);
    for (int i=0; i<n; ++i) {
        pf[i+1] = (pf[i] + (s[i]-'a'+1) * binexp(p, i)) % mod;
    }
    for (int i=n-1; i>=0; --i) {
        sf[i] = (sf[i+1]+(s[i]-'a'+1) * binexp(p, n-1-i)) % mod;
    }
    for (int i=1; i<=n; ++i) {
        invp[i] = (invp[i-1] * inv) % mod;
    }
}

ll solve (int l, int r, int n, string &s) {
    ll S = 0;
    if (!ispal(l, r, n, s)) S += (r-l+1);
}

bool ispal(int l, int r, int n, string &s) {
    int mid = (l + r)/2;
    int len = r-l+1;
    if (len <= 1) return true;
    ll leftv, rightv;
    if (len % 2) {
        leftv = (((pf[mid] - pf[l]) * invp[l]) % mod + mod) % mod;
        rightv = (((sf[mid+1] - sf[r+1]) * invp[n-1-r]) % mod + mod) % mod;
    }
    else {
        leftv = (((pf[mid] - pf[l]) * invp[l]) % mod + mod) % mod;
        rightv = 0;
    }
    return (leftv == rightv);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;
        init_vectors(n, s);
        while (q--) {
            int l, r; cin >> l >> r; l--; r--;
            cout << solve(l, r, n, s) << nl;
        }
	}
	return 0;
}
