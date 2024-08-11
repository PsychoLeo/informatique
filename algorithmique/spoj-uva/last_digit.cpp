#include <stdio.h>
#include <vector>

using namespace std;

int lastDigit (int a, int b) {
    if (a == 0) {
        return 0;
    }
    a %= 10;
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % 10;
        }
        a = (a*a) % 10;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lastDigit(a, b));
    }
}