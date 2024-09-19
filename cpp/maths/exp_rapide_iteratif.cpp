#include <iostream>

using namespace std;

#define ll long long

#define MOD (ll)1e9+7

ll binExp(ll a, ll n) {
    ll r = 1;
    while (n) {
        if (n % 2) r = (r * a) % MOD;
        n = n/2;
        a = (a * a) % MOD;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, n; cin >> a >> n; 
    cout << binExp(a, n) << "\n";
}