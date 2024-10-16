/*
* Author:  Léopold Bernard
* Created: 25/07/2024 14:53:35
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

#define nl "\n"

#define MOD 1000000007
#define INF 1e9

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
    vector<pair<string, int>> rounds;
    map<string, int> sc;
    for (int i=0; i<n; ++i) {
        string person; int score; cin >> person >> score;
        if (sc.find(person) == sc.end()) sc[person] = score;
        else sc[person] += score;
        rounds.pb(mp(person, score));
    }
    int maxsc = -INF;
    vector<string> playersMaxScore;
    for (auto [p, score] : sc) {
        if (score > maxsc) {
            maxsc = score;
            playersMaxScore = {p};
        }
        else if (score == maxsc) playersMaxScore.pb(p);
    }
    if (sz(playersMaxScore) == 1) {
        cout << playersMaxScore[0] << "\n";
        return 0;
    }
    else {
        // cout << "Hello" << nl;
        map<string, int> sc2;
        deque<string> candidates;
        for (auto [pers, score] : rounds) {
            if (sc2.find(pers) == sc2.end()) sc2[pers] = score;
            else sc2[pers] += score;
            if (sc2[pers] >= maxsc) candidates.pb(pers);
        }
        while (1) {
            string p = candidates.front();
            candidates.pop_front();
            if (sc2[p] == maxsc) {
                cout << p << "\n";
                return 0;
            }
        }
    }
	return 0;
}
