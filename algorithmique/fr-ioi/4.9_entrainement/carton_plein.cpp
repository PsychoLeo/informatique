#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define SIZE 20000

using namespace std;
int nbInside[SIZE];

int main() {
    int n; cin >> n;
    int maxNb = 0;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        nbInside[a]++;
        maxNb = max(maxNb, nbInside[a]);
    }
    cout << maxNb << endl;
}