#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int x, y;
    cin >> x >> y;
    int n; cin >> n;
    ll minDist = (ll)1e12;
    int minX, minY;
    for (int i=0; i<n; i++) {
        int X, Y;
        cin >> X >> Y;
        if (sqrt(pow(X-x, 2)+pow(Y-y, 2)) < minDist) {
            minDist = sqrt(pow(X-x, 2)+pow(Y-y, 2));
            minX = X;
            minY = Y;
        }
    }
    cout << minX << " " << minY << "\n";
}