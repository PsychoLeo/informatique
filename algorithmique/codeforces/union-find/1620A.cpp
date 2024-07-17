#include <iostream>
#include <string> 

using namespace std;

string solve(string & s) {
    int diff_counter = 0;
    for (char c : s) {
        if (c == 'N') ++diff_counter;
    }
    if (diff_counter == 1) return "NO";
    return "YES";
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}