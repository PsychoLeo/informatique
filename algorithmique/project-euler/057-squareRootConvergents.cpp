#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#define MAX 1000*1000*1000

using namespace std;
using ll = unsigned long long int;

struct Fraction {
    ll numer, denom;
    Fraction(ll a, ll b) {
        numer = a;
        denom = b;
    }
    void simplify() {
        ll pgcd = __gcd(numer, denom);
        numer /= pgcd;
        denom /= pgcd;
    }

    void invert() {
        swap(numer, denom);
    }

    bool moreDigitsThanDenom () {
        return (to_string(numer).size() > to_string(denom).size());
    }

    Fraction operator + (const Fraction & other) {
        Fraction res = Fraction(numer*other.denom+denom*other.numer, denom*other.denom);
        return res;
    }
};

int main() {
    int nbExpansions = 1;
    int r = 0;
    Fraction frac = Fraction(3, 2);
    while (nbExpansions <= 1000) {
        frac = frac + Fraction(1, 1);
        frac.invert();
        frac = frac + Fraction(1, 1);
        frac.simplify();
        printf("%llu %llu\n", frac.numer, frac.denom);
        if (frac.moreDigitsThanDenom()) {
            r++;
        }
        while (frac.denom > MAX) {
            frac.denom /= 10;
            frac.numer /= 10;
        }
        nbExpansions++;
    }
    printf("%d\n", r);
}