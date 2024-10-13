#include <bits/stdc++.h>
using namespace std;

bool grid[501][501];
bool grid_invert[501][501];

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string row; cin >> row;
        for (int j = 0; j < m; ++j) {
            if (row[j] == 'W') {
                grid[i][j] = false;
                grid_invert[i][j] = true;
            } else {
                grid[i][j] = true;
                grid_invert[i][j] = false;
            }
        }
    }

    bool b1, b2, b3, b4;
    b1 = true;
    b2 = true;
    b3 = true;
    b4 = true;
    bool ib1, ib2, ib3, ib4;
    ib1 = true;
    ib2 = true;
    ib3 = true;
    ib4 = true;
    for (int i = 0; i < n; ++i) {
        b1 = b1 && grid[i][0];
        b2 = b2 && grid[i][m-1];

        ib1 = ib1 && grid_invert[i][0];
        ib2 = ib2 && grid_invert[i][m-1];
    }
    for (int j = 0; j < m; ++j) {
        b3 = b3 && grid[0][j];
        b4 = b4 && grid[n-1][j];

        ib3 = ib3 && grid_invert[0][j];
        ib4 = ib4 && grid_invert[n-1][j];
    }
    if((b1 || b2 || b3 || b4) && (ib1 || ib2 || ib3 || ib4)) {
        cout << "NO" << "\n";
    } else {
         cout << "YES" << "\n";
    }

}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
} 