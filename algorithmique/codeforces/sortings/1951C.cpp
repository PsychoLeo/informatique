/*
* Author:  Léopold Bernard
* Created: 26/09/2024 16:39:00
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

ll compute(int len, int m, int k, int i, vector<pii> &a, vll &pf) {
    // pour j allant de 0 à i-1, on calcule normalement, ensuite on ajoute le terme d'indice i, puis la suite 
    int delta = k - m * (k / m);
    ll pre = 1LL * m * pf[i] + 1LL * m * m * i * (i-1) / 2;
    ll mid = 1LL * delta * (a[i].se + m * i);
    ll post = 1LL * m * delta * (len-i-1) + 1LL * m * (pf[len]-pf[i+1]);
    ll sumj = 1LL * (len - i - 2) * (len - i - 1) / 2 + 1LL * i * (len-i-1);
    post += 1LL * m * m * sumj;
    if (i == len-1) post = 0;
    if (i == 0) pre = 0;
    // cout << pre << " " << mid << " " << post << nl;
    return pre + mid + post;
}

ll solve(int m, int k, vector<pii> &a) {
    ll ans = 0;
    sort(all(a));
    int len = (k % m) ? (k/m + 1) : k/m;
    if (k % m == 0) {
        ll cnt = 0;
        for (int i=0; i<len; ++i) {
            ans += 1LL * m * (a[i].fi + cnt);
            cnt += 1LL * m;
        }
    }
    else {
        vector<pii> a2;
        for (int i=0; i<len; ++i) {
            pii p = a[i];
            a2.pb(mp(p.se, p.fi));
        }
        sort(all(a2));
        // for (pii p: a2) cout << p.se << " ";
        // cout << nl;
        vll pref = {0};
        for (int i=0; i<len; ++i) pref.pb(pref.back() + a2[i].se);
        ans = compute(len, m, k, 0, a2, pref);
        // debug(ans);
        for (int i=1; i<len; ++i) {
            ll v = compute(len, m, k, i, a2, pref);
            // debug(v); debug(i);
            ans = min(ans, v);
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<pii> a(n); 
        for (int i=0; i<n; ++i) {
            int x; cin >> x;
            a[i] = mp(x, i);
        }
        cout << solve(m, k, a) << nl;
	}
	return 0;
}
