#include <stdio.h>
#include <vector>
#define n 10*1000

using namespace std;
int sumDiv[n];
bool counted[n];

int main() {
    fill(sumDiv, sumDiv+n, 0);
    fill(counted, counted+n, false);
    for (int i=1; i<n; i++) {
        for (int j=2*i; j<n; j+=i) {
            sumDiv[j] += i;
        }
    }
    // printf("%d %d\n", sumDiv[220], sumDiv[284]);
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (sumDiv[i] < n && i != sumDiv[i] && i == sumDiv[sumDiv[i]]) {
            if (!counted[sumDiv[i]]) {
                counted[sumDiv[i]] = true;
                sum += sumDiv[i];
            }
            if (!counted[i]) {
                counted[i] = true;
                sum += i;
            }
        }
    }
    printf("%d\n", sum);
}