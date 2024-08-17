/*
* Author:  Léopold Bernard
* Created: 13/08/2024 11:45:26
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
#define EPS 1e-12 

ll solve(int n, vi &a) {
    bool isincr = true;
    int j = (a[0]) ? 0 : n-1; // index of first element different of 1
    for (int i=1; i<n; ++i) {
        if (a[i] != 1) j = min(j, i);
        if (a[i] == 1 && a[i-1] > 1) return -1;
        else if (a[i] < a[i-1]) isincr = false;
    }
    if (isincr) return 0;
    ll ans = 0;
    vector<ld> na;
    for (int i=j; i<n; ++i) {
        ld llx = log2(log2((ld)a[i]));
        na.pb(llx);
    }
    int m = sz(na);
    ll toadd = 0;
    for (int i=1; i<m; ++i) {
        ld v = na[i-1] - na[i];
        if (v - floor(v) < EPS) v = floor(v);
        v = ceil(v);
        toadd = max(0LL, toadd + (ll)v);
        ans += toadd;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        vi a(n); for (int &x : a) cin >> x;
        cout << solve(n, a) << nl;
	}
	return 0;
}
