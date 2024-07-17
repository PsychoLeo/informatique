#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Global variables :
int width, height;
int nbReq;
vector<int> result;
vector<vector<char>> grid;

// Function to initialize grid
void initVector() {
    for (int i=0; i<height; i++) {
        vector<char> v;
        for (int j=0; j<width; j++) {
            char c;
            cin >> c;
            v.push_back(c);
        }
        grid.push_back(v);
    }
}


// BFS function
void BFS(int initX, int initY, int initDepth=0) {
    deque<vector<int>> pos = {{initX, initY, initDepth}};
    while (!pos.empty()) {
        vector<int> l = pos.front();
        pos.pop_front();
        int x=l[0], y=l[1], depth=l[2];
        if (depth < nbReq) {
            result[depth]++;
            grid[y][x] = '#';
            // cout << x << " " << y << "\n";
            for (int X: {x+1, x-1}) {
                if (0 <= X && X < width && grid[y][X] == '.') {
                    grid[y][X] = '#';
                    pos.push_back({X, y, depth+1});
                }
            }
            for (int Y: {y+1, y-1}) {
                if (0 <= Y && Y < height && grid[Y][x] == '.') { 
                    grid[Y][x] = '#';
                    pos.push_back({x, Y, depth+1});
                }
            }
        }
    }
}

int main() {
    cin >> height >> width;
    initVector(); // initialize grid
    cin >> nbReq;
    for (int i=0; i<nbReq; i++) {
        result.push_back(0);
    }
    grid[height-1][width-2] = '#';
    BFS(width-2, height-2);
    for (int i=0; i<nbReq; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}