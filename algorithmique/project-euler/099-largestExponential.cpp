#include <cmath>
#include <cstdio>

#define MAX 1000
#define ll long long int

using namespace std;

int main() {
    double max = 0;
    int bestIndex = -1;
    for (int i=0; i<MAX; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        if ((double)b*log10(a) > max) {
            max = b*log10(a);
            bestIndex = i;
        }
    }
    printf("%d\n", bestIndex+1);
}