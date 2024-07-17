#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long
#define MAX 60

using namespace std;
int P[MAX];

void fillPrimes () {
	fill(P, P+MAX, true);
	P[0] = P[1] = false;
	for (int i=2; i<MAX; i++) {
		if (P[i]) {
			for (int j=i*i; j<MAX; j+=i) {
				P[j] = false;
			}
		}
	}
}

ll pow2 (int n) {
	ll res = 1;
	for (int i=0; i<n; i++) {
		res *= 2;
	}
	return res;
}

void findDivisors (int a) {
	ll n = pow2(a)-1;
	printf("Divisors of %lld (2^%d-1) :\n", n, a);
	for (ll i=2; i*i<=n; i++) {
		if (n%i == 0) {
			printf("%lld %lld\n", i, n/i);
		}
	}
	printf("\n");
}

int main() {
	fillPrimes();
	// Recherche pour l'exercice #3246 Mathraining
	// Montrer que si 2^n-1 est premier, alors n est premier.
	// On raisonne par contraposée en supposant n non premier
	// Si n congru à 0 (mod 2), alors 2^n-1 non premier car factorisable (forme a^2-b^2)
	// Si n congru à 1 (mod 2) -> ORDINATEUR pour conjecturer
	for (int i=1; i<MAX; i+=2) {
		if (!P[i]) {
			findDivisors(i);
		}
	}
}
