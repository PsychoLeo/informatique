#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double distance(int xA, int yA, int xB, int yB);

int main() {
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    double minDist = 1e15; // l'infini
    int bestxA=0, bestyA=0, bestxB=0, bestyB=0;
    for (int i=0; i<n; i++) {
        int xA, yA, xB, yB;
        cin >> xA >> yA >> xB >> yB;
        double AB = distance(xA, yA, xB, yB);
        double AB_scalaire_AP = (xB-xA)*(x-xA) + (yB-yA)*(y-yA);
        double distOrientee_AP = (double)AB_scalaire_AP/AB;
        // P est le nom du point de la tour de contrôle
        // A est le nom du premier point du segment de la piste
        // B est le nom du second point du segment de la piste
        // H est le projetté orthogonal de P sur (AB)
        double dist;
        if (distOrientee_AP > AB) {
            dist = distance(x, y, xB, yB);
        }
        else if (distOrientee_AP < 0) {
            dist = distance(x, y, xA, yA);
        }
        else {
            double m = (double)(yB-yA)/(xB-xA);
            double p = yA - m*xA;
            double xH = (double)(x-p*m+m*y)/(1+m*m);
            double yH = m*xH + p;
            dist = sqrt(pow(x-xH, 2) + pow(y-yH, 2));
        }
        if (dist < minDist) {
            minDist = dist;
            bestxA = xA;
            bestyA = yA;
            bestxB = xB;
            bestyB = yB;
        }
    }
    printf("%d %d %d %d\n", bestxA, bestyA, bestxB, bestyB);
    return 0;
}

double distance(int xA, int yA, int xB, int yB) {
    return sqrt(pow(xA-xB, 2) + pow(yA-yB, 2));
}