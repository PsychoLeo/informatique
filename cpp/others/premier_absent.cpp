#include <iostream>

using namespace std;

int main() {
    int nbEleves, nbArriv, currArriv, index=0;
    cin >> nbEleves >> nbArriv;
    int limit = nbArriv;
    bool arriv[nbArriv+1] = {false};
    // for (int i=0; i<nbArriv; i++) {
    //     arriv[i] = false;
    // }
    for (int i=0; i<nbArriv; i++) // POUR chaque arrivée
    {
        cin >> currArriv; // eleve qui arrive
        // if(index>=nbEleves)
        // {
        //     cout << -1 << "\n";
        // }
        if (currArriv-1 < limit)  // Si l'élève qui est arrivé est en dessous de la limite
        {
         arriv[currArriv-1] = true; // On le signale comme arrivé sur notre limite
         while (arriv[index] == true) // Tant que notre élève est présent est true
            {
               index++; // ON passe à lélève suivant
               if (index >= nbEleves) // si notre index a dépassé les élèves qui arrivent ce jour là
                {
                  cout << -1 << "\n";
                  return 0; // c'est terminé
                }
            }
        }
        cout << index+1 << "\n";
    }
}
