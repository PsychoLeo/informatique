/*
* Author:  Léopold Bernard
* Created: 22/07/2024 16:29:36
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
#define debug(x) cout << #x << "=" << x << "\n";
#else
#define debug(x)
#endif

#define INF 1000000

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int g, l, n; cin >> g >> l >> n;
    vi a(g);
    for (int i=0; i<g; ++i) {
        int x = 0;
        for (int j=0; j<l; ++j) {
            bool b; cin >> b;
            x += (b << (l-1-j));
        }
        a[i] = x;
        // cout << x << endl;
    }
    vi v;
    int y = 0;
    for (int i=0; i<l; ++i) {
        bool b; cin >> b;
        y += (b << (l-1-i));
    }
    v.pb(y);
    for (int i=l; i<n; ++i) {
        bool b; cin >> b;
        int delta = (y >= (1<<(l-1))) ? y-(1<<(l-1)) : y;
        y = (delta << 1) + b;
        v.pb(y);
    }
    for (int x: a) {
        int c = INF;
        for (int vi: v) {
            c = min(c, __builtin_popcount(x ^ vi));
        }
        cout << c << endl;
    }


    // algo en O(NG) ~ 10^7 opérations avec conversion des chaînes en entiers sur 32 bits
	return 0;
}
