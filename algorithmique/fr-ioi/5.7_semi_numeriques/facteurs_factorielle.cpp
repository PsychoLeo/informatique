#include <iostream>

using namespace std;
using ull = unsigned long long int;

int main() {
    ull n, p;
    cin >> n >> p;
    ull res=0, powP=p;
    while (n/powP>0) {
        res += n/powP;
        powP *= p;
    }
    cout << res << endl;
}