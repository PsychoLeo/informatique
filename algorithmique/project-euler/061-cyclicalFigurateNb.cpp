#include <cstdio>
#include <vector>

#define vi vector<int>
#define SZ 6
#define vb vector<bool>

using namespace std;

vector<vi> series(SZ, vi(0, 0));

/*
Remarks : 4-digit numbers have to be between 1000 and 10,000
1000 <= u_n < 10,000
Therefore we can fix a condition on n for each serie (triangle, square, ...)
Triangle : [45, 141]
Square : [32, 101]
Pentagonal : [26, 82]
Hexagonal : [23, 71]
Heptagonal : [21, 64]
Octagonal : [19, 59]

Therefore, we can do a brute force algorithm
For all n in O (we know for sure one of them has to belong to the set) :
    Search in S, P, Hx, Hp, O for a number being next in the chain and mark the
    list he belongs to as visited
Recursive function
*/

void findCyclical(vi l = {}, vb visited = {false, false, false, false, false, false}) {
    if (l.size() == SZ) {
        if (l.back()%100 == l[0]/100) {
            for (int x: l) {
                printf("%d ", x);
            }
            printf("\n");
            return;
        }
    }
    else {
        if (l.size() == 0) {
            for (int x: series[0]) {
                l.push_back(x);
                visited[0] = true;
                findCyclical(l, visited);
                l.pop_back();
                visited[0] = false;
            }   
        }
        else {
            int toFind = l.back()%100;
            for (int i=0; i<SZ; i++) {
                if (!visited[i]) {
                    for (int x: series[i]) {
                        if (x/100 == toFind) {
                            l.push_back(x);
                            visited[i] = true;
                            findCyclical(l, visited);
                            l.pop_back();
                            visited[i] = false;
                        }
                    }
                }
            }
        }
    }
}

void printSeries() {
    for (auto v: series) {
        for (int x: v) {
            printf("%d ", x);
        }
        printf("\n");
    }
}

int main() {
    vi currValues = {1, 1, 1, 1, 1, 1};
    for (int i=1; i<150; i++) { 
        // Rang n de la suite
        for (int j=1; j<=SZ; j++) {
            currValues[j-1] += j*i+1;
            if (currValues[j-1] >= 1000 && currValues[j-1] < 10000) {
                series[j-1].push_back(currValues[j-1]);
            }
        }
    }
    findCyclical();
    // printSeries();
}