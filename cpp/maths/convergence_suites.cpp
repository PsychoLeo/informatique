#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout.precision(10);
    double a, b, u, v;
    cin >> a >> b;
    u = a;
    v = b;
    for (int i=0; i<20; i++) {
        // cout << a << " " << b << endl;
        a = (u+v)/2;
        b = sqrt((u*u + v*v)/2);
        u = a;
        v = b;
    }
    // cout << "Result :" << endl;
    cout << u << endl;
}