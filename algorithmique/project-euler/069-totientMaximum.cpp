#include <cstdio>
#include <vector>
#define MAX 1000*1000+1

double phi[MAX];

void printArray() {
    for (int i=2; i<=10; i++) {
        printf("Phi(%d) = %lf\n", i, phi[i]);
    }
    printf("\n");
}

int main() {
    std::fill(phi, phi+MAX, 1);
    for (int i=2; i<MAX; i++) {
        if (phi[i] == 1) {
            // The number is prime
            for (int j=i; j<MAX; j+=i) {
                phi[j] *= ((double)i/(i-1));
            }
        }
    }
    // printArray();
    double max = -1;
    int maxIndex = -1;
    for (int i=2; i<MAX; i++) {
        if (phi[i] > max) {
            max = phi[i];
            maxIndex = i;
        }
    }
    printf("%d\n", maxIndex);
}