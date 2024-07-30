/*
* Author:  Léopold Bernard
* Created: 25/07/2024 12:24:12
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

const string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char isAlph(char c) {
    int x = (c-'A');
    return (0 <= x && x<26);
}

string convert(int x) {
    string t;
    while (x) {
        int i = x % 26;
        if (i == 0) i = 26;
        t.push_back(alph[i-1]);
        x = (x-1)/26;
    }
    reverse(all(t));
    return t;
}

string solve(string& s) {
    int n = sz(s);
    bool b = isAlph(s[1]); 
    // if b, we are in case number 1
    int case_number = b ? 1 : 2;
    // else we have to check if there is another character in the string
    bool found = false;
    if (!b) {
        for (int i=2; i<n; ++i) {
            if (isAlph(s[i])) {
                found = true;
            }
        }
        if (!found) case_number = 1;
    }
    string r;
    if (case_number == 1) {
        r.push_back('R');
        int x = 0;
        int i = 0;
        for (; i<n && isAlph(s[i]); ++i) {
            x = (x * 26) + (s[i]-'A'+1);
        }
        for (; i<n; ++i) r.push_back(s[i]);
        r.push_back('C');
        r += to_string(x);
    }
    else {
        int i = 1;
        for (; i<n && !isAlph(s[i]); ++i);
        string str = s.substr(1, i-1);
        int x = stoi(s.substr(i+1, n-i-1));
        // cout << x << endl;
        r += convert(x);
        r += str;
    }
    return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
    string s;
	rep(i, 0, n) {
        cin >> s; cout << solve(s) << "\n";
    }
	return 0;
}
