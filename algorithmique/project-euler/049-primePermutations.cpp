#include <stdio.h>
#include <vector>
#include <string>
#include <map>

#define MAX 10*1000
#define MIN 1000
#define perm 24

using namespace std;

bool P[MAX];
// bool checkedNumber[MAX];
vector<int> currPermutation;
// string nbStr;
// map<char, int> nbComposition;

void fillPrimes () {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    for (int i= 4; i<MAX; i+=2) {
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

// void permutations (string currStr = "", int nbElem=0) {
//     if (nbElem == perm) {
//         return;
//     }
//     for (char c: nbStr) {
//         return;
//     }
// }

bool isPermutation(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    map<char, int> charCountA;
    map<char, int> charCountB;
    for (char c1: s1) {
        if (charCountA.find(c1) == charCountA.end()) {
            charCountA[c1] = 1;
        }
        else {
            charCountA[c1]++;
        }
    }
    for (char c2: s2) {
        if (charCountB.find(c2) == charCountB.end()) {
            charCountB[c2] = 1;
        }
        else {
            charCountB[c2]++;
        }
    }
    for (char c: s1) {
        if(charCountB.find(c) == charCountB.end() || charCountB[c] != charCountA[c]) {
            return false;
        }
    }
    return true;
}

int main() {
    fillPrimes();
    // for (int n=MIN; n<MAX; n++) {
    //     if (P[n] && !checkedNumber[n]) {
    //         nbStr = to_string(n);
    //         permutations();
    //         // Check if 2 permutations are prime and mark them
    //         return 0;
    //     }
    //     currPermutation.clear();
    // }
    for (int i=MIN; i<MAX; i++) {
        if (P[i] && i+3330 < MAX && P[i+3330] && i+6660 < MAX && P[i+6660]) {
            if (isPermutation(i, i+3330) && isPermutation(i, i+6660)) {
                printf("%d %d %d\n", i, i+3330, i+6660);
            }
        }
    }
}