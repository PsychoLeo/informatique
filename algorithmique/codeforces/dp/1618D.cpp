#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <random>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<(b); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T> long long sum(const T& a){ return accumulate(a.begin(), a.end(), 0LL); }
template<class T> auto min(const T& a){ return *min_element(a.begin(), a.end()); }
template<class T> auto max(const T& a){ return *max_element(a.begin(), a.end()); }


typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvl;

#define DEBUG true
#ifdef DEBUG
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 

ll minscore(int n, int k, vi &a) {
    ll c = 0;
    for (int i=0; i<n-2*k; ++i) c += a[i];
    for (int i=n-2*k; i<n;) {
        int j = i+1;
        while (j < n && a[j] == a[i]) ++j;
        if (j-i > k) {
            c += j-i-k;
        }
        i = j;
    }
    return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n, k; cin>> n >> k;
        vi a(n); rep(i, 0, n) cin >> a[i];
        sort(all(a));
        cout << minscore(n, k, a) << "\n";
	}
	return 0;
}

/*
On montre sur papier qu'il est optimal de virer les 2k plus grands éléments d'une manière ou d'une autre
Quelle est donc la manière optimale de les mettre par paires (x, y) en minimisant la somme des x/y ?

On doit trouver mieux que 1 de coût par paire (qui s'obtient facilement en premier chaque élément avec 
son prédecesseur)
Si xi != xj, on peut obtenir 1. 
On doit donc obtenir une configuration qui maximise le nombre de paires distinctes

Si aucun nombre a la majorité, on considère l'algorithme suivant : les nombres semblables sont classés
ensemble et à chaque fois on apparie un élement avec un élément de l'ensemble ayant le plus d'éléments actuellement (hormis celui
dont l'élément provient)
Cela nous donne des paires distinctes, donc le résultat est 0

Si un nombre a la majorité, notons m > k le nombre de fois qu'il apparaît.
Le résultat est alors (2k-m) * 0 + (m - (2k-m))/2 * 1 = m-k
*/
