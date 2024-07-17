#include <iostream>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(10);
	long double a;
	long double b;
	cin >> a >> b;
	cout << a/b << endl;
}
