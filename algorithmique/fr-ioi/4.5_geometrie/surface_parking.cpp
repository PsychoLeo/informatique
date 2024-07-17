#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // On pose le triangle ABC
    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    // On utilise la formule : A = b*h/2
    // Or on nous demande le double de l'aire, soit 2*A = b*h
    double m = (double)(yC-yB)/(xC-xB);
    double p = yB - m*xB;
    double xH = (double)(xA+m*yA-m*p)/(1+m*m);
    double yH = m*xH + p;
    double BC = sqrt(pow(xC-xB, 2) + pow(yC-yB, 2));
    double AH = sqrt(pow(xH-xA, 2) + pow(yH-yA, 2));
    double surface = BC*AH;
    cout << surface << endl;
    // int result = surface;
    // cout << result << endl;
}