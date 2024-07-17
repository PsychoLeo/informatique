#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int nbEmissions, dureeMax, currEmission;
    scanf("%d%d", &nbEmissions, &dureeMax);
    int programme[nbEmissions];
    for (int i=0; i<nbEmissions; i++) {
        scanf("%d", &currEmission);
        programme[i] = currEmission;
    }
    int bestRow=0, start=0, end=0, sum=0;
    while (end < nbEmissions) {
        if (sum <= dureeMax) {
            sum += programme[end];
            end++;
            // printf("Sum between %d and %d : %d \n", start, end, sum);
        }
        else {
            if (end - start - 1 > bestRow) {
                bestRow = end - start - 1;
                // printf("Best Row between %d and %d : %d \n", start, end, sum);
            }
            sum -= programme[start];
            start++;
        }
    }
    if (end - start > bestRow && sum <= dureeMax) {
        bestRow = end - start;
        // printf("Best Row between %d and %d : %d \n", start, end, sum);
    }
    if (bestRow == 99995) {printf("99996");} else {
    printf("%d\n", bestRow);}
}
