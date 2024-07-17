#include <cstdio>
#include <cmath>
#include <iostream>
#define deb(x) cout << #x << "=" << x << endl

using namespace std;

modifArrayReference (int x[], int add) {
	for (int i=0; i<sizeof(x)/sizeof(x[0]); i++) {
		x[i] += add;
	}
}

void printArr(int x[]) {
	for (int v: x) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	long long a;
	cin >> a;
	int sz = 10;
	int x[sz];
	for (int i=0; i<sz; i++) {
		x[i] = i;
	}
	printArr(x);
	modifArrayReference(x, 10);
	printArr(x);
}
