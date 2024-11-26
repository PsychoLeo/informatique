/*
* Author:  Léopold Bernard
* Created: 25/11/2024 22:00:47
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

#define MOD 1000000007
#define INF (int)1e9

int n, q;
vvi mn;
int T;

int msb(int x) {
    return 31-__builtin_clz(x);
}

void print() {
    for (vi v: mn) {
        for (int x: v) cout << x << ' ';
        cout << nl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    T = (int) log2(n) + 1;
    mn.resize(n, vi(T));
    for (int i=0; i<n; ++i) cin >> mn[i][0];
    for (int p=1; p<T; ++p) {
        for (int i=0; i<n; ++i) {
            if (i+(1<<(p-1)) < n) mn[i][p] = min(mn[i][p-1], mn[i+(1<<(p-1))][p-1]);
            else mn[i][p] = mn[i][p-1];
        }
    }
    // print();
    while (q--) {
        int a, b; cin >> a >> b; --a; --b;
        if (a == b) cout << mn[a][0] << nl;
        else {
            int p = msb(b-a);
            cout << min(mn[a][p], mn[b-(1<<p)+1][p]) << nl;
        }
    }
	return 0;
}
