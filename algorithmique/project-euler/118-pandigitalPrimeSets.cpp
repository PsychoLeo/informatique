#include <cstdio>
#include <vector>

#define MAX 100*1000*1000
#define ull unsigned long long int

using namespace std;


bool P[MAX];

void findSets() {

}

void fillPrimes() {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    for (int i=4; i<MAX; i+=2) {
        P[i] = false;
    }
    for (int i=3; i*i<MAX; i+=2) {
        if (P[i]) {
            for (int j=i*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
    printf("DONE sieving primes\n");
}

int main() {
    fillPrimes();
}