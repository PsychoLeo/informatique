/*
* Author:  Léopold Bernard
* Created: 02/08/2024 01:28:03
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
#include <iomanip>

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

ld solve(int x, int pos) {
    int cnt = 0;
    for (int mask=0; mask<(1<<x); ++mask) {
        int v = 0;
        for (int i=0; i<x; ++i) {
            v += (mask & (1<<i)) ? 1:-1;
        }
        if (v == pos) ++cnt;
    }
    ld ans = (ld)cnt/(ld)pow(2, x); 
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b;
    int pos = 0;
    for (int i=0; i<sz(a); ++i) {
        pos += (a[i] == '+') ? 1:-1;
    }
    int x = 0;
    for (int i=0; i<sz(b); ++i) {
        if (b[i] == '?') x++;
        else (pos += (b[i] == '+') ? -1:1);
    }
    // we now have to find the probability of moving from 0 to pos using x moves
    // debug(x); debug(pos);
    cout << fixed << setprecision(12);
    cout << solve(x, pos) << endl;
    // x deplacement parmi lesquels abs(pos)
	return 0;
}
