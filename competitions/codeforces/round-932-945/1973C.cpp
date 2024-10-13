/*
* Author:  Léopold Bernard
* Created: 25/09/2024 13:53:21
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

vi solve(int n, vi &p) {
    int m = n/2;
    vi l1, l2;
    vi index(n);
    for (int i=0; i<n; ++i) {
        p[i]--;
        index[p[i]] = i;
    }
    int l2containsN = 0;
    for (int i=0; i<n; ++i) {
        if (p[i] == n-1) l2containsN = (i%2);
        if (i % 2) l2.push_back(p[i]);
        else l1.push_back(p[i]);
    }
    // which one contains n ?
    vi ans(n);
    sort(all(l1)); sort(all(l2));
    if (l2containsN) {
        for (int i=0; i<m; ++i) {
            ans[index[l1[m-1-i]]] = i;
            ans[index[l2[i]]] = n-1-i;
        }
    }
    else {
        for (int i=0; i<m; ++i) {
            ans[index[l2[m-1-i]]] = i;
            ans[index[l1[i]]] = n-1-i;
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        vi p(n); for (int &x: p) cin >> x;
        for (int x: solve(n, p)) cout << x+1 << " ";
        cout << nl;
	}
	return 0;
}
