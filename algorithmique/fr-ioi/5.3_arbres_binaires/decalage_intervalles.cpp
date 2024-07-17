#include <stdio.h>
#include <vector>
#include <cmath>
#define size 262144 // 2^18

using namespace std;

int h, r, d;
int l[size] = {0};

void printTree () {
    int currPow = 1;
    for (int i=1; i<2*d; i++) {
        printf("%d ", l[i]);
        if (i == pow(2, currPow)-1) {
            currPow++;
            printf("\n");
        }
    }
}

void ajouterIntervalle(int dep, int end, int val) {
    if (dep == end) {
        l[dep] += val;
        return;
    }
    if (dep % 2 == 1) {
        l[dep] += val;
        ajouterIntervalle(dep+1, end, val);
    }
    else if (end % 2 == 0) {
        l[end] += val;
        ajouterIntervalle(dep, end-1, val);
    }
    else {
        ajouterIntervalle(dep/2, end/2, val);
    }
}

int main() {
    scanf("%d %d", &h, &r);
    d = pow(2, h);
    // printTree();
    for (int i=0; i<r; i++) {
        char c;
        scanf("%s", &c);
        if (c == 'D') { // ajouter quantité
            int A, B, val;
            scanf("%d %d %d", &A, &B, &val);
            // printf("%d %d %d\n", A, B, val);
            ajouterIntervalle(A+d, B+d, val);
            // printTree();
        }
        else {
            int j, sum = 0;
            scanf("%d", &j);
            j += d;
            while (j > 0) {
                sum += l[j];
                j /= 2;
            }
            printf("%d\n", sum);
        }
    }
}