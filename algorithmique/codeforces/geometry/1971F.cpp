/*
* Author:  Léopold Bernard
* Created: 10/08/2024 19:51:40
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
#define INF 



ll solve(ll r) {
    set<pll> vis;
    vector<pii> moves = {mp(1, 0), mp(0, -1), mp(1, -1)};
    ll ans = 0;
    deque<pll> tovis = {mp(0, r)};
    while (!tovis.empty()) {
        pll p = tovis.front();
        tovis.pop_front();
        if (p.fi == r && p.se == 0) break;
        if (vis.find(p) == vis.end()) {
            vis.emplace(p);
            ll x = p.fi, y = p.se;
            ll dist = x*x+y*y;
            if (r*r <= dist && dist <= r*r+2*r) {
                ans++;
                for (pii d : moves) {
                    tovis.pb(mp(p.fi+d.fi, p.se+d.se));
                }
            }
        }
    }
    return 4*ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        ll r; cin >> r;
        cout << solve(r) << nl;
	}
	return 0;
}
