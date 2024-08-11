#include <vector>
#include <stdio.h>

using namespace std;
using ull = unsigned long long int;
using ll = long long int;

bool isPrime (ull x) {
    if (x % 2 == 0 && x != 2) {
        return false;
    }
    for (int i=3; i*i <= x; i+=2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        ull x;
        scanf("%llu", &x);
        if (isPrime(x)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}