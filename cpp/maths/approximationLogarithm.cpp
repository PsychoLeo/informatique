#include <stdio.h>
#include <cmath>

using namespace std;

double ln (double x, int precision=1000) {
    // fonctionne seulement pour -1 < x <= 1
    double r = (double)(2*(x-1))/(x+1);
    double power = 1;
    for (int i=0; i<precision; i++) {
        r += power/(2*i+1);
        power *= ((x-1)*(x-1))/((x+1)*(x+1));
    }
    return r;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", ln(x));
}