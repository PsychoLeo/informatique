// Including
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

// STL functions
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second

#define MAX (int)(1e9+5)

// Iteration
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fo(i,n) for(int i=0; i<n; i++)

// Input and output
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x) 
#define ss(x) getline(cin, x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(x) cout << x << "\n"

// Types 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;

// Debugging
#define isDebug true
#ifdef isDebug
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

int n, k, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m;
    unordered_map<string, int> ind;
    for (int i=0; i<n; ++i) {
        string c; cin >> c; ind[c] = i;
        // cout << c << endl;
    }
    vector<int> a(n, 0);
    for(int i=0; i<n; ++i) {
        int x; cin >> x; a[i] = x;
    }
    vector<int> group_min_val (k, MAX);
    vector<int> group(n); // groupe auquel chaque élément appartient
    for(int i=0; i<k; ++i) {
        int group_size; cin >> group_size;
        for (int l=0; l<group_size; ++l) {
            int x; cin >> x; group_min_val[i] = min(group_min_val[i], a[x-1]);
            group[x-1] = i;
        }
    }
    ll c = 0;
    for (int i=0; i<m; ++i) {
        string str; cin >> str; 
        int j = ind[str]; int gp = group[j]; c += group_min_val[gp];
    }
    cout << c << endl;
	return 0;
}
