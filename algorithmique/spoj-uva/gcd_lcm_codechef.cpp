#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = unsigned long long int;

ll gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        ll pgcd = gcd(a, b);
        ll ppcm = a/pgcd*b;
        printf("%llu %llu\n", pgcd, ppcm);
    }
}