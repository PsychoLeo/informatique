#include <iostream>

using namespace std;
using ull = unsigned long long int;

ull fact(int a);

int main() {
    short n, p;
    cin >> n >> p;
    // Calculer les combinaisons de p parmi n soit n!/(n-p)!*p!
    ull result = 1;
    if (n-p >= p) {
        for (int i=n; i>n-p; i--) {
            result *= i;
        }
        result /= fact(p);
    }
    else {
        for (int i=n; i>p; i--) {
            result *= i;
        }
        result /= fact(n-p);
    }
    cout << result << endl;
}

ull fact(int a) {
    if (a <= 1) {
        return 1;
    }
    else {
        return a*fact(a-1);
    }
}