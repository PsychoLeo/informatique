#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int possibleBuys (int a, int b, int c, int p) {
    int r = 0;
    r += (p%a==0) + (p%b==0) + (p%c==0);
    int ab = gcd(a, b), bc = gcd(b, c), ac = gcd(a, c);
    r += (p%ab==0) + (p%bc==0) + (p%ac==0);
    return r;
}

int main() {
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int a, b, c, p;
        int r = possibleBuys (a, b, c, p);
        printf("Case %d: %d", t+1, r);
    }
}