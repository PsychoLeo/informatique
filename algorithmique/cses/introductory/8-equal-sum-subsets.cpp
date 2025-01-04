/*
* Author:  Léopold Bernard
* Created: 18/10/2024 17:25:34
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
    if (n % 4 == 1 || n%4 == 2) cout << "NO" << nl;
    else {
        ll obj = n*(n+1)/4;
        vll g1, g;
        for (int i=1; i<=n; ++i) g.pb(i);
        ll s = 0;
        ll chosen = 0;
        while (s + g.back() <= obj) {
            s += g.back();
            g1.pb(g.back());
            g.pop_back();
        }
        if (obj-s > 0) {
            chosen = obj-s;
            g1.pb(chosen);
        }
        cout << "YES" << nl;
        cout << sz(g1) << nl;
        for (int x: g1) cout << x << ' ';
        cout << nl;
        cout << sz(g) - (chosen > 0) << nl;
        for (int a: g) if (a != chosen) cout << a << ' ';
        cout << nl;
    }
	return 0;
}
