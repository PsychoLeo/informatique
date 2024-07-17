#include <stdio.h>
#include <vector>
#define n 28124

using namespace std;
vector<int> abundantNb;
int sumDiv[n];
bool isSumAbundant[n];

int main() {
    fill(sumDiv, sumDiv+n, 0);
    for (int i=1; i<n; i++) {
        for (int j=2*i; j<n; j+=i) {
            sumDiv[j] += i;
        }
    }
    for (int i=0; i<n; i++) {
        if (sumDiv[i] > i) {
            abundantNb.push_back(i);
        }
    }
    for (int a: abundantNb) {
        for (int b: abundantNb) {
            if (a + b < n) {
                isSumAbundant[a+b] = true;
            }
        }
    }
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (!isSumAbundant[i]) {
            sum += i;
        }
    }
    printf("%d\n", sum);
}