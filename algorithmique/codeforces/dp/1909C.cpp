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

const int MOD = 1000000007;
const ll INF = 1e18; 

ll solve(int n, vi &l, vi &r, vi &c) {
    // Inégalité de réarrangement : SUM(a_k * b_s(k)) >= SUM (a_k * b_k)
    set<int> setl;
    for (int x: l) setl.emplace(x);
    ll S = 0;
    rep(i, 0, n) {
        int x = *(--setl.lower_bound(r[i]));
        S += c[n-1-i]*(r[i]-x);
        setl.erase(x);
    }
    return S;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi l(n); vi r(n); vi c(n);
        rep(i, 0, n) cin >> l[i];
        rep(i, 0, n) cin >> r[i];
        rep(i, 0, n) cin >> c[i];
        sort(all(l));
        sort(all(r));
        sort(all(c));
        cout << solve(n, l, r, c) << "\n";
    }
	return 0;
}
