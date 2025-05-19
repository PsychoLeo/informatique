/*
* Author:  Léopold Bernard
* Created: 20/04/2025 10:00:12
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

const int INF = 1e9;
int N, M, P;
vector<int> I, V; // taille N-1

static const int priority[3] = { /* d=-1 */ 1,
    /* d= 0 */ 0,
    /* d=+1 */ 2 };

// DP sur [L..R[, start→end
void solve(int L, int R, int start_col, int end_col, vector<int>& out_moves) {
    if (R - L == 0) return;
    if (R - L == 1) {
        // cas base : une ligne, un seul move possible
        int best = -INF, best_d = 0;
        for (int d : {-1,0,1}) {
            int c = start_col + d;
            if (c<0||c>=M) continue;
            int v = V[L] * (c == I[L]);
            if (v > best
             || (v == best && priority[d] < priority[best_d])) {
                best = v;
                best_d = d;
            }
        }
        out_moves.push_back(best_d);
        return;
    }
    int mid = (L + R) >> 1;

    // 1) Forward DP L→mid
    static int dp_fwd[500], dp_fwd_next[500], parent_mid[500];
    fill(dp_fwd, dp_fwd+M, -INF);
    dp_fwd[start_col] = 0;
    for (int i = L; i < mid; ++i) {
        fill(dp_fwd_next, dp_fwd_next+M, -INF);
        for (int j = 0; j < M; ++j) if (dp_fwd[j] > -INF) {
            for (int d : {-1,0,1}) {
                int k = j + d;
                if (k<0||k>=M) continue;
                int val = dp_fwd[j] + (k == I[i] ? V[i] : 0);
                if (val > dp_fwd_next[k]
                 || (val == dp_fwd_next[k] 
                     && priority[d] < priority[parent_mid[k]])) {
                    dp_fwd_next[k] = val;
                    parent_mid[k] = d; // le move qu’on a pris pour arriver à k
                }
            }
        }
        swap(dp_fwd, dp_fwd_next);
    }

    // 2) Backward DP R→mid
    static int dp_bwd[500], dp_bwd_next[500];
    fill(dp_bwd, dp_bwd+M, 0);  // à la ligne R la valeur est 0
    for (int i = R-1; i >= mid; --i) {
        fill(dp_bwd_next, dp_bwd_next+M, -INF);
        for (int j = 0; j < M; ++j) if (dp_bwd[j] > -INF) {
            for (int d : {-1,0,1}) {
                int k = j + d;
                if (k<0||k>=M) continue;
                int val = dp_bwd[j] + (k == I[i] ? V[i] : 0);
                if (val > dp_bwd_next[k]) {
                    dp_bwd_next[k] = val;
                }
            }
        }
        swap(dp_bwd, dp_bwd_next);
    }

    // 3) Choix de la colonne de passage mid (j*)
    int best_tot = -INF, jstar = 0;
    for (int j = 0; j < M; ++j) {
        int tot = dp_fwd[j] + dp_bwd[j];
        if (tot > best_tot
         || (tot == best_tot
             && priority[parent_mid[j]] < priority[parent_mid[jstar]])) {
            best_tot = tot;
            jstar = j;
        }
    }

    // 4) Recurse sur les deux moitiés
    solve(L,   mid, start_col, jstar, out_moves);
    solve(mid, R,   jstar,     end_col,   out_moves);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// --- dans main() :
    cin >> N >> M >> P;
    I.resize(N); V.resize(N);
    I[0] = -1; V[0] = 0;
    for(int i=1; i<N; ++i) {
        int j,v; cin >> j >> v;
        V[i] = v;
        I[i] = j;
    }
    // read N,M,P, I[], V[]
    vector<int> moves;
    solve(0, N-1, P, M-1, moves);
    // moves contient N-1 déplacements
    for (int d : moves) cout << d << ' ';
    cout << nl;
	return 0;
}
