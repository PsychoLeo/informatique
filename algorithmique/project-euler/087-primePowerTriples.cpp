#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

#define ll long long int
#define n2 7071
#define n3 368
#define n4 84
#define MAX 50*1000*1000
#define db(x) cout << #x << "=" << x << endl

using namespace std;

bool counted[MAX];
vector<int> primes = {2};
bool P[MAX];

void fillPrimes() {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    for (int i=4; i<MAX; i+=2) {
        P[i] = false;
    } 
    for (int i=3; i<MAX; i+=2) {
        if (P[i]) {
            primes.push_back(i);
            for (ll j=(ll)i*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
}

int main() {
    fillPrimes();
    fill(counted, counted+MAX, false);
    ll r = 0;
    for (int i=0; primes[i] <= n2; i++) {
        for (int j=0; primes[j] <= n3; j++) {
            for (int k=0; primes[k] <= n4; k++) {
                ll n = pow(primes[i], 2) + pow(primes[j], 3) + pow(primes[k], 4);
                if (n < MAX && (!counted[n])) {
                    ++r;
                    counted[n] = true;
                }
            }   
        }
    }
    printf("%lld\n", r);
}