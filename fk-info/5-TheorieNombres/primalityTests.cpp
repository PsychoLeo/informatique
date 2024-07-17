#include <cstdio>
#include <cmath>

#define ull unsigned long long int

using namespace std;
using u128 = __int128;

ull binExp(ull n, ull e, ull m) {
    // Returns n^e (mod m)
    n %= m;
    u128 res = 1;
    while (e > 0) {
        if (e & 1) {
            res = (u128)res*n % m;
        }
        n = (u128)n*n % m;
        e >>= 1;
    }
    return (ull)res;
}

bool checkComposite(ull n, ull a, ull d, int s) {
    ull x = binExp(a, d, n);
    if (x == 1 || x == n-1) {
        return false;
    }
    for (int i=0; i<s-1; i++) {
        x = (u128)x*x%n;
        if (x == n-1) {
            return false;
        }
    }
    return true;
}

bool millerRabin(ull n, int iter=8) {
    if (n < 4) return n == 2 || n == 3;
    int s=0; // n = 2^s*d
    ull d = n-1;
    while ((d&1)==0) {
        // while the number is divisible by 2
        d >>= 1;
        ++s;
    }
    for (int i=0; i<iter; i++) {
        ull a = 2 + rand() % (n-3);
        if (checkComposite(n, a, d, s)) {
            return false; // n is not prime
        }
    }
    return true; // n is probably prime
}

int main() {
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) {
        ull x;
        scanf("%llu", &x);
        millerRabin(x) ? printf("YES\n"): printf("NO\n");
    }
}