#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#define N 1505
#define ll long long int

const ll m = 1e9+9;
const ll p = 31;

ll bad[N] = {0}; // bad[i] contient le nombre de "bad" entre O et i (inclus)
ll prefix_hash[N] = {0};
ll inverseModuloM[N] = {1}; // inv[i] = inverse de p^i modulo m
ll prefix[N] = {1}; // prefix[i] = (p^0*p^1*...*p^i) % m
ll suffix[N] = {1}; // suffix[i] = (p^(N-1)*p^(N-2)*...*p^i) % m

ll prod(ll a, ll b);

//! OK
ll binExp(ll a, ll x) {
    // calcul de a^x % m pour l'utiliser avec a^(m-2) = a^-1 mod m (car m est premier)
    ll pow = a;
    ll res = 1;
    while (x > 0) {
        if (x % 2 == 1) {
            res = prod(res, pow);
        }
        x = x/2;
        pow = prod(pow, pow);
    }
    return res;
}

ll prod(ll a, ll b) {
    return ((a * b) % m + m) % m;
}

void fillInverseModuloM() {
    ll pow = 1;
    // on construit le tableau des produits préfixes
    for (ll i=1; i<N; ++i) {
        pow = prod(pow, p);
        prefix[i] = prod(prefix[i-1], pow);
    }
    // on construit le tableau des produits suffixes
    pow = binExp(p, N-1);
    ll invP = binExp(p, m-2); // inverse de p modulo m (Fermat)
    suffix[N-1] = pow;
    for (ll i=N-2; i>=0; --i) {
        pow = prod(pow, invP);
        suffix[i] = prod(suffix[i+1], pow);
    }
    // on construit le tableau des inverses à l'aide de la formule
    ll invProd = binExp(prefix[N-1], m-2); // inverse de tout le produit
    // cout << "Inverse du produit : " << invProd << endl;
    inverseModuloM[N-1] = prod(prefix[N-2], invProd);
    for (ll i=1; i<N-1; ++i) {
        ll tmp = prod(prefix[i-1], suffix[i+1]);
        inverseModuloM[i] = prod(tmp, invProd);
    }
}

void fillPrefixHash(string s) {
    ll h = 0;
    ll pow = 1;
    ll i=0;
    for (char c : s) {
        h = (h + prod(c-'a'+1, pow)) % m;
        prefix_hash[i] = h;
        pow = prod(pow, p);
        ++i;
    }
}

ll numberGoodSubstrings(ll n, ll k, string& s) {
    ll c = 0; // counter
    // for (ll i=0; i<n; ++i) cout << prefix_hash[i] << " ";
    // cout << "Tableau des prefix :" << endl;
    // for (ll i=0; i<N; ++i) cout << prefix[i] << " ";
    // cout << endl;
    // cout << "Tableau des suffix : " << endl;
    // for (ll i=0; i<N; ++i) cout << suffix[i] << " ";
    // cout << endl;
    // cout << "Tableau des inverses de p^i : " << endl;
    // for (ll i=0; i<N; ++i ) cout << inverseModuloM[i] << " ";
    // cout << endl; 
    // cout << "Tableau des prefix_hash : " << endl;
    // for (ll i=0; i<N; ++i) cout << prefix_hash[i] << " ";
    for (ll len=1; len<=n; ++len) { // on itère sur la longueur du préfixe
        unordered_set<ll> hash_list;
        for (ll dep=0; dep<=n-len; ++dep) {
            ll depNotBad = (dep==0) ? 0 : bad[dep-1];
            if (bad[dep+len-1]-depNotBad <= k) {
                ll prefixHashDep = (dep == 0) ? 0 : prefix_hash[dep-1];
                ll h = prod(prefix_hash[dep+len-1]-prefixHashDep, inverseModuloM[dep]);
                // cout << endl;
                // cout << "Substring : " << s.substr(dep, len) << " | Hash value : " << h << endl;
                // cout << "Inverse de p^dep : " << inverseModuloM[dep] << endl;
                hash_list.insert(h);
            }
        }
        c += hash_list.size();
    }
    return c;
}

int main() { 
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << binExp(p, 3) << endl;
    string s, good; cin >> s; cin >> good;
    ll k; cin >> k;
    fillInverseModuloM();
    fillPrefixHash(s);
    ll n = s.size();
    ll c = 0;
    for (ll i=0; i<n; ++i) {
        if (good[s[i]-'a'] == '0') ++c;
        bad[i] = c;
    }
    ll r = numberGoodSubstrings(n, k, s);
    cout << r << endl;
}