#include <iostream>
#include <cmath>
#include <string>
#include <map>

using namespace std;

map<char, int> corres;
string alph;
int a, b, c, d;

void getRev () {
    char c; cin >> c;
    int n; cin >> n;
    cout << corres[c] << endl;
    cout << alph[n] << endl;
}

void encodeTwoChars (char c1, char c2) {
    // cout << c1 << c2 <<endl;
    int x1 = corres[c1], x2 = corres[c2], y1, y2;
    y1 = (a*x1 + b*x2) % 26;
    y2 = (c*x1 + d*x2) % 26;
    cout << alph[y1] << alph[y2];   
}

int main() {
    ios::sync_with_stdio(false);
    alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0; i< alph.size(); i++) {
        corres[alph[i]] = i;
    }
    string s;
    getline(cin, s);
    cin >> a >> b >> c >> d;
    for (int i=0; i<s.size(); i+=2) {
        char c1 = s[i], c2 = s[i+1];
        encodeTwoChars(c1, c2);
    }
    cout << endl;
}