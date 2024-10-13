/*
* Author:  Léopold Bernard
* Created: 02/10/2024 13:47:31
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, p; cin >> n >> p;
    vb present(p+5, false);
    int firstabs = 0; // index of first absent
    for (int i=0; i<p; ++i) {
        ll ei; cin >> ei; --ei;
        if (ei < p) {
            present[ei] = true;
            while (present[firstabs]) firstabs++;
        }
        if (firstabs < n) cout << firstabs+1 << nl;
        else cout << -1 << nl;
    }
	return 0;
}
