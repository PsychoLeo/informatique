#include <iostream>
#include <vector>

using namespace std;

int find(int dep, int node, int c, int *next, vector<int> &r) {
    if (node == dep) {
        r[node] = c;
        return c;
    }
    else {
        int numSauts = find(dep, next[node], c+1, next, r);
        r[node] = numSauts;
        return numSauts;
    }
}

vector<int> solve(int n, int* next) {
    vector<int> r(n, -1);
    for (int i=0; i<n; ++i) {
        if (r[i] == -1) find(i, next[i], 1, next, r);
    }
    return r;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int next[n];
        for (int i=0; i<n; ++i) {
            int x; cin >> x;
            next[i] = x-1;
        }
        for (int x: solve(n, next)) {
            cout << x << " ";
        }
        cout << endl;
    }
}