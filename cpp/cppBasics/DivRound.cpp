#include <iostream>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(0);
	double a,b;
	cin >> a >> b;
	cout << a/b << endl;
}
