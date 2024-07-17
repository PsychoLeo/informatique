#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int narrays, nqueries, maxlen;
    cin >> narrays >> nqueries;
    vector<vector<int>> l;
    for (int i=0; i<narrays; i++) {
        cin >> maxlen;
        vector<int> arr(maxlen);
        for (int j=0; j<maxlen; j++) {
            cin >> arr[j];
        }
        l.push_back(arr);
    }
    int a, b;
    vector<int> result;
    for (int i=0; i<nqueries; i++) {
        cin >> a >> b;
        result.push_back(l[a][b]);
    }
    for (int i: result) {
        cout << i << endl;
    }
    return 0;
}