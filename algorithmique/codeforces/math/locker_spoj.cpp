#include <stdio.h>
#define mod 1'000'000'007

using namespace std;
using ll = unsigned long long int;

ll binPow (ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a*a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        ll x;
        scanf("%llu", &x);
        if (x < 3) {
            printf("%llu\n", x);
            continue;
        }
        ll r;
        switch (x%3) {
            case 0 : 
                r = binPow(3, x/3);
                break;
            case 1 : 
                r = 4*binPow(3, (x-4)/3);
                break;
            case 2 : 
                r = 2*binPow(3, (x-2)/3);
                break;
        }
        printf("%llu\n", r%mod);
    }
}