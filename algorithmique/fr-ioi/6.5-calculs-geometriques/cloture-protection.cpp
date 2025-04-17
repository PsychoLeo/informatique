/*
* Author:  Léopold Bernard
* Created: 15/04/2025 10:17:48
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

typedef complex<ll> vec;

int a, l;
vector<vec> pts;

int turn(vec A, vec B) {
    ll z = (conj(A) * B).imag();
    if (z > 0) return 1;
    else if (z < 0) return -1;
    return 0;
}

bool intersects(vec A, vec B, vec C, vec D) {
    return turn(B-A, C-B) != turn(B-A, D-B) && turn(D-C, A-D) != turn(D-C, B-D);
}

bool isin(vec p) {
    // using ray casting algorithm
    vec ray(1e9, 3);
    int nbinter = 0;
    for (int i=0; i<a; ++i) {
        if (intersects(p, ray, pts[i], pts[(i+1)%a])) nbinter++;
    }
    return (nbinter % 2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a;
    for (int i=0; i<a; ++i) {
        ll x, y; cin >> x >> y;
        pts.pb(vec(x, y));
    }
    cin >> l;
    for (int i=0; i<l; ++i) {
        ll x, y;cin >> x >> y;
        vec p(x, y);
        cout << isin(p) << nl;
    }
	return 0;
}
