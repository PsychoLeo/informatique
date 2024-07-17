#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, r, d;
vector<bool> l;

int powerTwo (int a) {
    int res = 1;
    while (res < a) {
        res *= 2;
    }
    return res;
}

void printTree () {
    int pow2 = 1;
    for (int i=1; i<2*d; i++) {
        printf("%d ", (int)l[i]);
        if (i == pow(2, pow2)-1) {
            pow2++;
            printf("\n");
        }
    }
    printf("\n");
}

int valeurSousBorne (int maxEnd, int dep = 0, int end = d, int i = 1) {
    // printf("%d\t%d\t%d\t%d\n", maxEnd, dep, end, i);
    if (i >= d && i-d <= maxEnd && l[i]) {
        return i-d;
    }
    else if (dep <= maxEnd && l[i]) {
        int right = valeurSousBorne(maxEnd, (dep+end)/2, end, 2*i+1);
        if (right == -1) {
            return valeurSousBorne(maxEnd, dep, (dep+end)/2, 2*i);
        }
        else {
            return right;
        }
    }
    return -1;
}

void remonterArbre (int i) {
    int neighbor = (i%2==0) ? i+1: i-1;
    if (neighbor == 0 || l[neighbor]) {
        return;
    }
    else {
        l[i/2] = l[i] ? true: false;
        remonterArbre(i/2);
    }
}

int main() {
    scanf("%d %d",&n, &r);
    d = powerTwo(n);
    l.resize(2*d, 0);
    for (int j=0; j<r; j++) {
        char c;
        scanf("%s", &c);
        if (c == 'M') {
            int pos, val;
            scanf("%d %d", &pos, &val);
            l[pos+d] = (bool)val;
            remonterArbre(pos+d);
            // printTree();
        }
        else {
            // printTree();
            int maxEnd;
            scanf("%d", &maxEnd);
            printf("%d\n", valeurSousBorne(maxEnd));
        }
    }
    // printTree();
}