/*
* Author:  Léopold Bernard
* Created: 05/11/2024 19:52:23
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vi v;
	for (int i=0; i<6; ++i) {
		int x; cin >> x; v.pb(x);
	}
	int ha, hb; cin >> ha >> hb;
	vi l; for (int i=0; i<6; ++i) l.pb(i);
	for (int i=0; i<6; ++i) {
		for (int j=0; j<6; ++j) {
			for (int k=0; k<6; ++k) {
				if (i !=j && j!=k && i!=k) {
					if (v[i]+v[j]+v[k] == ha) {
						vi a = {v[i], v[j], v[k]};
						vi b;
						// cout << v[i] << ' ' << v[j] << ' ' << v[k] << ' ';
						for (int m=0; m<6; ++m) {
							if (m!=i && m!=j && m!=k) b.pb(v[m]);
						}
						sort(all(a)); sort(all(b));
						for (int m=2; m>=0; --m) cout << a[m] << ' ';
						for (int m=2; m>=0; --m) cout << b[m] << ' ';
						cout << nl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
