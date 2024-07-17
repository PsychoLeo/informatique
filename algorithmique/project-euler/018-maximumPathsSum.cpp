#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define size 100
#define inf 1000*1000*1000
vector<vector<int>> dp(size, vector<int>());

int main() {
    // Programmation dynamique
    int x;
    scanf("%d", &x);
    dp[0].push_back(x);
    for (int i=1; i<size; i++) {
        int nbInput = 0;
        for (int j=0; j<i+1; j++) {
            int x;
            scanf("%d", &x);
            int maxPred = dp[i-1][j];
            if (j-1 >= 0) {
                maxPred = max(maxPred, dp[i-1][j-1]);
            }
            dp[i].push_back(x+maxPred);
        }
    }
    int maxi = -inf;
    for (int i=0; i<size; i++) {
        maxi = max(maxi, dp[size-1][i]);
    }
    printf("%d\n", maxi);
}