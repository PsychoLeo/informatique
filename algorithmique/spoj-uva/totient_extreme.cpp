#include <stdio.h>
#define size 10*1000

using namespace std;
using ll = long long int;

int main() {
    int totient[size+1];
    for (int i=0; i<=size; i++) {
        totient[i] = i;
    }
    for (int i=2; i<=size; i++) {
        if (totient[i] == i) { // if j is a prime number
            // printf("%d\n", i);
            for (int j=i; j<=size; j+=i) {
                totient[j] -= totient[j]/i;
            }
        }
    }
    ll totientSum[size+1];
    ll currSum = 0; // because phi(0) = 0
    for (int i=0; i<=size; i++) {
        currSum += totient[i];
        totientSum[i] = currSum;
    }
    int r;
    scanf("%d", &r);
    for (int i=0; i<r; i++) {
        int x;
        scanf("%d", &x);
        printf("%llu\n", totientSum[x]*totientSum[x]);
    }
}