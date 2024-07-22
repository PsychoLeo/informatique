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

#define DEBUG true
#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 

int aux(vector<string> &v, int n, int dep, int fin, int j) {
    int S = 0;
    // debug(dep);
    // debug(fin);
    for (int i=dep; i<=fin;) {
        if (j >= sz(v[i])) ++i;
        else {
            char c = v[i][j];
            int ni = i+1;
            while (ni <= fin && v[ni][j] == c) ++ni;
            // cout << i << " " << ni-1 << " " << j+1 << endl;
            S = (S+1+aux(v, n, i, ni-1, j+1));
            i = ni;
        }
    }
    return S;
}

int solve(vector<string> &v) {
    int n = v.size();
    return aux(v, n, 0, n-1, 0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<string> v;
    string line;
    while (getline(cin, line)) {
        v.pb(line);
    }
    sort(all(v));
    cout << solve(v)+1 << endl;
	return 0;
}
