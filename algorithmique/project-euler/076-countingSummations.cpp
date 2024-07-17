#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

#define ll long long int
#define MAX 25
#define SIZE 101
#define db(x,y) cout << #x << "=" << x << " | " << #y << "=" << y << endl;

using namespace std;

ll seqN;
ll seq[SIZE];

void countSum (int n, int max) {
    if (n < 1) {
        seqN++;
    }
    for (int i=1; i<=max; i++) {
        if (n >= i) {
            countSum(n-i, i);
        }
        else {
            break;
        }
    }
}

void printSeq() {
    for (int i=0; i<MAX; i++) {
        printf("%lld\n",  seq[i]);
    }
}

ll P(ll n) {
    if (n < 0) {
        return 0;
    }
    else if (n < SIZE && seq[n] != -1) {
        return seq[n];
    }
    else {
        ll sum = 0;
        for (int i=1; i<=n; i++) {
            ll fi = n-i*(3*i-1)/2;
            if (fi >= 0 && seq[fi] == -1) {
                seq[fi] = P(fi);
            }
            ll se = n-i*(3*i+1)/2;
            if (se >= 0 && seq[se] == -1) {
                seq[se] = P(se);
            }
            ll res = P(fi) + P(se);
            i % 2 == 1 ? sum += res: sum -= res;
        }
        db(n, sum);
        seq[n] = sum;
        return sum;
    }
}

int main() {
    /*
    Now, we use a recurrence relation invented by Euler (generating function)
    https://mathworld.wolfram.com/PartitionFunctionP.html
    P(n) = SUM(k=1 to n){(-1)^(k+1)[P(n-f(k)) + P(n-g(k))]}
    where f(n) = n*(3n-1)/2 & g(n) = n*(3n+1)/2
    We can remark that g(n) - f(n) = n, so g(n) = f(n) + n
    Therefore, P(n) = SUM(k=1 to n){(-1)^(k+1)*[P(n-f(k)) + P(n-k-f(k))]}
    */
//    fill(seq, seq+SIZE, -1);
//     seq[0] = seq[1] = 0;
//     for (int i=2; i<MAX; i++) {
//         seqN = 0;
//         countSum(i, i-1);
//         seq[i] = seqN;
//     }
//     printf("%lld\n", P(100));
    seqN = 0;
    countSum(100, 99);
    printf("%lld\n", seqN);
    // Runs in 3.5s
}