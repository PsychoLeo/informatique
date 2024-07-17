#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, nbIntervalles;
vector<int> powersTwo;
vector<int> l;

void printArbre() {
    int p = 1;
    for (int i=1; i<(int)l.size(); i++) {
        printf("%d ", l[i]);
        if (i == pow(2, p)-1) {
            p++;
            printf("\n");
        }
    }
}

int maximumEntre (int A, int B) {
    // A et B sont des indices dans l'arbre et non dans la liste
    if (B-A < 2) {
        return max(l[B], l[A]);
    }
    if (A % 2 == 1) {
        return max(l[A], maximumEntre(A+1, B));
    }
    if (B % 2 == 0) {
        return max(l[B], maximumEntre(A, B-1));
    }
    else {
        return maximumEntre(A/2, B/2);
    }
}

void initPowersTwo () {
    for (int i=0; i<18; i++) {
        powersTwo.push_back(pow(2, i));
    }
}

int main() {
    initPowersTwo();
    scanf("%d", &n);
    int k=0;
    while (powersTwo[k] < n) {
        k++;
    }
    int d = powersTwo[k]; // size of the list
    // printf("%d\n", d);
    l.resize(2*d); // size of the tree (2**(n+1)-1)
    fill(l.begin(), l.end(), 0);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        l[i+d] = x;
    }
    for (int i=d-1; i>0; i--) {
        l[i] = max(l[2*i], l[2*i+1]);
    } // initialisation des prédecesseurs
    // printArbre();
    int r;
    scanf("%d", &r);
    for (int i=0; i<r; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", maximumEntre(A-1+d, B-1+d));
    }
}