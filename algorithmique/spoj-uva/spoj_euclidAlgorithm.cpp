#include <stdio.h>
#include <cmath>
#include <vector>
#include <tuple>
#define mod 1000000007

using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
#define PB push_back
#define f first
#define s second
using llu = unsigned long long int;

struct FiboMatrix {
    llu a, b, c, d;

    FiboMatrix (llu A, llu B, llu C, llu D) {
        a = A;
        b = B;
        c = C;
        d = D;
    }

    FiboMatrix operator * (const FiboMatrix & other) {
        llu newA = (a*other.a + b*other.c) % mod;
        llu newB = (a*other.b + b*other.d) % mod;
        llu newC = (c*other.a + d*other.c) % mod;
        llu newD = (c*other.b + d*other.d) % mod;
        return FiboMatrix(newA, newB, newC, newD);
    }
};

pair<llu, llu> fib (llu N) {
    // Raise FiboMatrix to the power of N and get the c term
    // (corresponding to F(N))
    FiboMatrix res = FiboMatrix(1, 0, 0, 1); // identity matrix
    FiboMatrix m = FiboMatrix(0, 1, 1, 1);
    while (N > 0) {
        if (N & 1) {
            res = (res*m);
        }
        N >>= 1;
        m = (m*m);
    }
    return make_pair(res.c % mod, res.d % mod);
}

llu verifGCD(llu a, llu b) {
    llu count = 0;
    while (b != 0) {
        count++;
        llu temp = a;
        a = b;
        b = temp % b;
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        llu N;
        scanf("%llu", &N);
        if (N == 0) {
            printf("0\n");
        }
        else {
            pair<llu, llu> res = fib(N); // returns fib(n), fib(n+1)
            llu a = res.f, b = res.s;
            printf("%llu\n", (a+b)%mod);
            // printf("Result : %d\n", (a+b)%mod);
            printf("Number of GCD iterations with F(n+1) and F(n) : %llu\n", verifGCD(a, b));
        }
    }
}