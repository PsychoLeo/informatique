#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solve(int n, vector<int> &a) {
    unordered_map<int, int> m;
    for (int x: a) {
        if (m.find(x) == m.end()) m[x] = 1;
        else m[x]++;
    }
    bool unique_found = false;
    for (int i=0; i<n+5; ++i) {
        if (m.find(i) == m.end()) return i;
        else if (m[i]==1 && unique_found) return i;
        else if (m[i]==1 && !unique_found) unique_found = true;
    }
    return -1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x: a) cin >> x;
        cout << solve(n, a) << "\n";
    }
}