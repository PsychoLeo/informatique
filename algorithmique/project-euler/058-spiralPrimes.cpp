#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

struct Fraction {
    int numer, denom;

    Fraction (int a, int b) {
        numer = a;
        denom = b;
    }

    double getValue() {
        return (double)numer/denom;
    }
};

bool isPrime (int x) {
    // Dismissing the case n=2 as not included in the spiral diagonals
    for (int i=2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 1;
    Fraction rapport = Fraction(0, 1);
    // printf("%d\n", isPrime(43));
    int mult = 1;
    while (rapport.getValue() >= 0.1 || n==1) {
        for (int i=0; i<4; i++) {
            n += (2*mult);
            if (isPrime(n)) {
                printf("%d\n", n);
                rapport.numer++;
            }
            rapport.denom++;
        }
        mult++;
    }
    mult--;
    printf("%d\n", 2*mult+1);
}