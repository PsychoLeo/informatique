#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> solve(int n, int m) {
    set<int> surv;
    for (int i=1; i<=n; i++) {
        surv.emplace(i);
    }
    vector<int> winner(n, 0);
    for (int i=0; i<m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        set<int>::iterator low = surv.lower_bound(l);
        vector<int> toRemove;
        for (; *low<=r; ++low) {
            if (*low == x) continue;
            else {
                winner[*low-1] = x;
                toRemove.push_back(*low);
            }
        }
        for (int a: toRemove) surv.erase(a);
    }
    return winner;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int x: solve(n, m)) {
        cout << x << " ";
    }
    cout << endl;
}