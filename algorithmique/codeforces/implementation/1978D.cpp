/*
* Author:  Léopold Bernard
* Created: 11/08/2024 00:42:04
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
#define INF 

vi solve(int n, int c, vi a) {
    vi ans(n, 0);
    vll prefix(n, 0);
    vi max_sfx(n);
    int curr_max = a[n-1];
    for (int i=n-1; i>=0; --i) {
        chmax(curr_max, a[i]);
        max_sfx[i] = curr_max;
    }
    vi max_pref(n);
    curr_max = a[0];
    ll sum_votes = 1LL * c;
    for (int i=0; i<n; ++i) {
        chmax(curr_max, a[i]);
        max_pref[i] = curr_max;
        sum_votes += 1LL * a[i];
        prefix[i] = sum_votes;
    }
    ans[0] = (a[0] + c < max_sfx[0]);
    for (int i=1; i<n; ++i) {
        if ((a[i] >= max_sfx[0]) && (a[i] > a[0] + c) && (a[i] > max_pref[i-1])) ans[i] = 0;
        else ans[i] = i+(prefix[i] < max_sfx[i]);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, c; cin >> n >> c;
        vi a(n);
        for (int i=0; i<n; ++i) cin >> a[i];
        for (int x: solve(n, c, a)) cout << x << " ";
        cout << nl;
	}
	return 0;
}
