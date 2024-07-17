#include <stdio.h>
#include <cmath>
#include <vector>
#define MAX 1001
#define SQMAX 100*1000*1000

using namespace std;
using ll = unsigned long long int;

bool isSquare[SQMAX];
bool P[MAX];

void fill() {
    fill(isSquare, isSquare+SQMAX, false);
    for (int i=0; i*i<SQMAX; i++) {
        isSquare[i*i] = true;
    }
    P[0] = P[1] = false;
    for (int i=2; i<MAX; i++) {
        if (P[i]) {
            for (int j=i*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
}

int main() {
    fill();
    ll maxX = 0, bestD = 0;
    for (int D=1; D<MAX; D++) {
        bool found = false;
        if (P[D]) {
            // If D prime, then x^2 = 1 (mod D) => x = +/-1 (mod D)
            ll x1 = 1, x2 = D-1;
            while (!found) {
                ll sq1 = x1*x1, sq2 = x2*x2;
                if (isSquare[(sq1-1)/D]) {
                    found = true;
                    if (x1 > maxX) {
                        maxX = x1; bestD = D;
                    }
                }
                if (isSquare[(sq2-1)/D]) {
                    found = true;
                    if (x2 > maxX) {
                        maxX = x2; bestD = D;
                    }
                }
                x1 += D; x2 += D;
            }   
        }
        else if (!isSquare[D]) {
            ll x = 2;
            while (!found) {
                ll sq = x*x;
                if ((x*x)%D == 1) {
                    if (isSquare[(sq-1)/D]) {
                        found = true;
                        if (x > maxX) {
                            maxX = x; bestD = D;
                        }
                    }
                }
                x++;
            }
        }
    }
    printf("x: %llu | D:%llu\n", maxX, bestD);
}