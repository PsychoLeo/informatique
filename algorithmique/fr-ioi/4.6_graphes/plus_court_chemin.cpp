#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int width, height;
vector<vector<int>> grid;
int NOT_VISITED, VISITED;
void findPath();

// Function to initialize grid
void initGrid() {
    for (int i=0; i<height; i++) {
        vector<int> v;
        for (int j=0; j<width; j++) {
            char c; cin >> c;
            if (c == '.') {
                v.push_back(-1);
            }
            else { // if c == '#'
                v.push_back(-2);
            }
        }
        grid.push_back(v);
    }
}

// BFS function
void BFS() {
    deque<vector<int>> pos = {{width-2, height-1, 0}};
    while (!pos.empty()) {
        vector<int> l = pos.front();
        pos.pop_front();
        int x=l[0], y=l[1], depth=l[2];
        grid[y][x] = depth;
        if (x == 0 && y == 1) {
            cout << depth << "\n";
            findPath();
        }
        for (int X: {x+1, x-1}) {
            if (0 <= X && X < width && grid[y][X] == NOT_VISITED) {
                grid[y][X] = depth+1; // we have visited it
                pos.push_back({X, y, depth+1});
            }
        }
        for (int Y: {y+1, y-1}) {
            if (0 <= Y && Y < height && grid[Y][x] == NOT_VISITED) { 
                grid[Y][x] = depth+1;
                pos.push_back({x, Y, depth+1});
            }
        }
    }
}

void findPath() {
    int x = 0, y=1;
    int depth = grid[y][x];
    map<vector<int>, string> moves = {{{1,0},"E"}, {{0,-1}, "N"}, {{-1,0}, "O"}, {{0,1}, "S"}};
    string result = "";
    int currBestX, currBestY;
    string currBestMove;
    while (grid[y][x] != 0) {
        currBestMove = "Z";
        for (pair<vector<int>, string> l: moves) {
            string move = l.second;
            int dx = l.first[0], dy = l.first[1];
            int X = x+dx, Y = y+dy;
            if (0<=Y && Y<height && 0<=X && x<width && grid[Y][X] == depth-1) {
                if (move < currBestMove) {
                    currBestMove = move;
                    currBestX = X;
                    currBestY = Y;
                }
            }
        }
        depth--;
        x = currBestX;
        y = currBestY;
        result += currBestMove;
    }
    cout << result << endl;
}

int main() {
    NOT_VISITED = -1;
    ios::sync_with_stdio(false);
    cin >> height >> width;
    initGrid(); // initialize grid
    grid[height-1][width-2] = 0;
    BFS();
    // for (int i=0; i<height; i++) {
    //     for (int j=0; j<width; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}