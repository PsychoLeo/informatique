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
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 

struct UF {
    int n;
    vi leader;
    vi rank;

    void init(int m) {
        n = m;
        rep(i, 0, n) {
            leader.push_back(i);
            rank.push_back(1);
        }
    }

    void _union(int a, int b) {
        a = find(a);
        b = find(b);
        if (rank[a] > rank[b]) {
            leader[b] = a;
            rank[b] += rank[a];
        }
        else {
            leader[a] = b;
            rank[a] += b;
        }
    }

    int find(int a) {
        if (leader[a] == a) return a;
        leader[a] = find(leader[a]);
        return leader[a];
    }

};

int solve(int n, vi &p) {
    UF uf;
    uf.init(n);
    vb vis(n, false);
    for (int i=0; i<n; ++i) {
        
    }
    int currMax = p[0], max_ind = 0;
    rep(i, 0, n) {
        if (p[i] < currMax) {
            uf._union(i, max_ind);
        }
        else {
            currMax = p[i];
            max_ind = i;
        }
    }
    unordered_set<int> leaders;
    rep(i, 0,  n) {
        leaders.emplace(uf.find(i));
    }
    return leaders.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi p(n); rep(i, 0, n) {
            int x; cin >> x; p[i] = x-1;
        } 
        cout << solve(n, p) << "\n";
    }
	return 0;
}
