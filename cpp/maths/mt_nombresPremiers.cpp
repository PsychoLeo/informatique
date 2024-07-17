#include <stdio.h>
#include <cmath>
#include <vector>

#define MAX 1000*1000*1000

using namespace std;

bool P[MAX];

void fillPrimes() {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    for (int i=2; i<MAX; i++) {
        if (P[i]) {
            for (long long j = (long long)i*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
    // printf("Erathosthene done..."); 
}

int gcd(int a, int b) {
    return b ? gcd(b, a%b): a;
}

int f(int x) {
    return pow(x, 8)-1;
}

int main() {
    fillPrimes();
    int currGcd = gcd(f(7), f(11));
    for (int x=12; f(x)<MAX; x++) {
        if (P[f(x)]) {
            currGcd = gcd(currGcd, f(x));
        }
    }
    printf("%d\n", currGcd);
}