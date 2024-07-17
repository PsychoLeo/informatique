#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    int n = 10*1000*1000;
    int primeCounter = 1;
    bool isPrime[n] = {true};
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i=4; i<n; i++) {
        isPrime[i] = false;
    }
    for (int i=3; i<n; i+= 2) {
        if (isPrime[i]) {
            primeCounter++;
            if (primeCounter == 10001) {
                printf("%d\n", i);
                return 0;
            }
            for (int j=2*i; j<n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

