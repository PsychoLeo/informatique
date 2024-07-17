#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <deque>
#include <cmath>
#include <algorithm>

#define SIZE 262144
#define NIVEAU 1000

using namespace std;

int n, k;
int tournoi[SIZE];

int main() {
    deque<unordered_set<int>> l;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        tournoi[i] = x;
    }
    for (int i=0; i<pow(2, n); i++) {
        int x;
        scanf("%d", &x);
        unordered_set<int> s = {x};
        l.push_back(s);
    }
    while (l.size()>1) {
        unordered_set<int> qualified;
        unordered_set<int> left = l.front();
        l.pop_front();
        unordered_set<int> right = l.back();
        l.pop_back();
        for (int c1: left) {
            for (int c2 : right) {
                if (abs(c1-c2) < k) {
                    qualified.insert(c1);
                    qualified.insert(c2);
                }
                else if (c1 > c2) {
                    qualified.insert(c1);
                }
                else {
                    qualified.insert(c2);
                }
            }
        }
        l.push_back(qualified);
    }
    int minimum = 1001;
    for (int i: l.front()) {
        if (i < minimum) {
            minimum = i;
        }
    }
    printf("%d\n", minimum);
}