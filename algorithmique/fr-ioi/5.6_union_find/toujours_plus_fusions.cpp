#include <stdio.h>
#include <vector>
#include <iostream>
#define SIZE 100000 // taille maximale

using namespace std;

int entreprise[SIZE];
int n, r;
vector<vector<int>> members;

int main () {
    scanf("%d %d", &n, &r);
    for (int i=0; i<n; i++) {
        entreprise[i] = i; // chacun appartient à sa propre entreprise
        vector<int> v = {i};
        members.push_back(v);
    }
    for (int i=0; i<r; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        if (entreprise[A] != entreprise[B]) { // il ne font pas partie de la même entreprise
            // printf("Personnes : %d %d | Entreprises : %d %d\n", A, B, entreprise[A], entreprise[B]);
            printf("%d %d\n", A, B); // il y a fusion des 2 entreprises
            for (int e: members[B]) {
                entreprise[e] = entreprise[A];
            }
            members[A].insert(members[A].end(), members[B].begin(), members[B].end());
            members[B].clear();
        }
    }
}