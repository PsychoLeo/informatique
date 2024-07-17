#include <iostream>

using namespace std;

int gcd(int a, int b);

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int Gcd = gcd(a, b);
        cout << Gcd << " " << a/Gcd*b << "\n";
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}