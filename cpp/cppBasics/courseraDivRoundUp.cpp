#include <iostream>

using namespace std;

int main() {
	int a, mod;
	cin >> a >> mod;
	if (a% mod == 0) {
		cout << a/mod << endl;
	}
	else {
		cout << a/mod + 1 << endl;
	}
}


