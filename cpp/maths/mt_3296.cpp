#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
using ll = long long;
const int p = 43;
int ltP[p-1];

ll fact (int n) {
	ll res = 1;
	for (int i=1; i<=n; i++) {
		res *= i;
	}
	return res;
}

void findModularInv (int x) {
	for (int i: ltP) {
		if ((x*i) % p == 1) {
			printf("%d * %d = 1 (mod %d)\n", x, i, p);
			return;	
		}
	}
}

int main() {
	// cout << "Enter prime number : ";
	// cin >> p;
	for (int i=1; i<p; i++) {
		ltP[i-1] = i;
	}
	for (int x=0; x<=p/2; x++) {
		findModularInv(x);
	}
	return 0;
}
