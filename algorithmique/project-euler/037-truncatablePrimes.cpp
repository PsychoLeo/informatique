#include <stdio.h>
#include <vector>
#include <string>
#define MAX 10*1000*1000

using namespace std;
bool P[MAX];
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

bool isRightPrime(int x) {
    // remove digits from right to left
    string currX = to_string(x);
    int size = currX.size();
    while (size > 0) {
        if (!P[stoi(currX)]) {
            return false;
        }
        currX.pop_back();
        size--;
    }
    return true;
}

bool isLeftPrime(int x) {
    // remove digits from left to right
    string currX = to_string(x);
    int size = currX.size();
    while (size > 0) {
        if (!P[stoi(currX)]) {
            return false;
        }
        currX.erase(0, 1);
        size--;
    }
    return true;
}

int main() {
    erath();
    int found = 0, sum=0;
    for (int i=10; i<MAX; i++) {
        if (isLeftPrime(i) && isRightPrime(i)) {
            found++;
            sum += i;
        }
    }
    printf("Found : %d\n", found); // 11
    printf("Sum : %d\n", sum); // 748 317
}