#include <stdio.h>
#include <vector>
#define goal 4
#define MAX 10*1000*1000

using namespace std;

int P[MAX];

void erathosthene() {
    fill(P, P+MAX, 0);
    for (int i=4; i<MAX; i+=2) {
        P[i]++;
    }
    for (int i=3; i<MAX; i+=2) {
        if (!P[i]) {
            for (int j=2*i; j<MAX; j+=i) {
                P[j]++;
            }
        }
    }
}   

int main() {
    erathosthene();
    int len = 0;
    for (int i=0; i<MAX; i++) {
        if (P[i] == goal) {
            len++;
        }
        else {
            len = 0;
        }
        if (len == goal) {
            printf("%d\n", i-3);
            return 0;
        }
    }
}