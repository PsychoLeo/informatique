/*
* Author:  Léopold Bernard
* Created: 26/07/2024 16:21:11
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
#define debug(x) cout << #x << "=" << x << "\n";
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 
#define M 26

void solve (int n, int q, string &a, string &b) {
	vvi num_at_index_a(n+1, vi(M, 0));
	vvi num_at_index_b(n+1, vi(M, 0));
	rep(i, 1, n+1) {
		rep(j, 0, M) {
			num_at_index_a[i][j] = num_at_index_a[i-1][j];
			num_at_index_b[i][j] = num_at_index_b[i-1][j];
		}
		num_at_index_a[i][a[i-1]-'a']++;
		num_at_index_b[i][b[i-1]-'a']++;
	}
	rep(i, 0, q) {
		int l, r; cin >> l >> r;
		int delta = 0;
		rep(j, 0, M) {
			int num_charj_a = num_at_index_a[r][j] - num_at_index_a[l-1][j];
			int num_charj_b = num_at_index_b[r][j] - num_at_index_b[l-1][j];
			delta += abs(num_charj_a-num_charj_b);
		}
		cout << delta/2 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		string a, b; cin >> a >> b;
		solve(n, q, a, b);
	}
	return 0;
}