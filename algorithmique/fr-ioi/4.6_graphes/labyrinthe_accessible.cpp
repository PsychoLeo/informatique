#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    for (int i=0; i<h; i++) {
        for (int j=0; j < w; j++) {
            char c; cin >> c;
            grid[i][j] = c;
        }
    }
    vector<pair<int, int>> toVisit; // (x, y) coordinates
    toVisit.push_back(make_pair(0, 1));
    while (!toVisit.empty()) {
        pair<int, int> xypair = toVisit.back();
        toVisit.pop_back();
        int x = xypair.first, y = xypair.second;
        grid[y][x] = '#';
        for (int X: {x-1, x+1}) {
            if (0 <= X < w && grid[y][X] == '.') {
                xypair.first = X;
                xypair.second = y;
                toVisit.push_back(xypair);
            }
        }
        for (int Y:{y-1, y+1}) {
            if (0 <= Y < h && grid[Y][x] == '.') {
                xypair.first = x;
                xypair.second = Y;
                toVisit.push_back(xypair);
            }
        }
    }
    int r = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (grid[i][j] == '.') {
                r++;
            }
        }
    }
    cout << r << "\n";
}