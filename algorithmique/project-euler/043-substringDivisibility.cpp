#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
using ll = long long int;

int nb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int divisors[7] = {2, 3, 5, 7, 11, 13, 17};
ll sum = 0;

ll strtoll (string n) {
    ll res = 0;
    ll pow10 = 1;
    while (!n.empty()) {
        res += (n.back()-'0')*pow10;
        n.pop_back();
        pow10 *= 10;
    }
    return res;
}

bool isSubstrDiv (string r) {
    bool res = true;
    for (int dep = 1; dep <= 7; dep++) {
        string subR = r.substr(dep, 3);
        // cout << subR << "\n";
        res = res && (strtoll(subR) % divisors[dep-1] == 0);
    }
    return res;
}

void pandigital (string r = "") {
    if (r.size() == 10) {
        // We have a pandigital number (check if it has the property)
        if (isSubstrDiv(r)) {
            sum += strtoll(r);
        }
    }
    for (int n: nb) {
        string c = to_string(n);
        if (r.find(c) == string::npos) {
            pandigital(r+c);
        }
    }
}

int main() {
    pandigital();
    printf("%llu\n", sum);
}