#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(const string s) {
    return equal(s.begin(), s.end(), s.rbegin(), s.rend());
}

int main() {
    string s;
    getline(cin, s);
    // int sz = s.size();
    // cout << boolalpha;
    // string::iterator dep = s.begin(); // declaring iterator
    // string::iterator pLeft;
    // string::iterator pRight;
    // if (sz % 2 == 0) {
    //     pLeft = s.begin() + sz/2-1;
    //     pRight = s.begin() + sz/2; 
    // }
    // else {
    //     pLeft = s.begin()+sz/2-1;
    //     pRight = s.begin()+sz/2+1;
    // }
    // while (pLeft != dep && *pLeft == *pRight) {
    //     pLeft--;
    //     pRight++;
    // }
    // cout << (pLeft == dep) << endl;
    cout << boolalpha;
    cout << isPalindrome(s) << endl;
}