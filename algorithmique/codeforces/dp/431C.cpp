/*
* Author:  Léopold Bernard
* Created: 17/08/2024 18:12:16
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
#define MAX 101

ll solve(int n, int k, int d) {
    vector<vll> cnt(MAX, vll(MAX, 0LL));
    for (int j=1; j<MAX; ++j) cnt[0][j] = 1;
    for (int i=1; i<MAX; ++i) {
        cnt[i][1] = 1LL;
        for (int j=2; j<MAX; ++j) {
            cnt[i][j] = 0LL;
            for (int l=1; l<=min(i, j); ++l) {
                cnt[i][j] =(cnt[i][j] + cnt[i-l][j]) % MOD;
            }
        }
    }
    // for (int i=0; i<=n; ++i) {
    //     for (int j=0; j<=n; ++j) cout << cnt[i][j] << " ";
    //     cout << nl;
    // }
    // cout << cnt[n][k] << nl;
    // cout << cnt[n][d-1] << nl;
    return (cnt[n][k] - cnt[n][d-1] + MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, d; cin >> n >> k >> d;
    cout << solve(n, k, d) << nl;
	return 0;
}
