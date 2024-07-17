#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = unsigned long long int;

int main() {
    // 10^(n-1) <= a^n < 10^n
    int res = 0;
    for (int a=1; a<=9; a++) {
        int toAdd = floor(-log(10)/log((double)a/10));
        res += toAdd;
    }
    printf("%d\n", res);
}