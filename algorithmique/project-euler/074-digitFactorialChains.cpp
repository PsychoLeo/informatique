#include <cstdio>
#include <cmath>
#include <unordered_set>
#include <vector>

#define SZ 2200000
#define MAX 1000*1000

int nxt[SZ] = {};
int fact[10];

using namespace std;

void fillFactorials() {
    int prod = 1;
    fact[0] = 1;
    for (int i=1; i<10; i++) {
        prod *= i;
        fact[i] = prod;
    }
}

int sumDigitsFactorial(int n) {
    int nv = 0;
    while (n > 9) {
        nv += fact[n%10];
        n /= 10;
    }
    return nv + fact[n];
}

int main() {
    fillFactorials();
    int r = 0;
    for (int i=1; i<MAX; i++) {
        int val = i;
        unordered_set<int> visited;
        int lenCycle = 0;
        while (visited.find(val) == visited.end()) {
            visited.emplace(val);
            if (nxt[val] == 0) {
                int newVal = sumDigitsFactorial(val);
                nxt[val] = newVal;
                val = newVal;
            }
            else {
                val = nxt[val];
            }
            ++lenCycle;
        }
        if (lenCycle == 60) {
            r++;
        }
    }
    printf("%d\n", r);
}