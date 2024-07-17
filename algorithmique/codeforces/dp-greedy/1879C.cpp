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

#define MOD 998244353
#define INF 

pair<int, long> solve(string &s) {
    ll p = 1;
    int c = 0;
    int n = (int)s.size();
    vi fact(n+1, 1);
    ll f = 1;
    rep (i, 1, n+1) {
        f = (f * i) % MOD;
        fact[i] = f;
        // debug(fact[i]);
    }
    int numChanges = 0;
    for (int i=0; i<n;) {
        char curr = s[i];
        int j = i+1;
        int len = 1;
        if (j < n && s[j] == curr) numChanges++;
        while (j < n && s[j] == curr) {
            ++len; ++j; ++c;
        }
        // debug(len);
        p = (p*fact[len]) % MOD;
        i = j;
    }
    p = (p * fact[numChanges]) % MOD;
    return mp(c, p);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        string s; cin >> s;
        pair<int, long> res = solve(s);
        cout << res.fi << " " << res.se << "\n";
	}
	return 0;
}
