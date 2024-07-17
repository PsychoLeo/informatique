#include <stdio.h>
#include <initializer_list>

const int MOINS_INFINI = -10000000;
const int MAX_LIN = 20000;
const int MAX_COL = 500;
int nbLin, nbCol, colDepart;
int jeu[MAX_LIN][MAX_COL] = {0};
int dynMeilleurScore[MAX_LIN][MAX_COL] = {0};

int main() {
   // entrée
   scanf("%d %d %d", &nbLin, &nbCol, &colDepart);
   for(int lin = 0; lin < nbLin; lin++) {
      int col;
      scanf("%d", &col);
      scanf("%d", &jeu[lin][col]);
   }
   // première ligne
   for(int col = 0; col < nbCol; col++)
      dynMeilleurScore[0][col] = jeu[0][col];
   // autres lignes
   for(int lin = 1; lin < nbLin; lin++) {
      for(int col = 0; col < nbCol; col++) {
         int meilleur = MOINS_INFINI;
         for(int dep: {0, -1, 1}) {
            int curCol = col + dep;
            if (curCol >= 0 && curCol < nbCol && dynMeilleurScore[lin-1][curCol] > meilleur) {
               meilleur = dynMeilleurScore[lin-1][curCol];
            }
         }
         dynMeilleurScore[lin][col] = jeu[lin][col] + meilleur;
      }
   }
   printf("%d\n", dynMeilleurScore[nbLin-1][colDepart]);
   return 0;
}