#include <stdio.h>
#include <algorithm>
#define WIDTH 50
#define HEIGHT 2000

using namespace std;
using li = long int;

li grid[HEIGHT][WIDTH];
int n, m, p;

int main() {
    scanf("%d %d %d",&n, &m, &p);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            li x;
            scanf("%ld", &x);
            grid[i][j] = x;
        }
    }
    int minWidth = p, maxWidth = p+1, steps = n-1; // largeur pour savoir si on peut accéder à ces cases
    while (steps >= 0) {
        for (int i=0; i<minWidth; i++) {
            grid[steps][i] = 0;
        }
        for (int i=maxWidth; i<m; i++) {
            grid[steps][i] = 0;
        }
        steps--;
        maxWidth++;
        minWidth--;
    }

    for (int i=n-2; i>=0; i--) {
        grid[i][0] += max(grid[i+1][0], grid[i+1][1]);
        for (int j=1; j<m-1; j++) {
            grid[i][j] += max(grid[i+1][j-1], max(grid[i+1][j], grid[i+1][j+1]));
        }
        grid[i][m-1] += max(grid[i+1][m-1], grid[i+1][m-2]);
    }
    
    // Attention : en partant des côtés il y a des mvts illégaux
    li maxi = -1000*1000*1000;
    for (int i=0; i<m; i++) {
        if (grid[0][i] > maxi) {
            maxi = grid[0][i];
        }
    }
    printf("%ld\n", maxi);
}