#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <bitset>
#include <climits>
#include <complex>
#include <chrono>
#include <random>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fo(i,n) for(int i=0; i<n; i++)

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x) 
#define ss(x) getline(cin, x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(x) cout << x << "\n"

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vb = vector<bool>;

#define isDebug true
#ifdef isDebug
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

int moveLogs(int pos, int n, int m, string& s) {
    // avance le plus possible avec les logs et renvoie la position finale
    // présuppose que l'on commence sur un log
    for (int i=pos+1; i<n; ++i) {
        if (s[i] == 'L') {
            if (pos+m >= i) {
                pos = i;
            }
        }
    }
    if (pos+m>= n) return n;
    return pos;
}

int moveSwim(int pos, int n, int m, int& k, string &s) {
    // part d'une position sur un log et voit jusqu'où on peut aller (prochain log ou n)
    // renvoie -1 si l'on tombe sur un crocodile
    int i = pos+m;
    int tmpk = k;
    for (; i<min(pos+m+tmpk+1, n); ++i) {
        if (s[i] == 'C') return -1;
        else if (s[i] =='L') return i;
        --k; 
        if (k < 0) return -1;
    }
    return i;
}

string solve(int n, int m, int k, string& s) {
    // we can either arrive only through logs, or with logs at the beginning and ending with swimming
    int pos = -1; // furthest we can go with logs only
    while (true) {
        pos = moveLogs(pos, n, m, s);
        if (pos >= n-1) return "YES";
        int tmp = moveSwim(pos, n, m, k, s);
        if (tmp >= n-1) return "YES";
        pos = tmp;
        if (pos == -1) return "NO";
        if (pos >= n-1) return "YES";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        cout << solve(n, m, k, s) << "\n";
    }
    return 0;
}