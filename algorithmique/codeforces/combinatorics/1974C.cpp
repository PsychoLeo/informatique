/*
* Author:  Léopold Bernard
* Created: 31/07/2024 11:41:55
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

ll computePairTriples(int m, int cdiff, vvi &t) {
    ll r = 0;
    int cmp1 = (cdiff+1)%3, cmp2 = (cdiff+2)%3;
    for (int i=0; i<m;) {
        int j = i+1;
        while (j < m && t[j][cmp1] == t[j-1][cmp1] && t[j][cmp2] == t[j-1][cmp2]) ++j;
        for (int k=i; k<j;) {
            int p = k+1;
            while (p < j && t[p][cdiff] == t[k][cdiff]) ++p;
            r += (p-k) * (j-p);
            k = p;
        }
        i = j;
    }
    return r;
}



ll solve (int m, vvi &t) {
    ll c = 0;
    for (int df: {0, 1, 2}) {
        const int x1 = (df+1)%3, x2 = (df+2)%3, x3 = df;
        sort(all(t), [x1, x2, x3](const vi& a, const vi& b) {
        return mt(a[x1], a[x2], a[x3]) < mt(b[x1], b[x2], b[x3]);});
        // for (int i=0; i<m; ++i) cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << nl;
        c += computePairTriples(m, df, t);
    }
    return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n; vi a(n);
        rep(i, 0, n ) cin>> a[i];
        vvi triples(n-2, vi(3, 0));
        for (int i=0; i<n-2; ++i) {
            triples[i][0] = a[i];
            triples[i][1] = a[i+1];
            triples[i][2] = a[i+2];
        }
        cout << solve(n-2, triples) << nl;
	}
	return 0;
}
