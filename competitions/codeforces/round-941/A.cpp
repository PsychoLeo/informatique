#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while(t--) {
        int n, k; cin >> n >> k;
        int count[101];
        fill(count, count+101, 0);
        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            int c; cin >> c;
            count[c] += 1;
            if (count[c] > maxCount) {
                maxCount = count[c];
            }
        }

        if(maxCount >= k) {
            cout << k-1 << "\n";
        } else {
            cout << n << "\n";
        }
        
    }
}