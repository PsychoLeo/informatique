#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
	return (b==0) ? a: gcd(b, a%b);
}

void testConjecture(ll a, ll b, ll s) {
	ll pw = s;
	while (gcd(a+s, b+s) == 1) {
		cout << a+s << " " << b+s << endl;
		s *= pw;
	}
}

int main() {
	ll a, b;
	cin >> a >> b;
	ll s = 0;
	while (gcd(a+s, b+s) != 1) {
		s++;
	}
	testConjecture(a, b, s);
}
