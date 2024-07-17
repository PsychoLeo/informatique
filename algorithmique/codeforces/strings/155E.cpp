#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long
#define MAX (ll)1e6+5

const ll mod = 10000000019;
ll pow2[MAX] = {1};
ll hash[MAX];

void fillPow2() {
    ll pow = 1;
    for (ll i=0; i<MAX; ++i) {
        pow2[i] = pow;
        pow = ((pow * 2) % mod + mod) % mod;
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n+1);
    fillPow2();
    for (ll i=0; i<m; ++i) {
        ll a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    vector<ll> hash;
    for (ll i=0; i<n; ++i) {
        ll h = 0;
        for (ll x: g[i]) {
            h = ((h + pow2[x]) % mod + mod) % mod;
        }
        hash.push_back(h);
    }
    // for (ll i=0; i<n; ++i) cout << "Node " << i+1 << " : " << hash[i] << endl;
    ll result = 0;
    unordered_map<ll, ll> hash_v;
    for (ll h : hash) {
        if (hash_v.find(h) == hash_v.end()) {
            hash_v[h] = 1;
        }
        else (hash_v[h]++);
    }
    // we now consider people to be their own friends
    for (ll i=0; i<n; ++i) {
        hash[i] = ((hash[i] + pow2[i]) % mod + mod) % mod;
    }
    unordered_map<ll, ll>::iterator it;
    for (it = hash_v.begin(); it != hash_v.end(); it++) {
        result += (it->second)*(it->second -1)/2;
    }
    // for (ll i=0; i<n; ++i) cout << "Node " << i+1 << " : " << hash[i] << endl;
    hash_v.clear();
    for (ll h : hash) {
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