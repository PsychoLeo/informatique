#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, r;
    scanf("%d %d", &h, &r);
    int size = pow(2, h+1);
    vector<int> l(size);
    fill(l.begin(), l.end(), 0);
    int d = pow(2, h);
    for (int i=0; i<r; i++) {
        int a, index;
        scanf("%d %d", &index, &a);
        l[index+d] = a;
        int currIndex = index+d;
        while (currIndex > 0) { // on remonte en log2(n)
            if (currIndex % 2) {
                l[currIndex/2] = max(l[currIndex], l[currIndex-1]);
            }
            else {
                l[currIndex/2] = max(l[currIndex], l[currIndex+1]);
            }
            currIndex /= 2;
        }
        printf("%d\n", l[1]);
    }
}