#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string alph = "abcdefghijklmnopqrstuvwxyz";

string solve(int n, int k, string s) {
    string r;
    int i=0;
    char max_abaissee = 'a'; // lettre la plus grande qu'on a pu abaisser à a
    for (; i<n && s[i]-'a'<=k; ++i) {
        r += 'a'; max_abaissee = max(max_abaissee, s[i]);
    }
    // i est l'indice de la première lettre qu'on ne pourra baisser complètement
    if (i==n) return r;
    int j = i;
    int reste_abaisser = k-(max_abaissee-'a');
    char remplacer = alph[s[i]-'a'-reste_abaisser];
    for (; i<n; ++i) {
        if (s[i] <= max_abaissee) r += 'a';
        else if (s[i] > s[j] || s[i] < remplacer) r += s[i];
        else r += remplacer;
    }
    return r;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t-- ) {
        int n, k;
        cin >> n >> k;
        string s; cin >> s;
        cout << solve(n, k, s) << endl;
    }
}