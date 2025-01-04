/*
* Author:  Léopold Bernard
* Created: 04/12/2024 14:24:06
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

map<int, ll> dp;
// dp[i] = number of distinct paths which end up in i
// dp[i] = SUM(j in pred[i]) dp[j]
map<int, vi> pred;
vi favorable;

void buildDP(int v) {
    ll num_paths = 0;
    if (sz(pred[v]) == 0) num_paths = 1;
    for (int u: pred[v]) {
        if (dp[u] == -1) buildDP(u);
        num_paths += dp[u];
    }
    dp[v] = num_paths;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        dp.clear();
        pred.clear();
        favorable.clear();
        int n; cin >> n;
        for (int i=0; i<n; ++i) {
            int v; cin >> v;
            dp[v] = -1;
            string s; cin >> s;
            if (s == "favourably") favorable.push_back(v);
            else if (s != "catastrophically") {
                int v1 = stoi(s);
                int v2, v3; cin >> v2 >> v3;
                if (pred.find(v1) == pred.end()) pred[v1] = {v}; 
                else pred[v1].push_back(v);
                if (pred.find(v2) == pred.end()) pred[v2] = {v}; 
                else pred[v2].push_back(v);
                if (pred.find(v3) == pred.end()) pred[v3] = {v}; 
                else pred[v3].push_back(v);
            }
        }
        ll ans = 0;
        for (int v: favorable) {
            buildDP(v);
            ans += dp[v];
        }
        cout << ans << nl;
	}
	return 0;
}
