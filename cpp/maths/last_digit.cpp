#include <iostream>

using namespace std;

int lastDigit (int a, int b);

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        cout << lastDigit(a, b) << "\n";
    }
}

int lastDigit (int a, int b) {
    a %= 10;
    int result = 1;
    // Operating mod 10
    while (b > 0) {
        if (b&1) {
            result = (result*a) % 10;
        }
        a = (a*a) % 10; // square it anyway
        b >>= 1;
    }
    return result%10;
}