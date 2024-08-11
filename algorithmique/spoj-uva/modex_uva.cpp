#include <stdio.h>
#include <iostream>

using namespace std;
using ll = unsigned long long int;

ll pow (int a, int b, int m) {
    a %= m;
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    // int t;
    // scanf("%d",&t);
    int count = 0;
    while (count != EOF) {
        ll a, b, m;
        count = scanf("%llu %llu %llu", &a, &b, &m);
        if (count != EOF) {
            printf("%llu\n", pow(a, b, m));
        }
    }
}