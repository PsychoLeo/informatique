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

const int MOD = 1000000007;
const ll INF = 1e18; 
const int MAX = 2e5+5;

vi next_diff(MAX, MAX);

int nextDifferent(int n, int i, vi &a) {
    if (i >= n-1) {
        next_diff[i] = n;
    }
    else if (next_diff[i] != MAX);
    else if (a[i] == a[i+1]) {
        next_diff[i] = nextDifferent(n, i+1, a);
    }
    else {
        next_diff[i] = i+1;
    }
    return next_diff[i];
}

pii solve(int l, int r) {
    if (next_diff[l] <= r) {
        return mp(l, next_diff[l]);
    }
    return mp(-2, -2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n); for (int i=0; i<n; ++i) {
            cin >> a[i]; next_diff[i] = MAX;
        }
        rep(i, 0, n) nextDifferent(n, i, a);
        // rep(i, 0, n) cout << next_diff[i] << " ";
        //cout << endl;
        int q; cin >> q; 
        rep(i, 0, q) {
            int l, r; cin >> l >> r;
            l--; r--;
            pii p = solve(l, r);
            cout << p.fi+1 << " " << p.se+1 << "\n";
        }
        cout << "\n";
    }
	return 0;
}
