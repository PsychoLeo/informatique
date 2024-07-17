#include <stdio.h>
#include <cmath>
#include <vector>
#define MAX 1000

using namespace std;

int rand01() {
    int rd = rand() % 2;
    return rd;
}

int random(int end) {
    // recursive function to generate random number in range [0, end]
    int r = rand01();
    int mid = end/2;
    if (end <= 0) {
        return 0;
    }
    if (r == 0) {
        return random(mid);
    }
    else {
        if (end % 2 == 1) {
            return mid + 1 + random(mid);
        }
        else {
            return mid + 1 + random(mid-1);
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d",&a, &b);
    int d = b-a+1;
    // Programme pour trouver un nombre aléatoire entre a et b
    // en utilisant seulement un générateur de nombres aléatoires entre 0 et 1
    vector<int> count(d, 0);
    for (int i=0; i<MAX; i++) {
        int r = random(d-1);
        count[r]++;
    }
    for (int i=0; i<d; i++) {
        printf("%d : %d\n", i+a, count[i]);
    }
    printf("\n");
}