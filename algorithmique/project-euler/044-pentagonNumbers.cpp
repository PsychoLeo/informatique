#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 10*1000*1000
#define inf 1000*1000*1000

using namespace std;
bool isPentagon[MAX];
vector<int> pentag;

void pentagonNumbers () {
    for (int i=1, n=1; n < MAX; i++) {
        isPentagon[n] = true;
        pentag.push_back(n);
        n += 3*i+1;
    }
    printf("%d\n", (int)pentag.size());
    int minDiff = inf;
    for (int a: pentag) {
        for (int b: pentag) {
            if (isPentagon[abs(a-b)] && (a+b < MAX) && isPentagon[a+b]) {
                minDiff = min(minDiff, abs(a-b));
            }
        }
    }
    printf("%d\n", minDiff);
}

int main() {
    pentagonNumbers();
    return 0;
}