#include <stdio.h>
#include <cmath>

using namespace std;
using ll = double;

ll parmiResult() {
    ll res = 1;
    for (int i=40; i>20; i--) {
        res *= i;
        printf("%lf\n", res);
    }
    for (int i=1; i<=20; i++) {
        res /= i;
    }
    return res;
}

int main() {
    // Nombres de combinaisons possibles pour placer
    // 20 lettres D et 20 lettres R
    // Calculer 20 parmi 40
    printf("%lf\n", parmiResult());
}