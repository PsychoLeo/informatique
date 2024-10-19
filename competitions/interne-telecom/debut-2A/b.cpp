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

#define INF 1e9

int t, a, b;
int x, y, z;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int closest(int m) {
    if (m < 0) return -INF;
    int mincongr = b;
    for (int u=0; a*u<=m; ++u) {
        mincongr = min(mincongr, (m-a*u)%b);
        if (mincongr == 0) return m;
    }
    return m-mincongr;
}

int solve() {
    int v1 = closest(t);
    int v2 = x + closest(t-x);
    int v3 = y + closest(t-y);
    int v4 = z + closest(t-z);
    return max(v1, max(v2, max(v3, v4)));
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t >> a >> b;
    x = a/2, y = b/2, z = (a+b)/2;
    if (a+b > t) z = INF;
    cout << solve() << nl;
}