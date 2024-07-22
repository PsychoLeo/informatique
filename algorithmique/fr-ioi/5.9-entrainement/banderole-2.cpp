/*
* Author:  Léopold Bernard
* Created: 22/07/2024 14:27:27
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
#define debug(x) cout << #x << "=" << x << "\n";
#else
#define debug(x)
#endif

#define INF 20000000


int solve(int l, int n, vi &h) {
    vi next_sup(n, n); // prochain indice avec un élément strictement supérieur
    h.pb(INF);
    vector<pii> queue;
    for (int i=0; i<n;) {
        int j = i;
        while (j < n && h[j+1] <= h[j]) { // tant que c'est décroissant
            queue.pb(mp(j, h[j]));
            ++j;
        }
        queue.pb(mp(j, h[j]));
        while (!queue.empty() && queue.back().se < h[j+1]) {
            pii p = queue.back();
            queue.pop_back();
            next_sup[p.fi] = j+1;
        }
        i = j+1;
    }
    // rep(i, 0, n) cout << next_sup[i] << " ";
    int c = 0;
    for (int i=0; i+l<n; ++i) {
        if (h[i] == h[i+l] && next_sup[i] > i+l) {
            ++c;
        }
    }
    return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l, n; cin >> l >> n;
    vi h(n); rep(i, 0, n) cin >> h[i];
    cout << solve(l, n, h) << endl;
	return 0;
}
