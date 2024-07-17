#include <cstdio>
#include <vector>
#include <cmath>

#define MAX 1000*1000+1
#define ll unsigned long long int
#define ld long double
const ld PI = 3.141592653589793238462643383279502884;

using namespace std;

int totient[MAX];

void fillTotient() {
    for (int i=0; i<MAX; i++) {
        totient[i] = i;
    }
    for (int i=2; i<MAX; i++) {
        if (totient[i] == i) {
            // The number i is prime
            for (int j=i; j<MAX; j+=i) {
                totient[j] -= totient[j]/i;
            }
        }
    }
}

int main() {
    /* 
    We can see that this problem comes back to computing :
    S = SUM(k=2 to n) PHI(k)
    As the number of irreductible fractions n/d for which n < d and GCD(n, d) = 1
    is the value PHI(d)
    Therefore applying this to every possible fraction with d <= 1,000,000 we find that 
    we have to find the sum of Euler's totient function
    
    We will try two implementations :
    - sieving PHI(k) for k=0 to n and getting the sum in O(n log log n)
    - using the interesting result : S = 3n^2/PI^2 + O(n(log n)^2/3*(log log n)^4/3) when n -> +inf
    https://en.wikipedia.org/wiki/Euler%27s_totient_function
    and finding the result in O(1)) - the issue here could be with precision and the fact
    n = 1,000,000 can't be considered infinite

    Time for first/ second method : 
    - 30 ms
    - 1 ms (does not get the exact result but a very good approximation) 
    */
   fillTotient();
   ll sum = 0;
   for (int i=2; i<MAX; i++) {
       sum += totient[i];
   }
   printf("Sieving method : %llu\n", sum);

   ll n = MAX-1;
   ld r = (ld)3*n*n/(PI*PI);
    printf("Totient sum formula : %Lf\n", r);
}