#include <stdio.h>
#include <vector>
#define SIZE 500

using namespace std;

int height, width, indice;
vector<int> pred(SIZE);
vector<int> dp(SIZE);

void printArray(vector<int> &array, int width) {
    for (int i=0; i<width; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    fill(pred.begin(), pred.end(), 0);
    scanf("%d %d %d", &height, &width, &indice);
    for (int i=0; i<height-1; i++) {
        int x, y; 
        scanf("%d %d", &x, &y);
        pred[x] += y;
        for (int j=0; j<width; j++) {
            int maxi = 0;
            for (int I:{j-1, j, j+1}) {
                if (0 <= I && I < width) {
                    maxi = max(maxi, pred[I]);
                }
            }
            dp[j] = maxi;
        }
        for (int j=0; j<width; j++) {
            pred[j] = dp[j];
        }
        // printArray(dp, width);
    }
    printf("%d\n", dp[indice]);
}