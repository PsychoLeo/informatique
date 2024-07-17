#include <stdio.h>
#include <vector>
#define size 10*1000*1000

using namespace std;
using ll = long long unsigned int;

vector<int> primes;
bool isPrime[size];

void initializePrimes () {
    fill(isPrime, isPrime+size, true);
    isPrime[0] = false;
    isPrime[1] = false;
    primes.push_back(2);
    for (int i=4; i<size; i+=2) {
        isPrime[i] = false;
    }
    for (int i=3; i<size; i+=2) {
        if (isPrime[i]) {
            // printf("%d\n", i);
            primes.push_back(i);
            for (int j=2*i; j<size; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int nbDiviseurs (ll n) {
    int nb = 1;
    int i = 0; // current prime number
    while (n > 1) {
        int e = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            e++;
        }
        nb *= (1+e);
        i++;
    }
    return nb;
}

void printFirstPrimes (int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    ll n = 1;
    int i = 2;
    initializePrimes();
    // printFirstPrimes(20);
    while (nbDiviseurs(n) <= 500) {
        // printf("%llu\n", n);
        n += i;
        i++;
    }
    printf("%llu\n", n);
}