/*
* Author:  Léopold Bernard
* Created: 13/10/2024 13:57:01
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
vector<pii> t;

int solve() {
    int ans = 0;
    int lastUsed = INF;
    for (int i=0; i<n; ++i) {
        pii pr = t[i];
        int l = pr.fi, p = pr.se;
        if (lastUsed-p >= 0) {
            ans++; lastUsed = min(l-p, lastUsed-2*p);
        }
    }
    return ans;
}

bool cmp(pii pair1, pii pair2) {
    // returns true iff p1 < p2
    int l1 = pair1.fi, p1 = pair1.se;
    int l2 = pair2.fi, p2 = pair2.se;
    if (l1-p1 > l2-p2) return true;
    else if (l1-p1 == l2-p2) return (p1 < p2);
    return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    int l, p;
    for (int i=0; i<n; ++i) {
        cin >> l >> p;
        t.pb(mp(l, p));
    }
    sort(all(t), cmp);
    // for (pii pr: t) cout << pr.fi << " " << pr.se << nl;
    cout << solve() << nl;
	return 0;
}
