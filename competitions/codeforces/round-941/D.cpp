#include <iostream>
#include <vector>

using namespace std;

vector<int> solve (int n, int k) {
    vector<int> ans;
    int p=1;
    int S=0;
    while (S+p <k) {
        ans.push_back(p);
        S += p;
        p *= 2;
    }
    if (k-1-S > 0) ans.push_back(k-1-S);
    ans.push_back(k+1);
    while (k+1+p <= (int)(1e6)) {
        ans.push_back(k+1+p);
        p *= 2;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> ans = solve(n, k);
        cout << ans.size() << "\n";
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }
}