#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

int w, h; // width, height (largeur, longeur du tableau)
vector<vector<int>> M; // liste contenant les colonnes
vector<int> lin; // colonne contenant 42


/*
=> On crée un tableau M contenant toutes les colonnes de notre tableau (sauf celle avec 42, que l'on marque à part comme étant lin)

=> Si le nombre de zeros dans M est strictement inférieur à len(L)-1 -> on renvoie impossible

NB : il n'y aura jamais de rajout d'éléments à lin
*/

void readInput() {
    vector<vector<int>> grid;
    scanf("%d %d", &h, &w);
    for (int i=0; i<h; i++) {
        vector<int> l;
        bool found = false;
        for (int j=0; j<w; j++) {
            int n;
            scanf("%d", &n);
            l.push_back(n);
        }
        grid.push_back(l);
    }
    for (int i=0; i<w; ++i) {
        vector<int> l;
        bool found = false;
        for (int j=h-1; j>=0; --j) {
            if (grid[j][i] != 0) {
                l.push_back(grid[j][i]);
            }
            if (grid[j][i] == 42) {
                found = true;
            }
        }
        if (!found) {
            M.push_back(l);
        }
        else {
            for (int e: l) {
                lin.push_back(e);
            }
        }
    }
}

void printGrid() {
    for (int e: lin) {
        printf("%d ", e);
    }
    printf("\n");
    for (vector<int> l: M) {
        for (int x: l) {
            printf("%d ", x);
        }
        printf("\n");
    }
}

int main() {
    readInput();
    // printGrid();
    int moves = 0;
    int n = lin.pop_back();
    int minMoves = numeric_limits<int>::max();
}