#include <cstdio>
#include <vector>

#define MAX 10*1000*1000
#define inf (double)1000*1000*1000

using namespace std;

int phi[MAX];
short phiDigits[MAX][11] = {}; // 10^8 in memory

void fillTotient() {
    for (int i=0; i<MAX; i++) {
        phi[i] = i;
    }
    for (int i=2; i<MAX; i++) {
        if (phi[i] == i) {
            for (int j=i; j<MAX; j+=i) {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

void printArray() {
    for (int i=2; i<=10; i++) {
        printf("%d ", phi[i]);
    }
    printf("\n");
}

bool isPermutation (int N) {
    // Returns true if phi(n) is a permutation of n
    int n = N; // temporary value for n (counting digits occurences)
    short digits[11] = {};
    while (n > 9) {
        digits[n%10]++;
        n /= 10;
        digits[10]++; // size is increased
    }
    digits[10]++;
    digits[n]++; // first digits also counts
    if (digits[10] == phiDigits[N][10]) {
        for (int i=0; i<10; i++) {
            if (phiDigits[N][i] != digits[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void fillDigits() {
    for (int i=2; i<MAX; i++) {
        int totientN = phi[i];
        while (totientN > 9) {
            phiDigits[i][totientN%10]++;
            totientN /= 10;
            phiDigits[i][10]++; // size is increased
        }
        phiDigits[i][10]++;
        phiDigits[i][totientN]++; // first digits also counts
    }
}

int main() {
    fillTotient();
    fillDigits();
    // printArray();
    double minRapport = +inf;
    int maxN = -1;
    for (int i=2; i<MAX; i++) {
        if (isPermutation(i)) {
            double r = (double)i/phi[i];
            if (r < minRapport) {
                minRapport = r;
                maxN = i;
            }
        }
    }
    printf("%d\n", maxN);
}