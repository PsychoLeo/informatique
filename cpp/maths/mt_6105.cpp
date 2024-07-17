#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>

#define ld long double
#define ll long long int
#define N 10
#define MAX (1000*1000)
ld v[N];

using namespace std;

void printArray() {
    for (ld x: v) {
        printf("%LF\n", x);
    }
}

int main() {
    srand(time(0));
    ld prod = 1;
    int mod = 2*MAX;
    for (int i=0; i<N-1; i++) {
        ld d;
        ll r;
        do {
            r = (rand() % mod);
            d = (ld)r/MAX;
            printf("%LF\n", d);
        } while (r == 0);
        v[i] = d;
        prod *= d;
    }
    v[N-1] = (ld)1/prod; // leur produit vaut 1
    printf("%LF\n", prod*v[N-1]);
    // printArray();
    ld sum = 0;
    for (ld x: v) {
        sum += (ld)1/(x+1);
    }
    printf("%LF\n", (ld)N/sum);
}