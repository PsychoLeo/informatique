#include <stdio.h>
#define size 1000*1000

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ETF[size+1];
    for (int i=0; i<=size; i++) {
        ETF[i] = i;
    }
    for (int i=2; i<=size; i++) {
        if (ETF[i] == i) {
            for (int j=i; j<=size; j+=i) {
                ETF[j] -= ETF[j]/i;
            }
        }
    }
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", ETF[x]);
    }
}