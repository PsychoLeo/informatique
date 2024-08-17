/*
* Author:  Léopold Bernard
* Created: 16/08/2024 17:16:46
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

ll count(int x, int n, vi &cnt, vector<pii> &cntv) {
    ll ans = 0;
    for (int l=1; l<=n; ++l) {
        int v = x + cnt[l-1];
        int depInd = n+l-1;
        if (v < sz(cntv)) {
            pii p = cntv[v];
            int ind = p.fi, num = p.se;
            if (ind >= depInd) ans += num;
            else ans += max(0, num+ind-depInd);
        }
    }
    return ans;
}

int solve(int n, string &s) {
    vi cnt(2 * n, 0);
    for (int i=1; i<2*n; ++i) {
        cnt[i] = cnt[i-1] + (s[i-1] == 'W');
    }
    vector<pii> cntv;
    for (int i=0; i<2*n; ++i) {
        if (cnt[i] >= sz(cntv)) {
            cntv.pb(mp(i, 1));
        }
        else cntv.back().se++;
    }
    int lo = 0, hi = cnt[2*n-1]; // if x > number of W's, impossible
    while (lo < hi) {
        int mid1 = (2 * lo + hi) / 3;
        int mid2 = (2 * hi + lo) / 3;
        ll c1 = count(mid1, n, cnt, cntv);
        ll c2 = count(mid2, n, cnt, cntv);
        if (c1 >= n) return mid1;
        if (c2 >= n) return mid2;
        if (c1 > c2) hi = mid2-1;
        else lo = mid1+1; 
    }
    return lo;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
    string s; cin >> s;
    cout << solve(n, s) << nl;  
	return 0;
}
