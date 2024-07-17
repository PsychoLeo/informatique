#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#define MAX_POWER 8 // power to which MAX is raised (here MAX = 1e7)
#define MAX 100*1000*1000
#define ll unsigned long long

using namespace std;
bool P[MAX];
string primesToConcatenate[4] = {"3", "7", "109", "673"};
vector<string> primes;

void fillPrimes() {
    fill(P, P+MAX, true);
    P[0] = P[1] = false;
    for (int i=2; i<MAX; i++) {
        if (P[i]) {
            primes.push_back(to_string(i));
            for (ll j=(ll)i*i; j<MAX; j+=i) {
                P[j] = false;
            }
        }
    }
}

int main() {
    fillPrimes();
    for (string x: primes) {
        for (string toConcat: primesToConcatenate) {
            string n1 = x + toConcat;
            string n2 = toConcat + x;
            // cout << "n1=" << n1 << "| " << "n2=" << n2 << endl;
            if (n1.size() <= MAX_POWER && n2.size() <= MAX_POWER) {
                if (P[stoi(n1)] || P[stoi(n2)]) {
                    continue;
                }
                else {
                    break;
                }
            }
            cout << x << endl;
            return 0;
        }
    }
}