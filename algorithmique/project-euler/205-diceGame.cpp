#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
#define ld long double

int main() {
    srand((unsigned)time(0));
    int MAX = 100*1000*1000;
    int p[4] = {1, 2, 3, 4};
    int c[6] = {1, 2, 3, 4, 5, 6};
    int r = 0;
    for (int i=0; i<MAX; i++) {
        int sP = 0, sC = 0;
        for (int i=0; i<9; i++) {
            sP += p[rand()%4];
        }
        for (int j=0; j<6; j++) {
            sC += c[rand()%6];
        }
        r += (sP > sC);
    }
    ld x = (ld)r/MAX;
    printf("%llf\n", x);
}   