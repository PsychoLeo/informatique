/*
* Author:  Léopold Bernard
* Created: 18/08/2024 13:10:31
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

string solve(int n, string &s) {
    vi pref(n);
    for (int i=0; i<n; ++i) {
        pref[i] = (i ? pref[i-1] : 0) + (s[n-1-i] - '0');
        // debug(pref[i]);
    }
    vi a(n, -1);
    int retenue = 0;
    for (int j=0; j<n; ++j) {
        int v = pref[n-1] - (j ? pref[j-1] : 0) + retenue;
        a[j] = (v % 10);
        // debug(a[j]);
        retenue = v/10;
    }
    string ans = (retenue ? to_string(retenue) : "");
    int dep = n-1;
    if (!retenue) while (!a[dep]) --dep;
    for (int i=dep; i>=0; --i) {
        ans.push_back('0' + a[i]);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << solve(n, s) << nl;
	}
	return 0;
}
