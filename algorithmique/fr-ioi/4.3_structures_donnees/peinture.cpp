#include <cstdio>

using namespace std;

int main() {
    int nbQte, qteCherchee, currQte;
    scanf("%d%d", &nbQte, &qteCherchee);
    bool isQuantite[100000000] = {false}; // Coup dur pour la RAM
    int quantites[100000];
    for (int i=0; i<nbQte; i++) {
        scanf("%d", &currQte);
        isQuantite[currQte] = true;
        quantites[i] = currQte;
    }
    for (int i =0; i<nbQte; i++) {
        if (isQuantite[qteCherchee-quantites[i]]) {
            printf("OUI\n");
            return 0;
        }
    }
    printf("NON\n");
}