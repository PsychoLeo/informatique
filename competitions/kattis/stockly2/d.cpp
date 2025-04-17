/*
* Author:  Léopold Bernard
* Created: 25/03/2025 20:32:50
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

#define MOD 199933LL
#define INF (int)1e9

struct UF {
    ll n;
    vll rank, repr;

    void init(ll nn) {
        n = nn;
        rank.resize(n, 1);
        for (int i=0; i<n; ++i) repr.pb(i);
    }

    ll find(ll x) {
        if (x == repr[x]) return x;
        return repr[x] = find(repr[x]);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        rank[b] += rank[a];
        repr[a] = b;
        return true;
    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, r, k, x0, a, b; cin >> n >> r >> k >> x0 >> a >> b;
    vll x(r+1), o(r+1);
    x[0] = x0;
    vll cnt(n, 0);
    bool of = false;
    UF uf; uf.init(n);
    ll ans = 0;
    for (int i=1; i<=r; ++i) {
        x[i] = (a*x[i-1]+b) % n; // xi
        o[i] = uf.find(x[i]);
        if (o[i] == 0 && cnt[0] >= k) {
            cout << "OVERFLOW" << nl;
            of = true;
            break;
        }
        // debug(o[i]);
        ans = (53*ans + o[i]) % MOD;
        // debug(ans);
        cnt[o[i]]++;
        if (cnt[o[i]] >= k) {
            if (o[i]) uf.unite(o[i], o[i]-1);
        }
    }
    if (!of) cout << ans << nl;
	return 0;
}
