#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define vi vector<int>
#define MAX 51 // pour inclure 50 aussi

vector<vi> factors(MAX); // => liste des facteurs premier d'un nombre
bool P[MAX];

void fillPrimes() {
	// Crible d'érathosthène
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

void printArray() {
	for (int i=2; i<MAX; i++) {
		printf("Factors of %d : ", i);
		for (int x: factors[i]) {
			printf("%d ", x);
		}
		printf("\n");
	}
}

int main() {
	// On cherche les solutions de l'équation :
	// k*k' = 50!/5!
	// On va donc décomposer le produit 50*49*48*...*8*7*6 en facteurs premiers
	// et chercher (k, k') tels que PGCD(k, k') = 1 et k <= k'
	fillPrimes();
	for (int i=2; i<MAX; i++) {
		if (P[i]) {
				printf("%d\n", i);
			for (int j=i; j<MAX; j+=i) {
				factors[j].push_back(i);
			}
		}
	}
	printArray();
}
