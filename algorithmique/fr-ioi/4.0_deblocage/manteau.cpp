/*
* Author:  Léopold Bernard
* Created: 29/10/2024 17:22:30
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

int n;
vector<pii> v;
// map<pii, int> m;

bool comp(pii p1, pii p2) {
    if (p1.fi < p2.fi) return true;
    else if (p1.fi > p2.fi) return false;
    return (p1.se > p2.se);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    v.resize(n);
    int ans = 0;
    for (pii &p : v) cin >> p.fi >> p.se;
    for (int i=0; i<n; ++i) {
        int c = 0;
        for (int j=0; j<n; ++j) {
            if (v[i].fi <= v[j].fi && v[j].se <= v[i].se) ++c;
        }
        ans = max(ans, c-1);
    }
    cout << ans << nl;
	return 0;
}
