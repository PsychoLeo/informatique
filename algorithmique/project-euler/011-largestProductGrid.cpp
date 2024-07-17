#include <stdio.h>
#include <vector>
#include <algorithm>
#define size 20

using namespace std;

int l[size][size];

int maxDiagoDroite () {
    int maxi = 0;
    for (int i=0; i<16; i++) {
        for (int j=0; j<16; j++) {
            int prod = 1;
            for (int k=0; k<4; k++) {
                prod *= l[i+k][j+k];
            }
            maxi = max(maxi, prod);
        }
    }
    return maxi;
}

int maxDiagoGauche() {
    int maxi = 0;
    for (int i=19; i>=4; i--) {
        for (int j=0; j<16; j++) {
            int prod = 1;
            for (int k=0; k<4; k++) {
                prod *= l[i-k][j+k];
            }
            maxi = max(maxi, prod);
        }
    }
    return maxi;
}

int maxLine () {
    int maxi = 0;
    for (int i=0; i<20; i++) {
        for (int j=0; j<16; j++) {
            int prod = 1;
            for (int k=0; k<4; k++) {
                prod *= l[i][j+k];
            }
            maxi = max(maxi, prod);
        }
    }
    return maxi;
}

int maxColumn() {
    int maxi = 0;
    for (int i=0; i<16; i++) {
        for (int j=0; j<20; j++) {
            int prod = 1;
            for (int k=0; k<4; k++) {
                prod *= l[i+k][j];
            }
        }
    }
    return maxi;
}

int main() {
    for (int i=0; i<20; i++) {
        for (int j=0; j<size; j++) {
            scanf("%d", &l[i][j]);
        }
    }
    int maxi[4] = {maxDiagoDroite(), maxDiagoGauche(), maxLine(), maxColumn()};
    printf("%d\n", *max_element(maxi, maxi+4));
}
