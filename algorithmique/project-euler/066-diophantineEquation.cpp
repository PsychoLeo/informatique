#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

// Fonction pour calculer la racine carrée entière
int intSqrt(int D) {
    return static_cast<int>(std::sqrt(D));
}

// Fonction pour trouver la première solution de l'équation de Pell
ll solvePellEquation(int D) {
    ll sqrtD = (ll)intSqrt(D);

    // Vérification si D est un carré parfait
    if (sqrtD * sqrtD == D) {
        return 0;
    }

    ll m = 0;
    ll d = 1;
    ll a = sqrtD;

    ll x0 = 1, x1 = a;
    ll y0 = 0, y1 = 1;

    // Algorithme pour trouver la première solution fondamentale
    while (x1 * x1 - D * y1 * y1 != 1) {
        m = d * a - m;
        d = (D - m * m) / d;
        a = (sqrtD + m) / d;

        ll x2 = a * x1 + x0;
        ll y2 = a * y1 + y0;

        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    return x1;
}

int main() {
    ll maxx = 0;
    int dval = 1;
    for (int D=1; D<=1000; ++D) {
        ll xd = solvePellEquation(D);
        cout << xd <<endl;
        if (xd > maxx) {
            maxx = xd;
            dval = D;
        }
    }
    cout << maxx << endl;
    cout << dval << endl;
    return 0;
}
