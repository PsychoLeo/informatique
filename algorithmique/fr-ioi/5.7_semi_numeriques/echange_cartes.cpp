#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos;
int n;

vector<pair<int, int>> nbEchanges () {
    vector<pair<int, int>> res;
    for (int j=0; j<2; j++) {
        for (int i=n-1; i>=0; i--) {
            if (pos[i] != i) {
                res.push_back(make_pair(i+1, pos[i]+1));
                iter_swap(pos.begin()+i, pos.begin()+pos[i]);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        int currNb; cin >> currNb;
        pos.push_back(currNb-1);
    }
    vector<pair<int, int>> res = nbEchanges();
    cout << res.size() << endl;
    for (pair<int, int> i: res) {
        cout << i.first << " " << i.second << endl;
    }
}