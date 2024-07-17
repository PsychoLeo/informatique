/*
We know that the solution has to contain exactly $1$ time the number $10$
as it has to be $16$ digits long for only $10$ nodes and the only number to 
be $2$ digits long is $10$.

We now can say that there is only one number 10 and it is located on the 
exterior of the ring as there would be more than 16 digits if it was on the interior

After searching for a bit (as I am a big fan of nice solutions), I couldn't come
to very satisfying conclusions and decided to try a brute force approach (testing $10^10$ different
combinations with small optimizations)

Sorry for this ugly solution, I am not very proud of it... :(
Runs in 1s in C++
*/

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#define ll long long int
#define vi vector<int>
#define inf 1000*1000*1000
#define SZ 5
#define pb push_back
#define db(x) printf("#x=%d", x)

using namespace std;

int val[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
ll sol = 0;

bool isValidPermutation(vector<int> p) {
    // Supposing the array is {x0, x1, x2, x3, x4, a, b, c, d, e}
    // Where x_i are the ring exterior values and a, b, c... interior
    if (p[5] == 10 || p[6] == 10 || p[7] == 10 || p[8] == 10 || p[9] == 10) {
        return false;
    }
    int sum = p[0] + p[5] + p[6];
    vector<int> checkSum = {p[1]+p[6]+p[7], p[2]+p[7]+p[8], p[3]+p[8]+p[9], p[4]+p[9]+p[5]};
    for (int x: checkSum) {
        if (x != sum) {
            return false;
        }
    }
    return true;
}

ll stringToLL(string s) {
    ll powTen = 1;
    ll r = 0;
    while (!s.empty()) {
        char c = s.back();
        s.pop_back();
        r += (c-'0')*powTen;
        powTen *= 10;
    }
    return r;
}

void printArray(vi s) {
    for (int x: s) {
        printf("%d ", x);
    }
    printf("\n");
}

void orderPermutation(vector<int> s) {
    vector<vi> xi;
    for (int i=0; i<SZ; i++) {
        vi v;
        v.pb(s[i]);
        v.pb(s[5+i]);
        v.pb(s[(1+i)%5+5]);
        xi.pb(v);
    }
    int min=+inf, minInd=0;
    for (int i=0; i<SZ; i++) {
        if (xi[i][0] < min) {
            min = xi[i][0];
            minInd = i;
        }
    }
    string res = "";
    for (int i=minInd; i<SZ+minInd; i++) {
        for (int x: xi[i%SZ]) {
            for (char c: to_string(x)) {
                res.push_back(c);
            }
        }
    }
    ll r = stringToLL(res);
    sol = max(sol, r);
}

void generateSides(vector<bool> in, int sz=0, vector<int> s={}) {
    if (sz == 10) {
        if (isValidPermutation(s)) {
            orderPermutation(s);
        }
    }
    else {
        for (int n: val) {
            if (!in[n%10]) {
                s.push_back(n);
                in[n%10] = true;
                generateSides(in, sz+1, s);
                s.pop_back();
                in[n%10] = false;
            }
        }
    }
}

int main() {
    vector<bool> r(10, false);
    generateSides(r);
    printf("%lld\n", sol);
}