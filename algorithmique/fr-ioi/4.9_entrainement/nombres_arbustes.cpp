#include <iostream>

using namespace std;

int main() {
    int height, width;
    int r=0;
    cin >> height >> width;
    for (int i=0; i<height; i++) {
        for (int j = 0; j<width; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                r++;
            }
        }
    }
    cout << r << "\n";
}