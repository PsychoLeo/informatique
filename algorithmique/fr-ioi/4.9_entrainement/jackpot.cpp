using namespace std;

#include <cstdio>
#include <iostream>
#include <vector>

#define MAX 1000*1000+1
#define MAX_SIZE 1000

int roues[MAX][2]; // (nombres d'éléments, sommes des positions)
int nbRoues, nbSymbolesRoue, energieTot;
int grid[MAX_SIZE][MAX_SIZE];

void fillArray() {
    for (int i=0; i<MAX; i++) {
        roues[i][0] = 0;
        roues[i][1] = 0;
    }
}

/*
Idée n°1: 
On parcours la grille par colonne car le prix de décalage est croissant
en fonction du numéro de la colonne que l'on parcourt
Donc on peut toujours ajouter tant que la somme des décalages pour atteindre
un certain nombre est inférieur à l'énergie totale
*/

int main() {
    fillArray();
    scanf("%d %d %d", &nbRoues, &nbSymbolesRoue, &energieTot);
    for (int i=0; i<nbRoues; i++) {
        for(int j=0; j<nbSymbolesRoue; j++) {
            int x;
            scanf("%d", &x);
            grid[i][j] = x;
        }
    }
    int maxLength = 0;
    for (int x=0; x<nbSymbolesRoue; x++) {
        for (int y=0; y<nbRoues; y++) {
            int currNum = grid[y][x];
            if (roues[currNum][1] + x <= energieTot) {
                roues[currNum][0]++;
                roues[currNum][1] += x;
                if (roues[currNum][0] == nbRoues) {
                    if ((energieTot-roues[currNum][1])%nbSymbolesRoue==0) {
                        printf("%d\n", nbRoues);
                        return 0;
                    }
                    else {
                        roues[currNum][0]--;
                        roues[currNum][1] -= x;
                    }
                }
                else if (roues[currNum][0] > maxLength) {
                    maxLength = roues[currNum][0];
                }
            }
        }
    }
    printf("%d\n", maxLength);
    return 0;
}