#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#define size 262144
#define inf 1000*1000*1000

using namespace std;

int r;
vector<int> l(size, inf);
int lastPos = 0;

int powerTwo (int a) {
    int j=1;
    while (j < a) {
        j *= 2;
    }
    return j;
}

void up(int i) {
    while (i > 1 && l[i/2] > l[i]) {
        swap(l[i/2], l[i]);
        i /= 2;
    }
}

void down(int i) {
    while ((l[i] > l[2*i] || l[i] > l[2*i+1]) && i<size) {
        if (l[2*i] <= l[2*i+1]) {
            swap(l[i], l[2*i]);
            i = 2*i;
        }
        else {
            swap(l[i], l[2*i+1]);
            i = 2*i+1;
        }
    }
}

int main() {
    scanf("%d", &r);
    for (int i=0; i<r; i++) {
        char c;
        scanf("%s", &c);
        if (c == 'I') {
            int x;
            scanf("%d", &x);
            lastPos++;
            l[lastPos] = x;
            up(lastPos);
        }
        else {
            if (l[1] < inf) {
                printf("%d\n", l[1]);
                l[1] = l[lastPos];
                l[lastPos] = inf;
                lastPos--;
                down(1);
            }
            else { // si le tas est vide
                printf("-\n");
            }
        }
    }
}