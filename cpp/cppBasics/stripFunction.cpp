#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

string strip(string s) {
    auto pLeft = s.begin();
    while (isspace(*pLeft)) {
        pLeft++;
    }
    s.erase(s.begin(), pLeft);
    auto pRight = s.end()-1;
    while (isspace(*pRight)) {
        pRight--;
    }
    s.erase(++pRight, s.end());
    return s;
}

int main() {
    string s;
    getline(cin, s);
    cout << "Before strip : " << s << endl;
    s = strip(s);
    cout << "After strip : " << s << endl;
    return 0;
}