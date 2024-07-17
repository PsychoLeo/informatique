#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int l[n];
    bool visited[n] = {false};
    for (int i=0; i<n; i++) {
        int currElem;
        scanf("%d", &currElem);
        l[i] = currElem;
    }
    int i = n-1, r = 0, numberFind=5;
    while (i >= 0) {
        if (!visited[i] && l[i] == numberFind) {
            numberFind--;
            visited[i] = true;
            if (numberFind == 0) {
                r++;
                numberFind = 5;
                i = n-1;
            }
        }
        else {
            i--;
        }
    }
    printf("%d\n", r);
}