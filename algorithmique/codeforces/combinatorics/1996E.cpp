/*
* Author:  Léopold Bernard
* Created: 08/08/2024 13:13:35
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

ll solve(string &s) {
    vll v = {0};
    int n = sz(s);
    for (int i=0; i<n; ++i) {
        v.pb(v[i] + ((s[i] == '0') ? -1 : 1));
    }
    map<ll, ll> cnt;
    for (int i=0; i<=n; ++i) {
        if (cnt.find(v[i]) == cnt.end()) cnt[v[i]] = i+1;
        else cnt[v[i]] += (i+1);
    }
    ll ans = 0;
    for (int l = n; l>0; --l) {
        cnt[v[l]] -= (l+1);
        ll add = ((n-l+1) * cnt[v[l]]) % MOD;
        ans = (ans + add) % MOD;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        string s; cin >> s;
        cout << solve(s) << nl;
	}
	return 0;
}
