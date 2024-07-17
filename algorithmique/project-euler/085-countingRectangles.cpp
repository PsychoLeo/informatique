/*
We remark that from every point of coordinates $(i, j)$ 
in the rectangle we can make $i \cdot j$ rectangles having this side
as bottom right corner
Therefore, for a rectangle of dimensions (n, m), the number of rectangles we can 
make is :
$\sum_{i=0}^{n} i \cdot \sum_{j=0}^{m} j$
$ = \sum_{i=0}^{n} i\cdot \frac{m(m+1)}{2}$
$ = \frac{m(m+1)}{2} \cdot \sum_{i=0}^{n} i$
$ = \frac{m(m+1)}{2}\cdot \frac{n(n+1)}{2}$

We can now iterate through $1 \le n \le 1000$ and $1 \le m \le 1000$
and find the minimum values
Time in C++ : 5 ms
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 1000
#define ld long double
#define ull unsigned long long int

int main() {
    int I, J;
    ull reach = 2*1000*1000, minDelta = MAX, bestVal;
    for (int i=1; i<MAX; i++) {
        for (int j=1; j<i; j++) {
            ld n = i*j*(i+1)*(j+1)/4;
            if (abs(n-reach) < minDelta) {
                minDelta = abs(n-reach);
                I = i; J = j;
                bestVal = n;
            } 
        }
    }
    printf("x=%d | y=%d | area=%lld\n", I, J, bestVal);
}