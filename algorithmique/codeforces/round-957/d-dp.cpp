#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <bitset>
#include <climits>
#include <complex>
#include <chrono>
#include <random>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fo(i,n) for(int i=0; i<n; i++)

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x) 
#define ss(x) getline(cin, x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(x) cout << x << "\n"

#define INF (int)1e9

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vb = vector<bool>;

#define isDebug true
#ifdef isDebug
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

string solve(int n, int m, int k, string& s) {
    // we can either arrive only through logs, or with logs at the beginning and ending with swimming
    int dp[n+2]; // 0 est la rive de départ, n+1 celle d'arrivée
    s = 'L'+s+'L';
    for (int i=0; i<n+2; ++i) dp[i] = 0;
    for (int i=n; i>=0; --i) {
        // debug(s[i]);
        if (s[i] == 'L') {
            int mini = INF;
            for (int j=i+1; j<min(n+2, i+m+1); ++j) {
                mini = min(mini, dp[j]);
            }
            dp[i] = mini;
        }
        else if (s[i] == 'C') dp[i] = INF;
        else dp[i] = dp[i+1]+1;
    }
    // for (int x:dp ) cout << x << " ";
    string r = (dp[0] <= k) ? "YES" : "NO";
    return r;


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        cout << solve(n, m, k, s) << "\n";
    }
    return 0;
}