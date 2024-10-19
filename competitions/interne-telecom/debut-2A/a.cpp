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
deque<vi> cows;

void solve() {
    int groups = 0;
    while (!cows.empty()) {
        vi a = cows.front();
        cows.pop_front();
        int v = a[0], x = a[1], i=a[2];
        while (!cows.empty() && cows.front()[2] < i) {
            cows.pop_front();
        }
        groups++;
    }
    cout << groups << nl;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int x, v;
        cin >> x >> v;
        vector<int> a = {v, x, i};
        cows.pb(a);
    }
    sort(all(cows));
    solve();
}