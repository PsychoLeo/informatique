#include <cstdio>
#include <iostream>

using namespace std;

int binaryExp (int x, int y, int n);

int main() {
    int numSets;
    cin >> numSets;
    for (int i=0; i<numSets; i++) {
        int n, x, y;
        cin >> x >> y >> n;
        cout << binaryExp (x, y, n) << "\n";
    }
}

int binaryExp (int x, int y, int n) {
    // Returns x^y (mod n)
    x %= n;
    // cout << y << "\n";
    int result = 1;
    while (y > 0) {
        if (y&1) {
            result = result*x % n;
        }
        x = (x*x) % n;
        y >>= 1; // divide y by 2
    }
    return result%n;
}