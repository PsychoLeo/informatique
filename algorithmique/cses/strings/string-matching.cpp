/*
* Author:  Léopold Bernard
* Created: 26/11/2024 17:07:09
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

#define MOD 100000007
#define INF (int)1e9

ll p = 31;
ll pp = 43;
string s, t;
int n, m;
ll invp, invpp;

ll binPow(ll a, ll r) {
    ll ans = 1;
    while (r) {
        if (r % 2) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        r /= 2;
    }
    return ans;
}

int solve() {
    if (n < m) return 0;
    int c = 0;
    ll v = 0;
    ll currh = 0;
    ll currhp = 0;
    ll vp = 0;
    ll pow = 1;
    ll powp = 1;
    for (int i=0; i<m; ++i) {
        v = (v + (t[i]-'a') * pow) % MOD;
        vp = (vp + (t[i]-'a') * powp) % MOD;
        currh = (currh + (s[i]-'a') * pow) % MOD;
        currhp = (currhp + (s[i]-'a') * powp) % MOD;
        pow = (pow * p) % MOD;
        powp = (powp * pp) % MOD;
    }
    pow = (pow * invp) % MOD;
    powp = (powp * invpp) % MOD;
    if (currh == v && currhp == vp) c++;
    for (int i=m; i<n; ++i) {
        currh -= (s[i-m]-'a');
        currh = ((currh + MOD) % MOD + MOD) % MOD;
        currh = (currh * invp) % MOD;
        currh = (currh + pow * (s[i]-'a')) % MOD;
        currhp -= (s[i-m]-'a');
        currhp = ((currhp + MOD) % MOD + MOD) % MOD;
        currhp = (currhp * invpp) % MOD;
        currhp = (currhp + powp * (s[i]-'a')) % MOD;
        if (currh == v && currhp == vp) c++;
    }
    return c;
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> t;
    n = sz(s); m = sz(t);
    invp = binPow(p, MOD-2);
    invpp = binPow(pp, MOD-2);
    cout << solve() << nl;
	return 0;
}
