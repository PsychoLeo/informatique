#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 1000*1000*1000

using namespace std;

vector<int> numbers;
bool P[MAX];

void pandigital (int i, string l="") {
    if (i <= 0) {
        int num = stoi(l);
        // printf("%d\n", num);
        if (P[num]) {
            printf("%d\n", num);
            exit(0);
        }
    }
    for (int n: numbers) {
        string c = to_string(n);
        // printf("%c\n", c);
        if (l.find(c) == string::npos) {
            pandigital(i-1, l+c);
        }
    }
}

void erathosthene() {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    for (int i=4; i<MAX; i+=2) {
        P[i] = false;
    }
    for (int i=3; i<MAX; i+=2) {
        if (P[i]) {
            for (int j=2*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
}

int main() {
    erathosthene();
    for (int i=9; i>1; i--) {
        for (int j=i; j>0; j--) {
            numbers.push_back(j);
        }
        pandigital(i);
        numbers.clear();
    }
    return 0;
}