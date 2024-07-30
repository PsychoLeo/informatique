/*
* Author:  Léopold Bernard
* Created: 29/07/2024 14:28:52
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

ll solve(vector<string> &a) {
    vvi count(6, vi(50, 0));
    for (string s: a) {
        int somme = 0;
        for (char c: s) {
            somme += (c-'0');
        }
        count[sz(s)][somme]++;
    }
    ll c = 0;
    vvi corresp = {{}, {1}, {2}, {1, 3}, {2, 4}, {1, 3, 5}};
    for (string s: a) {
        int m = sz(s);
        int somme_mot = 0;
        for (char ch: s) somme_mot += (ch-'0');
        int d = 0;
        for (int len: corresp[m]) {
            // on cherche le nombre de prefixes ou suffixes de taille len
            int somme = 0;
            int mid = (m+len)/2;
            for (int i=0; i<mid; ++i) somme += (s[i]-'0');
            if (somme > somme_mot-somme) d += count[len][2*somme-somme_mot];
            if (m != len) {
                somme = 0;
                for (int i=0; i<mid; ++i) somme += (s[m-1-i]-'0');
                if (somme > somme_mot - somme) d += count[len][2*somme-somme_mot];
            }
        }
        //debug(s);
        // debug(d);
        c += d;
    }
    return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
    vector<string> a(n); rep(i, 0, n) cin >> a[i];
    cout << solve(a) << nl;
	return 0;
}
