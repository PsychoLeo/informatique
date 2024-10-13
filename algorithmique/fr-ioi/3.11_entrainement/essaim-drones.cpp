/*
* Author:  Léopold Bernard
* Created: 11/10/2024 16:51:10
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

int l, c;
vector<pii> im1, im2;
vvi transl;

vector<pii> solve() {
    for (pii p1: im1) {
        for (pii p2: im2) {
            transl[p1.fi-p2.fi+l][p1.se-p2.se+c]++;
        }
    }
    int max = 0;
    pii translation_opti = mp(0, 0);
    for (int i=0; i<2*l; ++i) {
        for (int j=0; j<2*c; ++j) {
            if (transl[i][j] > max) {
                max = transl[i][j];
                translation_opti = mp(i, j);
            }
        }
    }
    vector<pii> ans;
    for (pii p1 : im1) {
        for (pii p2: im2) {
            if (mp(p1.fi-p2.fi+l, p1.se-p2.se+c) == translation_opti) {
                ans.pb(p2);
            }
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> c;
    transl.assign(3*l, vi(3*c, 0));
    // O(U*U + L*C)
    for (int i=0; i<l; ++i) {
        for (int j=0; j<c; ++j) {
            int b; cin >> b; 
            if (b == 1) im1.pb(mp(i,j));
        }
    }
    for (int i=0; i<l; ++i) {
        for (int j=0; j<c; ++j) {
            int b; cin >> b; 
            if (b == 1) im2.pb(mp(i, j));
        }
    }
    vector<pii> ans = solve();
    cout << ans.size() << nl;
    for (pii p : ans) {
        cout << p.fi+1 << " " << p.se+1 << nl;
    }
	return 0;
}
