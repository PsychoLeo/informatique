/*
* Author:  Léopold Bernard
* Created: 11/08/2024 00:06:03
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

string solve(int n, string &s) {
    if (n % 2) return "NO";
    string ans(n, 'R');
    map<char, int> cnt;
    map<char, int> last;
    for (char c: {'N', 'E', 'S', 'W'}) cnt[c] = 0;
    for (int i=0; i<n; ++i) {
        if (cnt[s[i]] % 2) ans[i] = 'H';
        cnt[s[i]]++;
        last[s[i]] = i;
    }
    int som = (cnt['N'] % 2) + (cnt['S'] % 2) + (cnt['E'] % 2)+ (cnt['W'] % 2);
    if (som == 0) return ans;
    if (som == 4) {
        ans[last['N']] = 'H';
        ans[last['S']] = 'H';
        return ans;
    }
    if (som % 2) return "NO";
    if (n == 2) return "NO";
    int som2 = (cnt['N'] % 2) + (cnt['S'] % 2)*2 + (cnt['E'] % 2)*4 + (cnt['W'] % 2)*8;
    return (som2 == 3 || som2 == 12) ? ans : "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n; 
        string s; cin >> s;
        cout << solve(n, s) << nl;
	}
	return 0;
}
