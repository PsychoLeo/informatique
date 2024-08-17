#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define N 100000
#define MOD 1000000

int p[N][N];

int main() {
    p[0][0] = 1;
    for (int n=1; n<N; ++n) {
        for (int k=1; k<=n; ++k) {
            p[n][k] = (p[n-k][min(k, n-k)] + p[n][k-1]) % MOD;
        }
        if (p[n][n] == 0) cout << n << endl;
    }
    cout << p[5][5] << endl;
    cout << p[6][6] << endl;
    cout << p[7][7] << endl;
}