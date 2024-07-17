#include <cstdio>
#include <iostream>
#include <cmath>

#define MAX 180
#define ull unsigned long long int
#define mod 823543

int main() {
    for (int a=1; a<MAX; a++) {
        for (int b=1; b<a; b++) {
            if (a*b*(a+b) % 7) {
                if ((ull)(pow(a+b, 7)-pow(a, 7)-pow(b, 7))%mod == 0) {
                    printf("%d %d\n", a, b);
                }
            }
        }
    }
}