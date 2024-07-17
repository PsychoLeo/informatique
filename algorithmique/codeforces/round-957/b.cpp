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

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;

#define isDebug true
#ifdef isDebug
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

int solve(int n, int k, vi &a) {
    int m = a[0];
    int maxInd = 0;
    ll c = 0;
    for (int i=0; i<k; ++i) {
        if (a[i] > m) {
            maxInd = i;
            m = a[i];
        }
    }
    for (int i=0; i<k; ++i) {
        if (i != maxInd) c += a[i]-1;
    }
    c += n-m;
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi a(k, 0); 
        for (int i=0; i<k; ++i) {
            cin >> a[i];
        }
        cout << solve(n, k, a) << "\n";
    }
    return 0;
}