#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 80
#define ll long long int

using namespace std;

int l[MAX][MAX];
ll minPath[MAX][MAX];

int main() {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            scanf("%d", &l[i][j]);
        }
    }
    ll sumFirstRow = 0, sumFirstCol = 0;
    for (int i=0; i<MAX; i++) {
        sumFirstRow += l[0][i];
        sumFirstCol += l[i][0];
        minPath[0][i] = sumFirstRow;
        minPath[i][0] = sumFirstCol;
    }
    for (int i=1; i<MAX; i++) {
        for (int j=1; j<MAX; j++) {
            minPath[i][j] = min(minPath[i-1][j], minPath[i][j-1]) + l[i][j];
        }
    }
    printf("%lld\n", minPath[MAX-1][MAX-1]);
}