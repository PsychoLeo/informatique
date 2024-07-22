/*
* Author:  Léopold Bernard
* Created: 22/07/2024 10:50:54
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

#define MOD 1000000007


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int d, m; cin >> d >> m;
    unordered_map<string, string> equiv;
    rep(i, 0, d) {
        string s; cin >> s;
        if (sz(s) <= 3) equiv[s] = s;
        else {
            int l = sz(s);
            string str = s.substr(1, l-2);
            sort(all(str));
            string t = s[0] + str + s[l-1];
            equiv[t] = s;
        }
    }
    rep(i, 0, m) {
        if (i > 0 && (i % 10 == 0)) cout << "\n";
        string s; cin >> s;
        if (sz(s) <= 3) cout << equiv[s] << " ";
        else {
            int l = sz(s);
            string str = s.substr(1, l-2);
            sort(all(str));
            string t = s[0] + str + s[l-1];
            cout << equiv[t] << " ";
        }
    }
    cout << endl;
	return 0;
}
