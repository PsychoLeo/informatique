#include <stdio.h>
#include <vector>
#define PB push_back
#define MAX 1000*1000

using namespace std;

bool P[MAX];
vector<int> ecc = {0}; // effectif cumulé croissant

void printFirstECC () {
    for (int i=0; i<10; i++) {
        printf("%d ", ecc[i]);
    }
    printf("\n");
}

void fillPrimes() {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    int sum = 0;
    for (int i=2; i<MAX; i++) {
        if (P[i]) {
            if (sum+i < MAX) {
                sum += i;
                ecc.PB(sum);
            }
            for (int j=2*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
}

int main() {
    fillPrimes();
    // printFirstECC();
    int n = (int)ecc.size()-1;
    for (int len=n; len>0; len--) {
        for (int dep=0; dep<=n-len; dep++) {
            if (P[ecc[dep+len]-ecc[dep]]) {
                printf("%d\n", ecc[dep+len]-ecc[dep]);
                return 0;
            }
        }
    }
}