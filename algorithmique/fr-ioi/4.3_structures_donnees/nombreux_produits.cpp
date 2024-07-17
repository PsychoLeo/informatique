#include <cstdio> 
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, nbOp;
    scanf("%d", &n);
    scanf("%d", &nbOp);
    vector<pair<int, int>> produits[20000];
    for (int i=0; i<nbOp; i++) {
        int prod, qte;
        long int peremption;
        scanf("%d%d%ld", &prod, &qte, &peremption);
        prod--;
        if (qte > 0) {
            produits[prod].push_back(make_pair(qte, peremption));
        }
        else {
            qte = -qte; // inverting the value (to make it positive)
            while ((!produits[prod].empty()) && (qte >= produits[prod][0].first)) {
                qte -= produits[prod][0].first;
                produits[prod].erase(produits[prod].begin());
            }
            if (!produits[prod].empty()) {
                produits[prod][0].first -= qte;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (!produits[i].empty()) {
            long int minProduct = (int) pow(10, 10); // value of infinity
            for (int j=0; j < produits[i].size(); j++) {
                if (produits[i][j].second < minProduct) {
                    minProduct = produits[i][j].second;
                }
            }
            printf("%ld\n", minProduct);
        }
        else {
            printf("0\n");
        }
    }
}