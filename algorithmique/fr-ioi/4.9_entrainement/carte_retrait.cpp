#include <stdio.h>
#include <deque>

using namespace std;

int h, plafond, n;

int main() {
    scanf("%d %d %d", &h, &plafond, &n);
    int currSomme = 0;
    deque<int> depenses;
    for (int i=0; i<h && i<n; i++) {
        int r; scanf("%d", &r);
        currSomme += r;
        depenses.push_back(r);
        if (currSomme <= plafond) {
            printf("1\n");
        }
        else {
            printf("0\n");
            currSomme -= r;
            depenses.back() = 0;
        }
    }
    for (int i=h; i<n; i++) {
        int r; scanf("%d", &r);
        currSomme -= depenses.front();
        depenses.pop_front();
        currSomme += r;
        depenses.push_back(r);
        if (currSomme <= plafond) {
            printf("1\n");
        }
        else {
            printf("0\n");
            currSomme -= r;
            depenses.back() = 0;
        }
    }
}