#include <iostream>
#include <vector>

using namespace std;

int connectedComponents (int height, int width, vector<vector<char>> &grid);

int main() {
	int height, width;
    cin >> height >> width;
    vector<vector<char>> grid;
    for (int i=0; i<height; i++) {
        vector<char> v;
        for (int j=0; j<width; j++) {
            char c; cin >> c;
            v.push_back(c);
        }
        grid.push_back(v);
    }
    int nbConnected = connectedComponents(height, width, grid);
    cout << nbConnected << "\n";
}

void DFS (int height, int width, int x, int y, vector<vector<char>> &grid) {
    vector<pair<int, int>> toVisit; // (x, y) coordinates
    toVisit.push_back(make_pair(x, y));
    while (!toVisit.empty()) {
        int x = toVisit.back().first;
        int y = toVisit.back().second;
        toVisit.pop_back();
        grid[y][x] = '#';
        for (int X: {x-1, x+1}) {
            if (0 <= X && X < width && grid[y][X] == '.') {
                toVisit.push_back(make_pair(X, y));
            }
        }
        for (int Y:{y-1, y+1}) {
            if (0 <= Y && Y < height && grid[Y][x] == '.') {
                toVisit.push_back(make_pair(x, Y));
            }
        }
    }
}

int connectedComponents (int height, int width, vector<vector<char>> &grid) {
    int r = 0;
    for (int y=0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == '.') {
                r++; // counting a new connected Component
                DFS(height, width, x, y, grid); // marking the past places
            }
        }
    }
    return r;
}