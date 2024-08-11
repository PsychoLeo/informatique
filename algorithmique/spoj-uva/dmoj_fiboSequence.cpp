#include <stdio.h>
#include <cmath>

#define mod 1000000007

using ll = long long int;
using namespace std;

struct Matrix {
    ll a, b, c, d;

    Matrix (ll A, ll B, ll C, ll D) {
        a = A;
        b = B;
        c = C;
        d = D;
    }

    Matrix operator * (const Matrix & other) {
        ll na = (a*other.a + b*other.c) % mod;
        ll nb = (a*other.b + b*other.d) % mod;
        ll nc = (c*other.a + d*other.c) % mod;
        ll nd = (c*other.b + d*other.d) % mod;
        return Matrix(na, nb, nc, nd);
    }
};

ll binMatrixExp (ll b) {
    Matrix res = Matrix(1, 0, 0, 1);
    Matrix f = Matrix(0, 1, 1, 1);
    while (b > 0) {
        if (b & 1) {
            res = (res*f);
        }
        b >>= 1;
        f = (f*f);
    }
    return res.c % mod;
}

int main() {
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", binMatrixExp(n));
}