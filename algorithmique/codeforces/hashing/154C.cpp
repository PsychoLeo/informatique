#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long
#define nl '\n'
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll, ll>
#define MAX (ll)1e6+5

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // Combine the two hashes
    }
};

const ll mod = 1e9+7;
ll pow2[MAX] = {1};
ll pow3[MAX] = {1};
ll hash[MAX];

void fillPow() {
    ll pow2v = 1;
    ll pow3v = 1;
    for (ll i=0; i<MAX; ++i) {
        pow2[i] = pow2v;
        pow3[i] = pow3v;
        pow2v = ((pow2v * 2) % mod + mod) % mod;
        pow3v = ((pow3v * 3) % mod + mod) % mod;
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n+1);
    fillPow();
    for (ll i=0; i<m; ++i) {
        ll a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    vector<pll> hash;
    for (ll i=0; i<n; ++i) {
        pll h = mp(0, 0);
        for (ll x: g[i]) {
            h.fi = ((h.fi + pow2[x]) % mod + mod) % mod;
            h.se = ((h.se + pow3[x]) % mod + mod) % mod;
        }
        hash.push_back(h);
    }
    // for (ll i=0; i<n; ++i) cout << "Node " << i+1 << " : " << hash[i] << endl;
    ll result = 0;
    unordered_map<pll, ll, pair_hash> hash_v;
    for (pll h : hash) {
        if (hash_v.find(h) == hash_v.end()) {
            hash_v[h] = 1;
        }
        else (hash_v[h]++);
    }
    // we now consider people to be their own friends
    for (ll i=0; i<n; ++i) {
        hash[i].fi = ((hash[i].fi + pow2[i]) % mod + mod) % mod;
        hash[i].se = ((hash[i].se + pow3[i]) % mod + mod) % mod;
    }
    unordered_map<pll, ll, pair_hash>::iterator it;
    for (it = hash_v.begin(); it != hash_v.end(); it++) {
        result += (it->second)*(it->second -1)/2;
    }
    // for (ll i=0; i<n; ++i) cout << "Node " << i+1 << " : " << hash[i] << endl;
    hash_v.clear();
    for (pll h : hash) {
        if (hash_v.find(h) == hash_v.end()) {
            hash_v[h] = 1;
        }
        else (hash_v[h]++);
    }
    for (it = hash_v.begin(); it != hash_v.end(); it++) {
        result += (it->second)*(it->second -1)/2;
    }
    cout << result << endl;
    return 0;
}