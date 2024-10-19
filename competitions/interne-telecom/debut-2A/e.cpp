#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define nl "\n"

#define all(c) (c).begin(), (c).end()

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << nl
#else
#define debug(x)
#endif

int n; 
vector<vector<char>> grid;
vvb vis;
vector<pii> moves = {
    mp(-1, 0),
    mp(1, 0),
    mp(0, -1),
    mp(0, 1)
};
vector<pii> comp_info;

#define INF (int)1e9

bool isPossible(int px, int py, int dx, int dy) {
    if (px+dx >= n || px+dx<0 || py+dy>=n || py+dy<0) return false;
    int npx = px+dx, npy = py+dy;
    if (vis[npx][npy]) return false;
    if (grid[npx][npy] == '.') return false;
    return true;
}

int contribution_perim(int x, int y) {
    int contr = 4;
    for (pii p: moves) {
        int dx = p.fi, dy = p.se;
        if (0 <= x+dx && x+dx < n && 0<=y+dy && y+dy<n) {
            if (grid[x+dx][y+dy] == '#') contr--;
        }
    }
    return contr;
}

void dfs(int x, int y) {
    vector<pii> tovis = {mp(x, y)};
    int comparea = 0;
    int comp_perim = 0;
    while (!tovis.empty()) {
        pii pos = tovis.back();
        tovis.pop_back();
        int px = pos.fi, py = pos.se;
        if (!vis[px][py]) {
            comparea++;
            comp_perim += contribution_perim(px, py);
            for (pii p: moves) {
                if (isPossible(px, py, p.fi, p.se)) {
                    tovis.pb(mp(px+p.fi, py+p.se));
                }
            }
        }
        vis[px][py] = true;
    }
    // cout << comparea << " " << comp_perim << nl;
    comp_info.pb(mp(comparea, comp_perim));
}

void solve() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (!vis[i][j] && grid[i][j] == '#') dfs(i, j);
        }
    }
    int maxarea = -INF, minperim = INF;
    for (pii p: comp_info) {
        int ar = p.fi, perim = p.se;
        if (ar > maxarea) {
            maxarea = ar;
            minperim = perim;
        }
        else if (ar == maxarea && perim < minperim) {
            minperim = perim;
        }
    }
    cout << maxarea << " " << minperim << nl;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    grid.assign(n, vector<char>(n));
    vis.assign(n, vb(n, false));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> grid[i][j];
        }
    }
    solve();
}