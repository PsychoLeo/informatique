#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> extendedGCD(int a, int b) {
    if (!b) {
        vector<int> v = {1, 0, a};
        return v;
    }
    else {
        vector<int> v = extendedGCD(b, a%b);
        int x = v[0], y = v[1], g = v[2];
        vector<int> nv = {y, x-(a/b)*y, g};
        return nv;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        vector<int> r = extendedGCD(a, b);
        printf("%d*%d + %d*%d = %d\n", a, r[0], b, r[1], r[2]);
    }
}