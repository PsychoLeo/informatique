/*
* Author:  Léopold Bernard
* Created: 08/01/2025 13:49:53
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

struct pt {
        long long x, y;
        pt() {}
        pt(long long _x, long long _y) : x(_x), y(_y) {}
        pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
        long long cross(const pt& p) const { return x * p.y - y * p.x; }
        long long cross(const pt& a, const pt& b) const { return (a -
 *this).cross(b - *this); }
 };
 int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }
 bool inter1(long long a, long long b, long long c, long long d) {
        if (a > b)
        swap(a, b);
        if (c > d)
        swap(c, d);
        return max(a, c) <= min(b, d);
}
 bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
        if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
        return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) && sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pt a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
		if (check_inter(a, b, c, d)) cout << "YES"<< nl;
        else cout << "NO" << nl;
	}
	return 0;
}