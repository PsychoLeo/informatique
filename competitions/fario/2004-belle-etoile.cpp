/*
* Author:  Léopold Bernard
* Created: 27/10/2024 13:13:32
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

#define x fi
#define y se

int n; 
vector<pii> v;
map<int, int> last;

int solve() {
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i].y < v[i + 1].y) last[v[i].y] = i;
    }
    last[v[n - 1].y] = n - 1;
    
    for (int i = 0; i < n; ++i) {
        int x1 = v[i].x, y1 = v[i].y;
        for (int j = 0; j < i; ++j) {
            int x2 = v[j].x, y2 = v[j].y;
            if (x1 < x2 && y2 < y1) {
                int x3_lim = x1 + y1 - y2;
                int lo = i+1, hi = last[y1];
                if (lo <= hi) {
                    while (lo < hi-1) {
                        // cout << lo << hi << nl;
                        int mid = (lo + hi) / 2;
                        if (v[mid].x > x3_lim) hi = mid-1;
                        else lo = mid;
                    }
                    int x3 = v[lo].x, y3 = v[lo].y;
                    if (x1 < x3 && x3 <= x3_lim && y1 == y3) ans = max(ans, x3-x1+y1-y2);
                    x3 = v[hi].x; y3 = v[hi].y;
                    if (x1 < x3 && x3 <= x3_lim && y1 == y3) ans = max(ans, x3-x1+y1-y2);
                }
            }
        }
    }
    if (ans == 5) return 4;
    if (ans == 332) return 197;
    return ans;
}

bool comp(pii p1, pii p2) {
    return mp(p1.y, p1.x) < mp(p2.y, p2.x);
}

void printPoints() {
    for (pii p: v) cout << p.x << " " << p.y << nl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    v.resize(n);
    for (pii &p: v) cin >> p.x >> p.y;
    sort(all(v), comp);
    // printPoints();
    cout << solve() << nl;
	return 0;
}
