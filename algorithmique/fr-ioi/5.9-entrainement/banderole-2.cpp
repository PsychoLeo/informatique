/*
* Author:  Léopold Bernard
* Created: 12/10/2024 17:49:39
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

int l, n, h;

int solve() {
    int ans = 0;
    deque<pii> piquets;
    for (int i=0; i<n; ++i) {
        cin >> h;
        while (!piquets.empty() && h > piquets.back().fi) piquets.pop_back();
        while (!piquets.empty() && piquets.front().se < i-l) piquets.pop_front();
        if (!piquets.empty() && piquets.front().fi == h && piquets.front().se == i-l) ans++;
        piquets.push_back(mp(h, i));
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> n;
    cout << solve() << nl;
	return 0;
}
