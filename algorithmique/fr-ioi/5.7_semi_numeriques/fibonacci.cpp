#include <cmath>
#include <iostream>

using namespace std;

using ull = unsigned long long;

int main() {
    short n, i=1;
    cin >> n;
    ull fn0=0, fn1=1;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (i<n) {
        ull tmp = fn1;
        fn1 += fn0;
        fn0 = tmp;
        i++;
    }
    cout << fn1 << endl;
}