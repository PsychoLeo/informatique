/* 
Je ne suis pas un grand connaisseur de C++, mais je me suis dit que le langage serait plus
rapide pour ce genre de problème (même si la solution à trouver ne varie pas tant en fonction
du langage de programmation mais surtout de la formule mathématique pour trouver la somme de la somme
des PPCM)
*/

/*
Partie 1:
On sait que n >= x, soit x-n <= 0, donc |x-n| = n-x
De plus, y >= 1, donc |y-1| = y-1 car y-1 >= 0
Donc |x-n| + |y-1| < n-1 équivaut à :
n -x + y -1 < n -1
x > y (condition à vérifier pour que le minotaure attaque)
Donc la moitié du carré ne peut être occupée (sans considérer la ligne du milieu car si x == y,
le minotaure ne nous détecte pas)
Le mouvement restreint par l'action d'Hélios nous oblige à bouger soit vers le bas, soit vers la droite
On utilise une méthode de résolution de labyrinthe pour trouver les premières valeurs de k,
et on remarque qu'elles correspondent aux premiers termes de la suite de Catalan.
De plus, les termes de la suite de Catalan nous donnent le nombre de chemins sous-diagonaux dans le carré, 
ce qui correspond à ce que nous cherchons.
*/

#include <iostream>

using namespace std;


long long int catalanNum(short n) {
    // Not using recursion so that parameters don't take to much space
    // Using the factorial definition of Cn (catalan numbers)
    // Cn = (2n)!/(n!*(n+1)!) <=> Cn = 2n*(2n-1)*...*(n+2)/(n!)
    long long int result = 1;
    for (int i=n+2; i<=2*n; i++) {
        result *= i;
    }
    long long int divid = 1;
    for (int i=2; i<=n; i++) { // i can start at 2, it won't change if it starts at 1
        divid *= i;
    }
    cout << result << endl;
    cout << divid << endl;
    return result/divid;
}

int main() {
    short n; cin >> n; // getting user input
    long long int k = catalanNum(n-1); // Prologin's Catalan series start at 1 (why?) and not 0
    cout << k << endl;
}