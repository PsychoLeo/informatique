#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int l[n];
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        l[i] = x-1;
    }
    int r=0;
    int dist[n];
    fill(dist, dist+n, -1);
    bool hasCycle[n];
    for (int i=0; i<n; i++) {
        if (!hasCycle[i]) {
            hasCycle[i] = true;
            int cycleSize = 1;
            int toReach = i;
            int currPos = l[i];
            while (currPos != toReach) {
                hasCycle[currPos] = true;
                cycleSize++;
                currPos = l[currPos];
            }
            r = max(r, cycleSize);
        }
    }
    printf("%d\n", r);
}