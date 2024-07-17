#include <string>
#include <stdio.h>
#include <cmath>
#define MAX 1000*1000

using namespace std;

int powTen[7] = {1, 10, 100, 1000, 10*1000, 100*1000, 1000*1000};

bool in (int x) {
    for (int pow: powTen) {
        if (x == pow) {
            return true;
        }   
    }
    return false;
}

int main() {
    int n = 1;
    int prod = 1;
    for (int i=1; n<MAX; i++) {
        string currNumber = to_string(i);
        for (char c: currNumber) {
            if (in(n)) {
                prod *= (c-'0');
            }
            n++;
        }   
    }
    printf("%d\n", prod);
}