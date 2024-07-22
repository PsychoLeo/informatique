/*
* Author:  Léopold Bernard
* Created: 22/07/2024 12:01:59
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

#define MOD 1000000007
#define INF 

int solve(int n, vector<pii> v) {
    int c = 1;
    int dist = v[0].se;
    for (int i=1; i<n; ++i) {
        pii p = v[i];
        int L = p.fi - p.se;
        int P = p.se;
        if (L-P >= dist) {
            ++c; dist = dist + 2*P;
        }
    }
    return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
    vector<pii> v;
    rep(i, 0, n) {
        int L, P; cin >> L >> P;
        v.pb(mp(L+P, P));
    }
    sort(all(v));
    cout << solve(n, v) << endl;
	return 0;
}
