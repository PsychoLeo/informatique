#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> piles) {
    sort(piles.begin(), piles.end());
    vector<int> new_piles;
    new_piles.push_back(piles[0]);
    for (int i=1; i<piles.size(); i++) {
        if (new_piles[new_piles.size()-1] != piles[i])
            new_piles.push_back(piles[i]);
    }
    vector<int> diff;
    diff.push_back(new_piles[0]);
    for (int i=1; i<new_piles.size(); i++) {
        diff.push_back(new_piles[i]-new_piles[i-1]);
    }
    // true=lose; false=win
    vector<bool> win(diff.size(), false);
    win[win.size()-1]=true;
    for (int i=win.size()-2; i>=0; i--) {
        if (win[i+1] && diff[i]==1) {
            win[i]=false;
        }
        else{
            win[i]=true;
        }
    }

    if (win[0]){
        cout << "Alice"<<'\n';
    }
    else
        cout << "Bob"<<'\n';
}


int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> piles(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> piles[i];
        }
        solve(piles);
    }
}