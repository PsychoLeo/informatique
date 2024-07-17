#include <stdio.h>
#include <vector>
#define MAX 10*1000*1000
#define PB push_back

using namespace std;
bool P[MAX];
vector<int> squares;

void fillPrimes() {
    fill(P, P+MAX, true);
    for (int i=4; i<MAX; i+=2) {
        P[i] = false;
    }
    for (int i=3; i<MAX; i+=2) {
        if (P[i]) {
            for (int j=2*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
}

void fillSquares() {
    for (int i=0; i*i < MAX; i++) {
        squares.PB(i*i);
    }
}

int main() {
    fillPrimes();
    fillSquares();
    for (int odd=1; odd<MAX; odd+=2) {
        if (!P[odd]) {
            bool found = false;
            for (int i=0; 2*squares[i] < odd; i++) {
                if (P[odd-2*squares[i]]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("%d\n", odd);
                return 0;
            }
        }
    }
}