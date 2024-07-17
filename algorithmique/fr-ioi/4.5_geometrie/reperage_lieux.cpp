#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout.precision(10);
    int xA, yA, xB, yB;
    cin >> xA >> yA >> xB >> yB;
    int n; cin >> n;
    double m = (double)(yB-yA)/(xB-xA);
    double p = yA - m*xA;
    double BA = sqrt(pow(xA-xB, 2) + pow(yA-yB, 2));
    // droite d'équation y = mx+p
    // Vecteur directeur de la droite : (-p; m)
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        double xProj = (double)(y*m-p*m+x)/(1+m*m);
        double yProj = m*xProj+p;
        // coordonnées du projetté orthogonal de O sur (d)
        double distToA = sqrt(pow(xProj-xA, 2)+pow(yProj-yA, 2));
        double BH = sqrt(pow(xProj-xB, 2) + pow(yProj-yB, 2));
        int mult = 1;
        if (BH > BA) {
            mult = -1;
        }
        cout << mult*distToA << "\n";
    }
}