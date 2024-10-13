/*
* Author:  Léopold Bernard
* Created: 08/10/2024 11:18:44
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

vi solve(int n, vi &a) {
    set<int> nondup;
    vb islast(n, false);
    for (int i=n-1; i>=0; --i) {
        int x = a[i];
        if (nondup.find(x) == nondup.end()) islast[i] = true;
        nondup.emplace(x);
    }
    for (int b: islast) cout << b << " ";
    cout << nl;
    vi v;
    for (int x: nondup) v.pb(x);
    sort(all(v));
    int m = v.size();
    int mn=0, mx=m-1;
    vi ans;
    set<int> used;
    for (int i=0; i<n;) {
        int j=i;
        while (mn < m && used.find(v[mn]) != used.end()) mn++;
        while (mx >= 0 && used.find(v[mx]) != used.end()) mx--;
        if (i % 2 == 0) {
            // on cherche le max
            if (mx < 0) break;
            while (mx >= 0 && j < n && a[j] < v[mx] && !islast[j]) ++j;
            if (a[j] == v[mx]) mx--;
        }
        else {
            if (mn >= m) break;
            while (mn < m && j < n && a[j] > v[mn] && !islast[j]) ++j;
            if (a[j] == v[mn]) mn++;
        }
        ans.pb(a[j]);
        used.emplace(a[j]);
        i = j+1;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        vi a(n); for (int &x: a) cin >> x;
        vi ans = solve(n, a);
        cout << ans.size() << nl;
        for (int x: ans) cout << x << " ";
        cout << nl;
	}
	return 0;
}
