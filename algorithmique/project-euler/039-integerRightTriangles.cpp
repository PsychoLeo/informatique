#include <stdio.h>
#include <cmath>
#include <algorithm>
#define MAX 1000
#define d 0.00001

using namespace std;

int main() {
    int bestValue = 120; // taking the value from the exercise
    int maxSolutions = 3;
    for (int p = 1; p<MAX; p++) {
        int nbSolutions = 0;
        for (int a=1; a<p; a++) {
            double b = (double)(2*p*a-p*p)/(2*a-2*p);
            double intPartB;
            if (modf(b, &intPartB) == 0.0 && intPartB != 0.0) {
                double c = sqrt(a*a+b*b);
                double intPartC;
                double floatPartC = modf(c, &intPartC);
                if ((floatPartC < d || floatPartC > 1-d) && p == a+b+c) {
                    nbSolutions++;
                    // printf("p=%d : %d^2 + %lf^2 = %lf^2\n", p, a, b, c);
                }
            }
        }
        if (nbSolutions > maxSolutions) {
            maxSolutions = nbSolutions;
            bestValue = p;
        }
    }
    printf("%d\n", bestValue);
    return 0;
}