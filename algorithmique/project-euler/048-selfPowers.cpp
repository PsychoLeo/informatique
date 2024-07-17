#include <stdio.h>
#include <vector>
#include <cmath>
#define MAX 1000
// Au final, fait en Python

using namespace std;
using ll = unsigned long long int;

const ll mod = 10'000'000'000;

ll binExp (ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res*a) % (mod);
        }
        a = (a*a) % (mod);
        b >>= 1;
    }
    return res;
}

int main() {
    // printf("%llu\n", binExp(2, 7));
    ll sum = 0;
    for (ll i=1; i<= MAX; i++) {
        sum += binExp(i, i);
        sum %= (mod);
    }
    printf("%llu\n", sum);
}