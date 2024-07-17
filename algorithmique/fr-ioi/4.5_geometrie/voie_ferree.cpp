#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int xA, yA, xB, yB;
    cin >> xA >> yA >> xB >> yB;
    int n; cin >> n;
    double m = (double)(yB-yA)/(xB-xA);
    double p = yA-m*xA;
    double maxDist = 0;
    int bestX, bestY;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        double xH = (double)(x-p*m+m*y)/(1+m*m);
        double yH = m*xH + p;
        double dist = sqrt(pow(xH-x, 2) + pow(yH-y, 2));
        if (dist > maxDist) {
            maxDist = dist;
            bestX = x;
            bestY = y;
        }
    }
    cout << bestX << " " << bestY << "\n";
}