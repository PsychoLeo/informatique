#include <iostream>

using namespace std;

int main() {
	// cout.setf(ios::fixed);
	cout.precision(20);
	long double a;
	cin >> a;
	float f = a;
	cout << (long double)f-a << endl;
}
