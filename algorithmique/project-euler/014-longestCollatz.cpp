#include <stdio.h>
#include <algorithm>

#define n 1000*1000
#define ll long long unsigned int

using namespace std;

ll collatzLength (ll x) {
    int length = 1;
    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
        }
        else {
            x = 3*x+1;
        }
        length++;
    }
    return length;
}

int main() {
    ll maxSize = 0;
    ll bestNumber;
    for (ll i=1; i<n; i++) {
        ll currCollatz = collatzLength(i);
        if (currCollatz > maxSize) {
            bestNumber = i;
            maxSize = currCollatz;
        }
    }
    printf("%llu\n", bestNumber);
}