/*
* Author:  Léopold Bernard
* Created: 21/07/2024 15:09:30
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
#define INF 1000000000

struct Point {
	int x, y;
	Point (int x, int y) : x(x), y(y) {}
	bool operator <(const Point & o) const {
		return x * o.y >= o.x * y;
	}
};

bool isCounterClockwise(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) >= (p2.y - p1.y) * (p3.x - p1.x);
}

vector<Point> findConvexHull(int n, vector<Point> pts) {
	vector<Point> convex_hull = {Point(0, 0), Point(n-1, 0)};
	// sort(all(pts));
	rep(i, 0, n) {
		convex_hull.push_back(pts[n-1-i]);
		int m = sz(convex_hull);
		while (m > 2 && !isCounterClockwise(convex_hull[m-3], convex_hull[m-2], convex_hull[m-1])) {
			Point p = convex_hull[m-1];
			// debug(p.y);
			convex_hull.pop_back();
			convex_hull.pop_back();
			convex_hull.push_back(p);
			--m;
		}
	}
	return convex_hull;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vi h(n);
	rep(i, 0, n) cin >> h[i];
	vector<Point> pts;
	rep(i, 0, n) pts.push_back(Point(i, h[i]));
	vector<Point> convex_hull = findConvexHull(n, pts);
	vector<int> cvx;
	for (Point p : convex_hull) cvx.pb(p.x);
	sort(all(cvx));
	int m = sz(cvx);
	for (int i=0; i<m;) {
		int v = cvx[i]; cout << v+1 << " ";
		int j= i+1;
		while (j < m && cvx[j] == v) ++j;
		i = j;
	}
	cout << endl;
	return 0;
}
