#include <stdio.h>
#include <vector>
#include <string>
#define MAX 1000*1000

using namespace std;

bool circularPrime[MAX];
bool P[MAX]; // prime numbers
vector<int> primes = {2};

void erath() {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    for (int i=4; i<MAX; i+=2) {
        P[i] = false;
    }
    for (int i=3; i<MAX; i+=2) {
        if (P[i]) {
            primes.push_back(i);
            for (int j=2*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
}

bool isCircularPrime (int p) {
    string currPrime = to_string(p);
    for (int i=0; i<(int)currPrime.size(); i++) {
        if (!P[stoi(currPrime)]) {
            return false;
        }
        char lastDigit = currPrime.back();
        currPrime.pop_back();
        currPrime = lastDigit + currPrime;
    }
    return true;
}

int markCircular(int p) {
    int sum = 0;
    string currPrime = to_string(p);
    for (int i=0; i<(int)currPrime.size(); i++) {
        if (!circularPrime[stoi(currPrime)]) {
            sum++;
            printf("%s\n", currPrime.c_str());
            circularPrime[stoi(currPrime)] = true;
        }
        char lastDigit = currPrime.back();
        currPrime.pop_back();
        currPrime = lastDigit + currPrime;
    }
    return sum;
}

int main() {
    erath(); // fill prime arrays
    int nCircular = 0;
    for (int p: primes) {
        // printf("%d\n", p);
        if (!circularPrime[p]) {
            if (isCircularPrime(p)) {
                nCircular += markCircular(p);
            }
        }
    }
    printf("%d\n", nCircular);
}