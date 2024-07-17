#include <stdio.h>
#include <vector>

using namespace std;

// BFS algorithm
bool canExit(vector<vector<int>> arr) {
    vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int width = arr[0].size(), height = arr.size();
	bool visited[height][width];
    vector<pair<int, int>> toVisit;
    toVisit.push_back(make_pair(0, 0));
    while (!toVisit.empty()) {
        pair<int, int> p = toVisit.back();
        toVisit.pop_back();
        int x = p.first, y = p.second;
        if (y == height-1 && x == width-1) {
            return true;
        }
        arr[y][x] = 1; // visited position
        for (vector<int> v: moves) {
            int dx = v[0], dy = v[1];
            if (arr[y+dy][x+dx] == 0) {
                toVisit.push_back(make_pair(x+dx, y+dy));
            }
        }
    }
    return false;
}