#include <cstdio>
#include <cmath>
#include <algorithm>

#define ll long long int
#define MAX 14

using namespace std;

const double a = 7, b = 4*sqrt(3);

ll x_n (int n) {
    return (ll)round((pow(a+b, n)+pow(a-b, n))/2);
}

ll y_n (int n) {
    return (ll)round((pow(a+b, n)-pow(a-b, n))/(2*b));
}

int main() {
    for (int k=1; k<MAX; k++) {
        ll r = x_n(k);
        if (r % 4 == 3) {
            printf("k=%d | n=%lld | a=%lld\n", k, (r-3)/4, y_n(k));
        }
    }
}