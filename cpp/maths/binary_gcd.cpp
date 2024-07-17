#include <stdio.h>
#include <iostream>
#include <chrono>
#include <algorithm>

#define MAX 1000*1000*1000
#define n 10*1000

using namespace std;
using namespace std::chrono;
typedef int (*vFunctionCall)(int a, int b);

// On se base sur les propriétés suivantes:  
// - si 2|a et 2|b alors gcd(a, b) = 2*gcd(a/2, b/2)
// - si 2|a et b congru à 1 (mod 2), alors gcd(a, b) = gcd(a/2, b)
// etc...

int gcd(int a, int b) {
    return b ? gcd(b, a%b): a;
}

int binaryGCD(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

void functionTime (vFunctionCall f, string functionName) {
    auto start = high_resolution_clock::now();
    for (int i=0; i<n; i++) {
        int a = rand() % MAX;
        int b = rand() % MAX;
        int GCD = f(a, b);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << functionName << " : " << duration.count() << " ms\n";
}

int main() {
    cout.precision(10);
    functionTime(binaryGCD, "Binary GCD");
    functionTime(gcd, "Euclidian GCD");
    functionTime(__gcd, "Library GCD (C++ 17)");
    return 0;
}