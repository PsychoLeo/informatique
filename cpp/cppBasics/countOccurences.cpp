#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    // cin.ignore();
    getline(cin, s);
    auto it = s.begin();
    while (it != s.end()) {
        auto endWord = find(it, s.end(), ' ');
        string currWord {it, endWord};
        cout << "Number of 'e' in " << currWord << " : " << count(it, endWord, 'e') << endl;
        it = endWord;
        if (endWord != s.end()) {
            ++it;
        }
    }
    // int n = count(s.begin(), s.end(), 'e');
    // cout << "Number of 'e' in sentence : " << n << endl;
}