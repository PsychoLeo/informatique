#include <iostream>

using namespace std;
using ll = long long;

void power (int a, int b);

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; 
        cin >> a >> b;
        power (a, b);
    }
}

void power (int a, int b) {
    int first = 1, last;
    // for last, we will work mod 1000
    // for first, we will always keep track of 4 first digits
    while (first < 100*1000 && b > 0) {
        first *= a;
        b -= 1;
    }
    last = first%1000;
    // first = a;
    while (first > 1000*1000) {
        first /= 10;
    }
    // cout << "First : " << first << " Last : " << last << endl;
    while (b > 0) {
        if (b&1) {
            first *= first;
            last = (last*last) % 1000;
        }
        b >>= 1; // divide b by 2
        while (first > 1000*1000) {
            first /= 10;
        }
    }
    cout << first/1000 << "..." << last << "\n";
}