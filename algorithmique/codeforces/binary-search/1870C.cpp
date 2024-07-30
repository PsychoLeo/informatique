/*
* Author:  Léopold Bernard
* Created: 29/07/2024 23:53:49
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
#define INF 

int bisect_left(int x, int lo, int hi, vi &maxi) {
    // we want the lowest index j1 such that 
    if (maxi[hi] < x) return hi;
    if (hi-lo <= 1) {
        if (maxi[lo] >= x) return lo;
        return hi;
    }
    int mid = (lo + hi)/2;
    if (maxi[mid] >= x) return bisect_left(x, lo, mid, maxi);
    else return bisect_left(x, mid+1, hi, maxi);
}

int bisect_right(int x, int lo, int hi, vi &maxi) {
    if (maxi[lo] < x) return lo;
    if (hi-lo<=1)  {
        if (maxi[hi] >= x) return hi;
        return lo;
    }
    int mid = (lo + hi)/2;
    if (maxi[mid] >= x) return bisect_right(x, mid, hi, maxi);
    else return bisect_right(x, lo, mid-1, maxi);
}

vi solve(int n, int k, vi &a) {
    vi sizes(k, 0);
    vi curr_max(n), curr_max_inv(n);
    for (int i=0, mx = a[0]; i<n; ++i) {
        chmax(mx, a[i]);
        curr_max[i] = mx;
    }
    for (int i=n-1, mx = a[n-1]; i>=0; --i) {
        chmax(mx, a[i]);
        curr_max_inv[i] = mx;
    }
    // for (int i=0; i<n; ++i) cout << curr_max[i] << " ";
    // cout << nl;
    // for (int i=0; i<n; ++i) cout << curr_max_inv[i] << " ";
    // cout << nl;
    // binary search to find indexes as far as possible and superior to current element
    for (int i=0; i<n; ++i) {
        int x = a[i];
        int j1 = bisect_left(x, 0, i, curr_max);
        int j2 = bisect_right(x, i, n-1, curr_max_inv);
        debug(i); debug(x); debug(j1); debug(j2);
        sizes[x-1] = 2 * (j2 - j1 + 1);
    }
    return sizes;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, k; cin >> n >> k;
        vi a(n); rep(i, 0, n) cin >> a[i];
        for (int s: solve(n, k, a)) cout << s << " ";
        cout << nl;
	}
	return 0;
}
