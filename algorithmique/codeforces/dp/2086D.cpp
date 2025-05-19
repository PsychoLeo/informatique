/*
* Author:  Léopold Bernard
* Created: 22/04/2025 17:01:07
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

#define MOD 998244353
#define INF (int)1e9
#define MX 500005
#define n 26

vll c(n);
ll fact_inv[MX];
ll fact[MX];
ll s;
vector<vll> dp;

ll binpow(ll x, ll p) {
	ll ans = 1;
	while (p) {
		if (p % 2) ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		p >>= 1;
	}
	return ans;
}

ll parmi(ll a, ll b) {
	// O(1) complexity
	if (a > b) return 0;
	ll ans = fact[b];
	ans = (ans * fact_inv[b-a]) % MOD;
	ans = (ans * fact_inv[a]) % MOD;
	return ans;
}

void print() {
	for (int k=0; k<10; ++k) cout << fact_inv[k] << " ";
	cout << nl;
	cout << parmi(0, 10) << nl;
	cout << parmi(0, 11) << nl;
	for (int k=0; k<10; ++k) cout << fact[k] << " ";
	cout << nl;
}


void fill() {
	fact_inv[0] = fact_inv[1] = 1;
	fact[0] = fact[1] = 1;
	for (int k=2; k<MX; ++k) {
		fact_inv[k] = (fact_inv[k-1] * binpow(k, MOD-2)) % MOD;
		fact[k] = (fact[k-1] * k) % MOD;
	}
}

ll get(int i, int even) {
	if (i < 0 && even != 0) return 0;
	else if (i < 0 && even == 0) return 1;
	if (even < 0) return 0;
	int odd = s - even;
	for (int k=n-1; k>i; --k) odd -= c[k];
	if (odd < 0) return dp[i][even] = 0;
	if (dp[i][even] != -1) return dp[i][even];
	ll ans = 0;
	ll pe = parmi(c[i], even), po = parmi(c[i], odd);
	if (pe) ans += (get(i-1, even-c[i]) * pe) % MOD;
	if (po) ans += (get(i-1, even) * po) % MOD;
	ans %= MOD;
	return dp[i][even] = ans;
}

ll solve() {
	return get(n-1, s-s/2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	fill();
	print();
	while (t--) {
		s = 0;
		for (ll &ci: c) {
			cin >> ci;
			s += ci;
		}
		dp.clear();
		dp.assign(n, vll(s, -1));
		cout << solve() << nl;
	}
	return 0;
}
