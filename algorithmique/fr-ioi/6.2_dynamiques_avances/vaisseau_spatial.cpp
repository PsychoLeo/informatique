#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1'000'000'000
#define MIN (-MAX)
#define W 500 // nombre maximal de colonnes
#define H 20'000 // nombre maximal de lignes

int dp[H][W] = {0};
int mv[H][W] = {0};
int N, M, P;

void fillDP() {
    for (int i=N-2; i>=0; --i) {
        if (dp[i+1][0] == MIN) {
            if (dp[i+1][1] == MIN) dp[i][0] = MIN; // on ne peut pas accéder à la case
            else {
                dp[i][0] = dp[i+1][0]; 
                mv[i+1][0] = -1;
            }
        }
        else {
        }
        for (int j=1; j<M-1; ++j) {
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> P;
    for (int j=0; j<M; ++j) {
        if (j != P) dp[N-1][j] = MIN;
    }
    fillDP();
    // printf("%lu\n", sizeof(dp));
}

/*
Idée : garder une ligne DP
Considérer seulement les bonus qu'on prend/ leurs positions et à partir de cela

*/