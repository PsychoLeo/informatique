#include <stdio.h>
#include <vector>
#define MP make_pair
#define F first
#define S second

using ll = unsigned long long int;
using namespace std;

pair<int, ll> t;
pair<int, ll> p;
pair<int, ll> h;

void changeRank () {
    // Relations found by doing u(n+1) - u(n)
    t.F++;
    t.S += t.F;
    p.S += 3*p.F + 1;
    p.F++;
    h.S += 4*h.F + 1;
    h.F++;
}

int main() {
    t = MP(285, 40755);
    p = MP(165, 40755);
    h = MP(143, 40755);
    changeRank();
    while (t.S != p.S && p.S != h.S) {
        while (t.S < p.S || t.S < h.S) {
            t.F++;
            t.S += t.F;
        }
        while (p.S < t.S || p.S < h.S) {
            p.S += 3*p.F + 1;
            p.F++;
        }
        while (h.S < p.S || h.S < t.S) {
            h.S += 4*h.F + 1;
            h.F++;
        }
    }
    printf("%llu\n", p.S);
}