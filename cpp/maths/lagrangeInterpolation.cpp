#include <cstdio>

using namespace std;

int main() {
    int n;
    printf("Enter the number of points : ");
    scanf("%d", &n);
    int p[n][2];
    for (int i=0; i<n; i++) {
        int x, y;
        printf("\nEnter x%d, y%d : ", i+1, i+1);
        scanf("%d %d", &x, &y);
        p[i][0] = x;
        p[i][1] = y;
    }
    
}