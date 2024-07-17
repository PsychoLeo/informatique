#include <stdio.h>
#include <string>
#define MAX 10*1000

using namespace std;

string pandigitalPossible (int x) {
    bool foundNumbers[10];
    string nul = "0";
    fill(foundNumbers, foundNumbers+10, false);
    string res = to_string(x) + to_string(2*x);
    int n = 3;
    while (res.size() < 9) {
        res += to_string(n*x);
        n++;
    }
    for (char c: res) {
        if (c == '0') {
            return nul;
        }
        if (foundNumbers[c-'0']) {
            return nul;
        }
        foundNumbers[c-'0'] = true;
    }
    return res.size() != 9 ? nul: res;
}

int main() {
    // On déduit facilement de l'énoncé que x < 10^4
    // En effet, si x >= 10^4 (5 chiffres) alors 2*x >= 10^4 et leur concaténation
    // donne donc 10 chiffres ou plus (Absurde!)
    int max = 0;
    for (int i=0; i<MAX; i++) {
        string panDig = pandigitalPossible(i);
        if (stoi(panDig) > max) {
            max = stoi(panDig);
        }
    }
    printf("%d\n", max);
}