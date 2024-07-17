#include <stdio.h>

using namespace std;
using ll = long long unsigned int;

const int mod = 10000007;

ll pow (ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n, k;
    scanf("%llu %llu", &n, &k);
    while (n != 0 && k != 0) {
        ll Zn = pow(n, k) + 2*pow(n-1, k) + pow(n, n) + 2*pow(n-1, n-1);
        printf("%llu\n", Zn%mod);
        scanf("%llu %llu", &n, &k);
    }
}