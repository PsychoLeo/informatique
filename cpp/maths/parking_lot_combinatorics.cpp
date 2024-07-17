#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    // Fill parking lot of size 2n-2 with row of n cars
    // Choisir une voiture parmi les 4 marques : 1 parmi 4 = 4
    // Choisir un emplacement pour les n voitures : 2n-2-n+1 = n-1
    // Remplir les autres cases : 3^(n-2) car on choisit une voiture parmi 3 n-2 fois
    // Principe multiplicatif : 4*(n-1)*3^(n-2)
    cout << (int)4*(n-1)*3*pow(4, n-3) << endl;
    return 0;
}