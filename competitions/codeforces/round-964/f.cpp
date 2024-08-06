/*
* Author:  Léopold Bernard
* Created: 06/08/2024 20:15:54
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

#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define MAX (ll)(2e5+5) 

ll fact[MAX];
ll ifact[MAX]; // inverse factorial

ll binexp(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n % 2) ans = (ans * a) % MOD;
        n /= 2;
        a = (a * a) % MOD; 
    }
    return ans;
}

void fill() {
    fact[0] = 1;
    for (int i=1; i<MAX; ++i) {
        fact[i] = (i * fact[i-1]) % MOD;
    }
    ifact[0] = 1;
    for (int i=1; i<MAX; ++i) {
        ifact[i] = binexp(fact[i], MOD-2);
    }
}

ll parmi (int k, int n) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    ll p = (fact[n] * ifact[k]) % MOD;
    p = (p * ifact[n-k]) % MOD;
    return p;
}

ll solve (int n, int k, vi &a) {
    ll ans = 0;
    int m = (k+1)/2;
    // find the number of subseq where there are >= m number of 1s
    int N = 0;
    for (int x : a) if (x == 1) N++;
    debug(N);
    if (m > N) return 0;
    // ANS = SUM(i=m -> k) (i parmi N) * (k-i parmi n-N)
    for (int i=m; i<=k; ++i) {
        ll p1 = parmi(i, N);
        ll p2 = parmi(k-i, n-N);
        debug(p1); debug(p2);
        ans = (ans + (p1 * p2) % MOD) % MOD;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
    fill();
	while (t--) {
        int n, k; cin >> n >> k;
        vi a(n); for (int &x : a) cin >> x;
        cout << solve(n, k, a) << nl;
	}
	return 0;
}
