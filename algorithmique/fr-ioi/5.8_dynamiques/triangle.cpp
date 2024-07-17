#include <stdio.h>
#include <algorithm>

#define SIZE 100

using namespace std;

int triangle[SIZE][SIZE] = {0};
int n;

int main() {
    scanf("%d",&n);
    int x;
    scanf("%d",&x); // first line
    triangle[0][0] = x;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            int x;
            scanf("%d",&x);
            if (j > 0) {
                triangle[i][j] = x+max(triangle[i-1][j], triangle[i-1][j-1]);
            }
            else {
                triangle[i][j] = x+triangle[i-1][j];
            }
        }
    }
    int maximum = 0;
    for (int i=0; i<n; i++) {
        if (triangle[n-1][i] > maximum) {
            maximum = triangle[n-1][i];
        }
    }
    printf("%d\n", maximum);
}