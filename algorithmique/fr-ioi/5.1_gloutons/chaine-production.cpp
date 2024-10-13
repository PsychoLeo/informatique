/*
* Author:  Léopold Bernard
* Created: 12/10/2024 20:06:57
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

int n, ma, mb;
vi a, b;
priority_queue<pii, vector<pii>, greater<pii>> ta, tb; // temps auquel les machines nous rendont les objets

void solve() {
    int t_a = 0, t_b = 0;
    vi times;
    for (int i=0; i<n; ++i) {
        pii pa = ta.top(); ta.pop();
        t_a = pa.fi;
        ta.push(mp(pa.fi+pa.se, pa.se));
        times.pb(t_a);
    }
    cout << t_a << nl;
    for (int i=0; i<n; ++i) {
        pii pb = tb.top(); tb.pop();
        t_b = max(t_b, times[n-1-i] + pb.fi);
        tb.push(mp(pb.fi+pb.se, pb.se));
    }
    cout << t_b << nl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> ma; 
    int x;
    for (int i=0; i<ma; ++i) {
        cin >> x; a.pb(x); ta.push(mp(x, x));
    }
    cin >> mb;
    for (int i=0; i<mb; ++i) {
        cin >> x; b.pb(x); tb.push(mp(x, x));
    }
    solve();
	return 0;
}
