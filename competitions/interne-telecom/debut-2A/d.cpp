#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define nl "\n"

#define all(c) (c).begin(), (c).end()

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << nl
#else
#define debug(x)
#endif

int n;
vector<pll> p;

ll dist(pll p1, pll p2) {
    return abs(p1.fi-p2.fi) + abs(p1.se-p2.se);
}

void solve() {
    ll totalSum = 0;
    ll ans = 1e18;
    for (int i=0; i<n-1; ++i) {
        ll d = dist(p[i], p[i+1]);
        totalSum += d;
    }
    for (int i=1; i<n-1; ++i) {
        pll p1 = p[i-1], p2 = p[i], p3 = p[i+1];
        ans = min(ans, totalSum - dist(p1, p2) -dist(p2, p3) + dist(p1, p3));
    }
    cout << ans << nl;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        ll x, y; cin >> x >> y;
        p.pb(mp(x, y));
    }
    solve();
}