#include <stdio.h>
#include <vector>

using namespace std;
using ll = unsigned long long int;

vector<int> extendedGCD (int a, int b) {
    if (!b) {
        vector<int> v = {1, 0, a};
        return v;
    }
    else {
        vector<int> v = extendedGCD(b, a%b);
        int x = v[0], y = v[1], d = v[2];
        vector<int> nv = {y, x-(a/b)*y, d};
        return nv;
    }
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        vector<int> v = extendedGCD(a, b);
        printf("%d %d %d\n", v[0], v[1], v[2]);
    }
}