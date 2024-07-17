#include <cstdio>
#include <vector>
#include <iostream>

#define ull unsigned long long int
#define MAX 10*1000*1000
#define db(x) cout << #x << "=" << x << endl

using namespace std;

bool P[MAX];
vector<int> primes;
int NumDiv[MAX];

// void fillPrimes() {
//     fill(P, P+MAX, true);
//     P[0] = P[1] = false;
//     for (int i=2; i<MAX; i++) {
//         if (P[i]) {
//             primes.push_back(i);
//             for (ull j=(ull)i*i; j<MAX; j+=i) {
//                 P[j] = false;
//             }
//         }
//     }
//     printf("DONE FILLING PRIMES\n");
// }

void generateNumberPrimeDiv() {
    // Fills an array with the number of divisors of each number
    fill(NumDiv, NumDiv+MAX, 1);
    for (int p: primes) {
        for (int j=p; j<MAX; j+=p) {
            int exp = 0, tmp = j;
            while (tmp % p == 0) {
                tmp /= p;
                exp++;
            }
            NumDiv[j] *= (1+2*exp);
        }
    }
    // printf("Nombre de div de 1260 : %d\n", NumDiv[1260]);
}

// ull nDivSqrt(ull n) {
//     int nbDiv = 0;
//     for (int i=2; i*i<=n; i++) {
//         if (n % i == 0) {
//             nbDiv+=2;
//             if (n/i == (ull)i) {
//                 nbDiv--;
//             }
//         }
//     }
//     return nbDiv;
// }

ull nDivB(ull n) {
    // Find number of divisors of n^2
    // printf("Number of divisors function B\n");
    ull r = 1;
    int exp = 0;
    while (n%2==0) {
        n >>= 1;
        exp++;
    }
    r *= (1+2*exp);
    for (int i=3; n>1 && i*i<=n; i+=2) {
        exp = 0;
        while (n%i==0) {
            n /= i;
            exp++;
        }
        r *= (1+2*exp);
    }
    if (n>1) {
        r *= 3;
    }
    return (r+1)/2;
}

ull nDiv (ull n) {
    // Returns the number of divisors of n^2
    ull nbDiv = 1; // nombres de diviseurs de n^2
    int i = 0;
    while (n > 1) {
        int exp = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            exp++;
        }
        nbDiv *= (1+2*exp);
        i++;
    }
    return (nbDiv+1)/2;
}

/*
Ok, obviously we will need a more clever implementation
because this one does not work at all for a limit of 4*1e6
We will search e1, e2,..., e_k such that n = p1^e1*p2^e2*...*p_k^e_k
and the number of divisors of n^2 = (1+2*e1)*(1+2*e2)*...*(1+2*e_k) >= 8*10^6
Supposing e1 >= e2 >= e3 >= ... >= e_k, we will know that the resulting number will be
N = 2^e1*3^e2*5^e3*...*p_k^e_k as it will be the minimum number fitting these conditions
*/

int main() {
    // fillPrimes();
    // generateNumberPrimeDiv();
    ull n=1260;
    ull res = nDivB(n);
    // printf("%llu\n", nDivB(1260));
    ull toReach = 1000;
    while (res <= toReach) {
        // printf("n=%llu : %llu\n", n, res);
        res = nDivB(++n);
    }
    printf("%llu\n", n);
}