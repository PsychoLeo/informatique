#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long

const ll mod = (int)(1e9+7);

ll binPow(int n) {
    // Calcule 2^n % mod
    ll p = 2;
    ll r = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            r = (r*p)%mod;
        }
        n /= 2;
        p = (p*p)%mod;
    }
    return r;
}

ll solve (int n, vector<int> a, vector<int> b) {
    // on calcule 2^nbOrbites
    int nbOrbites = 0;
    vector<int> p(n);
    for (int i=0; i<n; ++i) {
        p[a[i]-1] = i;
    }
    vector<bool> vis(n, false);
    for (int i=0; i<n; ++i) {
        int j=i, ai=a[i]-1, bi=b[i]-1;
        if (!vis[j]) {
            ++nbOrbites;
            do {
                vis[j] = true;
                j = p[bi];
                bi = b[j]-1;
                ai = a[j]-1;
            } while (j != i);
        }
    }
    return binPow(nbOrbites);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin >> t;
    //cout << binPow(4) << endl;
    //cout << binPow(10) << endl;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); vector<int> b(n);
        for (int i=0; i<n; ++i) cin >> a[i];
        for (int i=0; i<n; ++i) cin >> b[i];
        cout << solve(n, a, b) << "\n";
    }
}