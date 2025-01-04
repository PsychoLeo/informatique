/*
* Author:  Léopold Bernard
* Created: 27/11/2024 15:50:38
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

string s;
int n;
vll ip;
vll p;
vll pfhash;

ll binexp(ll a, ll r) {
    ll ans = 1;
    while (r) {
        if (r % 2) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        r /= 2;
    }
    return ans;
}

ll _hash(int i, int j) {
    // hash of indexes between i and j (j is excluded)
    return (ip[i] * (pfhash[j]-pfhash[i]+MOD)) % MOD;
}

bool isperiod(int k) {
    for (int i=0; i<(n/k-1); ++i) {
        if (_hash(i*k, (i+1)*k) != _hash((i+1)*k, (i+2)*k)) return false;
    }
    return (_hash(k*(n/k), n) == _hash(0, n-k*(n/k)));
}

vb solve(int q) {
    p.assign(n+1, 1);
    ip.assign(n+1, 1);
    ll iq = binexp(q, MOD-2);
    ll currpow = 1, curripow = 1;
    for (int i=0; i<=n; ++i) {
        p[i] = currpow;
        ip[i] = curripow;
        currpow = (currpow * q) % MOD;
        curripow = (curripow * iq) % MOD;
    }
    pfhash = {0};
    for (int i=0; i<n; ++i) {
        ll v = (pfhash.back() + (s[i]-'a')*p[i]) % MOD;
        pfhash.pb(v);
    }
    vb ans(n, false);
    for (int i=1; i<=n; ++i) {
        // debug(i);
        if (isperiod(i)) ans[i-1] = true;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; n = sz(s);
    vb p1 = solve(31);
    vb p2 = solve(43);
    for (int i=0; i<n; ++i) {
        if (p1[i] && p2[i]) cout << i+1 << ' ';
    }
    cout << nl;
	return 0;
}
