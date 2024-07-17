#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, r;
vector<int> tree;

int powerTwo (int a) {
    // corresponding power of 2
    int s = 1;
    while (s < a) {
        s *= 2;
    }
    return s;
}

void printTree() {
    int p = 1;
    for (int i=1; i<(int)tree.size(); i++) {
        printf("%d ", tree[i]);
        if (i == pow(2, p)-1) {
            printf("\n");
            p++;
        }
    }
}

int somme (int A, int B) {
    if (B == A) {
        return tree[B];
    }
    if (A % 2 == 1) {
        return tree[A] + somme(A+1, B);
    }
    if (B % 2 == 0) {
        return tree[B] + somme(A, B-1);
    }
    else {
        return somme (A/2, B/2);
    }
}

int main() {
    scanf("%d",&n);
    int d = powerTwo(n);
    tree.resize(2*d);
    fill(tree.begin(), tree.end(), 0);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        tree[i+d] = x;
    }
    for (int i=d-1; i>0; i--) {
        tree[i] = tree[2*i+1] + tree[2*i];
    }
    // printTree();
    scanf("%d",&r);
    for (int i=0; i<r; i++) {
        char op;
        scanf("%s", &op);
        int A, B;
        scanf("%d %d",&A, &B);
        if (op == 'S') { // afficher somme
            printf("%d\n", somme(A+d, B+d));
        }
        else { // modifier tree
            int delta = B-tree[A+d];
            int currIndex = A+d;
            while (currIndex > 0) {
                tree[currIndex] += delta;
                currIndex /= 2;
            }
        }
    }
    // printTree();
}