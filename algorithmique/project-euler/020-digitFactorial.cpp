#include <stdio.h>
#define n 10
#define max 10*1000*1000

using namespace std;

int fact[10];

int factorial(int x) {
    int res = 1;
    for (int i=1; i<=x; i++) {
        res *= i;
    }
    return res;
}

int sumDigitsFactorial (int x) {
    int sum = 0;
    while (x > 0) {
        sum += fact[x%10];
        x /= 10;
    }
    return sum;
}   

int main() {
    for (int i=0; i<n; i++) {
        fact[i] = factorial(i);
    }
    int sum = 0;
    for (int i=3; i<max; i++) {
        if (sumDigitsFactorial(i) == i) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("Result : %d\n", sum);
}