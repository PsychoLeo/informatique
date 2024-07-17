#include <cmath>
#include <stdio.h>
#include <vector>

#define n 100
#define nbQuestions 10000

using namespace std;

int cheatingDetection () {
    double sumDelta = 0;
    
}

int main() {
    int t, p;
    scanf("%d %d", &t, &p);
    for (int i=0; i<t; i++) {
        printf("Case #%d: %d\n", t+1, cheatingDetection());
    }
}