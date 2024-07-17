#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	char digits[16] = {'1','4','1','5','9','2','6','5','3','5','8','9','7','9','3','2'};
	if (n > 0) {
		cout << "3.";
		for (int i=0; i<n; i++) {
			cout << digits[i];
		}
		cout << endl;
	}
	else {
		cout << 3 << endl;
	}
}

int main() {

}
