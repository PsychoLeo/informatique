/*
* Author:  Léopold Bernard
* Created: 17/08/2024 17:19:44
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

ll solve (vi &n, vi &p, vi &b , ll r) {
    ll ans = 0;
    // using what we already have left to try buying
    for (int i:{0, 1, 2}) if (b[i] == 0) n[i] = 0;
    while (r >= 0) {
        if (n[0] >= b[0] && n[1] >= b[1] && n[2] >= b[2]) {
            ans++;
            if (n[0] == b[0] && n[1] == b[1] && n[2] == b[2]) break;
            else for (int i:{0, 1, 2}) n[i] -= b[i];
        }
        for (int i: {0, 1, 2}) if (n[i] < b[i]) {
            r -= p[i]; n[i]++;
        }
    }
    // buying entire burgers
    if (r < 0) return ans;
    int burgerPrice = b[0] * p[0] + b[1] * p[1] + b[2] * p[2];
    //debug(burgerPrice);
    ans += r / burgerPrice;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
	vi n(3, 0), p(3, 0), cost(3, 0);
    for (char c : s) {
        if (c == 'B') ++cost[0];
        else if (c == 'S') ++cost[1];
        else ++cost[2];
    }
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    ll r; cin >> r;
    cout << solve(n, p, cost, r) << nl;
	return 0;
}
