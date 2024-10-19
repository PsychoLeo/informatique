/*
* Author:  Léopold Bernard
* Created: 13/10/2024 15:11:44
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

int l, q, n;
map<int, int> quilles;

void printMap() {
    for (auto it = quilles.begin(); it != quilles.end(); ++it) {
        cout << it->first << " " << it->second << nl;
    }
}

int count(int lo, int hi) {
    int ans = 0;
    map<int, int>::iterator it_left = quilles.lower_bound(lo);
    if (it_left == quilles.end()) return 0;
    map<int, int>::iterator it_right = quilles.upper_bound(hi);
    if (it_right == quilles.begin()) return 0;
    for (auto it = it_left; it != it_right; it = quilles.erase(it)) {
        ans += it->second;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> q;
    int x;
    for (int i=0; i<q; ++i) {
        cin >> x;
        if (quilles.find(x) == quilles.end()) quilles[x] = 1;
        else quilles[x]++;
    }
    int ray, b;
    cin >> n;
    for (int i=0; i<n; ++i) {
        // printMap();
        cin >> ray >> b;
        cout << count(b-ray, b+ray) << nl;

    }
	return 0;
}
