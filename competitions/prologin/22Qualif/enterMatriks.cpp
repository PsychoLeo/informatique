#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <limits>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define ll long long int

int x, n;
vi L;
vector<ll> Ecc;

/*
==> On crée un tableau des effectifs cumulés croissants, ce qui nous permettra
de savoir plus facilement s'il est possible d'obtenir une sous-liste de L
telle que la somme de ses éléments divise X. En effet, la somme des éléments d'une sous-liste L[i:j+1] vaut Ecc[j]-Ecc[i].

==> On itère les couples (i, j) avec i>j de Ecc
On cherche tous ceux tels que a = Ecc[i]-Ecc[j] divise X. On marque M[a] = (i, j) dans une map si a n'a pas été trouvé, sinon on prend le maximum en i-j et si égalité le maximum en Ecc[i]-Ecc[j]. 

==> Il faut trouver 2 nombres a, b tels que a*b = X et dont la somme des longueurs (contenue dans la map M) est maximale (càd i-j+k-l est maximale). On utilise une fonction qui génère tous les couples (a, b) tels que a*b = X (positifs ou négatifs) et on itère dans ceux-ci en regardant si on avait trouvé a et b avant.

==> On affiche la "meilleure" sous-liste (L[i:j] ou L[k:l]) en premier (la plus grande et si égalité, celle dont la somme des éléments est maximale)
*/

vector<pii> factors(int a) {
    // Trouve les couples (x, y) tels que x*y=a (positifs ou négatifs) -> complexité O(sqrt(a))
    vector<pii> r;
    for (int i=1; i< (int)(sqrt(abs(a))) + 1; ++i) {
        if (a % i == 0) {
            r.push_back(make_pair(i, a/i));
            r.push_back(make_pair(-i, -a/i));
        }
    }
    return r;
}

void printResult(int a, int b, int c, int d) {
    // Affiche le résultat final
    for (int i=a; i<b-1; ++i) {
        printf("%d ", L[i]);
    }
    printf("%d\n", L[b-1]);
    for (int i=c; i<d-1; ++i) {
        printf("%d ", L[i]);
    }
    printf("%d\n", L[d-1]);
}

void getInput() {
    scanf("%d %d", &x, &n);
    Ecc.push_back(0); // on considère aussi les sommes commençant au premier élément de L
    for (int i=0; i<n; ++i) {
        int p; scanf("%d", &p);
        L.push_back(p);
        Ecc.push_back(Ecc[i] + (ll)p);
    }
}

void solveNull() {
    // On traite le cas x = 0 à part
    // On prend L et la plus grande sous-liste dont la somme vaut 0
    pii M;
    M.first = 0; M.second = 0;
    bool found = false;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<i; ++j) {
            ll a = Ecc[i] - Ecc[j];
            if (a == 0) {
                found = true;
                if (i-j > M.first-M.second) {
                    M.first = i; M.second = j;
                }
            }
        }
    }
    if (!found) {
        printf("IMPOSSIBLE\n"); return;
    }
    printResult(0, L.size(), M.second, M.first); // on renvoie L et la plus longue sous-liste de L dont la somme des élément vaut 0
}   

int main() {
    // Algorithme en O(n^2)  
    getInput();
    if (x == 0) {
        solveNull(); return 0;
    }
    map<ll, pii> M;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<i; ++j) {
            ll a = Ecc[i] - Ecc[j]; // somme des termes de la sous-liste L[j:i]
            if ((a != 0) && (x%a == 0)) { // s'il existe une sous-liste dont la somme des éléments divise X
                if (M.find(a) == M.end()) { 
                    M.emplace(a, make_pair(i, j));
                }
                else if (i-j > M[a].first-M[a].second) {
                    M[a].first = i;
                    M[a].second = j;
                }
                else if (M[a].first-M[a].second == i-j) {
                    if (a > Ecc[M[a].first] - Ecc[M[a].second]) {
                        M[a].first = i;
                        M[a].second = j;
                    }
                }
            }
        }
    }
    ll max = numeric_limits<ll>::min();
    ll bestA, bestB;
    bool hasChanged = false;
    for (pii p: factors(x)) {
        ll a = p.first, b = p.second; // pour deux facteurs a, b tq a*b = x
        if ((M.find(a) != M.end()) && (M.find(b) != M.end())) { // s'il existe deux sous-listes de L telles que leur somme vale a et b
            if (M[a].first-M[a].second+M[b].first-M[b].second > max) {
                bestA = a; bestB = b; max = M[a].first-M[a].second+M[b].first-M[b].second;
                hasChanged = true; // on a bien trouvé une clé
            }
        }
    }
    if (!hasChanged) { // s'il n'y a pas de clé possible
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int i = M[bestA].first, j = M[bestA].second, k = M[bestB].first, l = M[bestB].second;
    int depA, endA, depB, endB;
    if ((i-j > k-l) || ((i-j == k-l) && (Ecc[i]-Ecc[j] >= Ecc[k]-Ecc[l]))) {
        depA = j; endA = i;
        depB = l; endB = k;
    }
    else {
        depB = j; endB = i;
        depA = l; endA = k;
    }
    printResult(depA, endA, depB, endB);
    return 0;
}