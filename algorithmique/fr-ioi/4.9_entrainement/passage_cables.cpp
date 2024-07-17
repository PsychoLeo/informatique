#include <stdio.h>
#include <vector>
#include <algorithm>

#define inf 1000*1000*1000
#define PB push_back
#define f first
#define s second

using namespace std;

int width, height, n;
vector<pair<int, int>> l;

void printArray() {
    for (auto p: l) {
        printf("%d %d | ", p.f, p.s);
    }
    printf("\n");
}

int main() {
    scanf("%d %d %d", &width, &height, &n);
    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int dy = y2-y1;
        l.PB(make_pair(x1, dy)); // ouverture d'un segment
        l.PB(make_pair(x2, -dy)); // fermeture d'un segment
    }
    sort(l.begin(), l.end());
    if (l[0].f > 0 || l.back().f < width) {
        printf("0\n");
        return 0;
    }
    // printArray();
    int minHeight = +inf;
    int currHeight = 0;
    int sz = l.size();
    for (int i=0; i<sz;) {
        int currx = l[i].f;
        // printf("%d\n", l[i].f);
        while (i < sz && l[i].f == currx) {
            currHeight += l[i].s;
            i++;
        }
        // printf("%d\n", currHeight);
        if (i != (int)l.size()) {
            minHeight = min(minHeight, currHeight);
        }
    }
    printf("%d\n", minHeight);
}