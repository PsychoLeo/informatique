/*
* Author:  Léopold Bernard
* Created: 19/07/2024 08:46:46
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
#define debug(x) cout << #x << "=" << x << "\n";
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 

struct Point {
    ll x, y, id;
};

vector<Point> possibleMoves(ll n, Point p) {
    vector<Point> r;
    for (pll d : {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)}) {
        if ((0 <= p.y+d.fi) && (p.y+d.fi < n) && 
        (0 <= p.x+d.se) && (p.x+d.se < n)) {
            Point newp = {p.x+d.se, p.y+d.fi, p.id};
            r.pb(newp);
        }
    }
    return r;
}

ll solve(ll n, vector<Point> pt) {
    vector<vector<pll>> grid(n, vector<pll>(n, mp(-1, -1)));
    ll m = sz(pt);
    vll zonesz(m, 0);
    ll t = 0; // number of iterations
    // cout << m << endl;
    while (!pt.empty()) {
        vector<Point> tovis_next;
        while (!pt.empty()) {
            Point p = pt.back();
            pt.pop_back();
            if (grid[p.y][p.x].fi == -1) {
                zonesz[p.id]++;
                grid[p.y][p.x] = mp(t, p.id);
            }
            else {
                if ((grid[p.y][p.x].fi == t) && (grid[p.y][p.x].se != p.id)) { // il a été visité à ce tour
                    zonesz[grid[p.y][p.x].se]--;
                    grid[p.y][p.x].se = -1;
                }
            }
            for (Point neighb : possibleMoves(n, p)) {
                if ((grid[neighb.y][neighb.x].fi == -1) && (grid[neighb.y][neighb.x].se == -1)) {
                    // cout << "co" << endl;
                    tovis_next.pb(neighb);
                }
            }
        }
        // cout << sz(tovis_next) << endl;
        pt = tovis_next;
        ++t;
    }
    // rep(i, 0, n) {
    //     rep(j, 0, n) cout << grid[i][j].se << " ";
    //     cout << endl;
    // }
    return max(zonesz);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
    vector<Point> pt;
    ll x, y; 
    ll id = 0;
    while (cin >> x) {
        cin >> y; Point p = {x, n-1-y, id}; pt.pb(p);
        ++id;
    }
    // for (Point p : pt) cout << p.x << " " << p.y << endl;
    cout << solve(n, pt) << endl;
	return 0;
}
