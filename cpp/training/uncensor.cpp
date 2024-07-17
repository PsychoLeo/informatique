#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

string uncensor(string str, string vowels) {
	vector<char> l;
    for (char c: str) {
        l.push_back(c);
    }
    int j=0; // index in vowels
    for (int i=0; i<l.size(); i++) {
        if (l[i] == '*') {
            l[i] = vowels[j];
            j++;
        }
    }
    string r = "";
    for (int i=0; i<l.size(); i++) {
        r += l[i];
    }
    return r;
}