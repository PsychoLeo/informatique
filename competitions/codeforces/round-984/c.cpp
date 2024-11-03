/*
* Author:  Léopold Bernard
* Created: 02/11/2024 16:04:33
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

set<int> pos;
string s;

bool isValid(int i) {
	return (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0');
}


void init() {
	for (int i=0; i<sz(s)-3; ++i) {
		if (isValid(i)) pos.emplace(i);
	}
}

void print() {
	for (int x: pos) cout << x << ' ';
	cout << nl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		pos.clear();
		init();
		int q; cin >> q;
		while (q--) {
			int i, v; cin >> i >> v;
			--i;
			s[i] = (v+'0');
			for (int j=max(0, i-3); j<min(i+1, sz(s)-3); ++j) {
				if (isValid(j)) pos.emplace(j);
				if (!isValid(j) && pos.find(j) != pos.end()) pos.erase(j);
			}
			// print();
			cout << (pos.empty() ? "NO" : "YES") << nl;
		}
	}
	return 0;
}
