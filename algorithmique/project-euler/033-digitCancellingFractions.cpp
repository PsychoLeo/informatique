#include <stdio.h>
#include <string>
#define n 100

using namespace std;

int isIn (char c, string s) {
    for (char cs: s) {
        if (cs == c) {
            return true;
        }   
    }
    return false;
}

int gcd(int a, int b) {
    return b == 0 ? a: gcd(b, a%b);
}

string removed (char c, string s) {
    // Returns s without the character c (only once)
    bool found = false;
    string r = "";
    for (char cs: s) {
        if (cs == c && !found) {
            found = true;
        }
        else {
            r += cs;
        }
    }
    return r;
}

int main() {
    int DENOM = 1;
    int NUMER = 1;
    for (int i=10; i<n; i++) {
        for (int j=10; j<i; j++) {
            //* Fraction est de la forme j/i
            string denom = to_string(i);
            string numer = to_string(j);
            double frac = (double)j/i;
            for (char c: numer) {
                if (isIn(c, denom) and c != '0') {
                    string newDenom = removed(c, denom);
                    string newNumer = removed(c, numer);
                    int ni = stoi(newDenom);
                    int nj = stoi(newNumer);
                    double newFrac = (double)nj/ni;
                    if (newFrac == frac) {
                        printf("%d %d\n", j, i);
                        NUMER *= j;
                        DENOM *= i;
                    }
                }
            }
        }
    }
    printf("%d\n", DENOM/gcd(DENOM, NUMER));
    return 0;
}