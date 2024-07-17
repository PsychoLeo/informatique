#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int height, width;
    cin >> height >> width;
    char grid[height][width];
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }
}
