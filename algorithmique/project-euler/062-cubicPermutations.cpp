using namespace std;

#include <cstdio>
#include <vector>

#define llu unsigned long long int
#define MAX 1000*1000

short cubes[MAX][11]; // index 10 used for the length of the number

void initCubes() {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<11; j++) {
            cubes[i][j] = 0;
        }
    }
}

void fillCubes() {
    initCubes();
    for (int i=0; i<MAX;i++) {
        // for (int j=0; j<10; j++) {
        //     cubes[i][j] = 0;
        // }
        llu cube = (llu)i*i*i;
        short sz = 1;
        while (cube >= 10) {
            cubes[i][cube%10]++;
            cube /= 10;
            sz++;
        }
        cubes[i][cube]++;
        cubes[i][10] = sz;
    }
}

int main() {
    fillCubes();
    for (int i=0; i<MAX; i++) {
        vector<int> permutations = {i};
        for (int j=i+1; j<MAX && cubes[j][10] == cubes[i][10]; j++) {
            short common = 0;
            for (int k=0; k<10; k++) {
                if (cubes[i][k] == cubes[j][k]) {
                    common++;
                }
                else {
                    break;
                }
            }
            if (common == 10) {
                permutations.push_back(j);
            }
        }
        if (permutations.size() >= 5) {
            for (int x: permutations) {
                printf("%d ", x);
            }
            printf("\n");
            return 0;
        }
    }
}