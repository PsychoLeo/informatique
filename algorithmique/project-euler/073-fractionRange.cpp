/*
First remark, we know that $\frac{1}{3} < \frac{n}{d} < \frac{1}{2}$
Therefore, we can fix limits on the values :
$n \in [\frac{d}{3}; \frac{d}{2}]$

Ideas :
- brute-force solution, try every fraction in the given range and test if $gcd(n, d) = 1$
Complexity : $O(n^2\cdot log(n)) \approx 10^8\cdot 10 \approx 10^9$ operations
0.5s in C++
- POTENTIAL IDEA : using Euler's totient function $\varphi(n)$ to count more efficiently
*/

#include <cstdio>
#include <algorithm>

#define MAX 12*1000+1

using namespace std;

int main() {
	int count = 0;
	for (int d=4; d<MAX; d++) {
		for (int n=d/3; n<=d/2; n++) {
			if (__gcd(n, d) == 1 && 2*n<d && 3*n>d) count++;
		}
	}
	printf("%d\n", count);
}