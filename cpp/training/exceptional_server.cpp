#include <stdio.h>
#include <iostream>
#include <unordered_set>
#define mod 2147483648

using namespace std;
using ll = unsigned long long int;

int main() {
    ll n, s, p, q, nbDiff = 1;
    scanf("%llu %llu %llu %llu",&n, &s, &p, &q);
    ll r = s;
    // printf("%llu %llu %llu %llu\n", n, s, p, q);
    unordered_set<ll> visited = {s};
    for (int i=1; i<n; i++) {
        // printf("Current value : %llu\n", r);
        r = (p*r + q) % mod;
        if (visited.find(r) == visited.end()) {
            nbDiff++;
            visited.emplace(r);
        }
    }
    printf("%llu\n", nbDiff);
}