#include <bits/stdc++.h>
#define F(i,k,n) for(int i=k, i<n, i++)

using namespace std;

int solve(int n, int k) {
    if (k >= n-1) return 1;
    return n;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}