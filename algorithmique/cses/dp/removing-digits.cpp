/*
* Author:  Léopold Bernard
* Created: 01/12/2024 23:39:44
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

int n;
vi dp;

unordered_set<int> digits(int m) {
    if (m == 0) return {};
    int x = m%10;
    unordered_set<int> v = digits(m/10);
    v.emplace(x);
    return v;
}

int solve(int m) {
    if (m == 0) return 0;
    int ans = INF;
    for (int x: digits(m)) {
        if (x) {
            if (dp[m-x] > 0) ans = min(ans, 1+dp[m-x]);
            else ans = min(ans, 1+solve(m-x));
        }
    }
    dp[m] = ans;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    dp.resize(n+1, 0);
    for (int i=1; i<min(10, n); ++i) dp[i] = 1;
    // debug(n);
    cout << solve(n) << nl;
	return 0;
}
