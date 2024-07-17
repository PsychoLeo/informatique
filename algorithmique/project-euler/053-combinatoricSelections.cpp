#include <stdio.h>
#include <cmath>
#define MAX 101
#define MILLION 1000*1000

using namespace std;
using ll = unsigned long long int;

ll pascal[MAX][MAX];

void fillTriangle () {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            pascal[i][j] = 0;
        }
    }
}

void printTriangle () {
    for (int i=0; i<10; i++) {
        for (int j=0; j<=i; j++) {
            printf("%llu ", pascal[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    fillTriangle();
    int r = 0;
    pascal[0][0] = 1;
    for (int i=1; i<MAX; i++) {
        pascal[i][0] = 1;
        for (int j=1; j<i; j++) {
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            if (pascal[i][j] > MILLION) {
                r++;
            }
        }
        pascal[i][i] = 1;
    }
    printf("%d\n", r);
    // printTriangle();
}