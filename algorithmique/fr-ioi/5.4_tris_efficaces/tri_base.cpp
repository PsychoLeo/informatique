#include <iostream>
#include <vector>

using namespace std;

void printList(vector<int> list) {
    for (int i: list) {
        cout << i << " ";
    }
    cout << endl;
}

void binarySort(vector<int> list, short power = 31) {
    // short est la décalage binaire à faire (1 => diviser par 2)
    // 2 => diviser par 4, etc...
    if (power == -1) {
        for (int i: list) {
            cout << i << " ";
        }
        return;
    }
    // printList(list);
    vector<int> lower;
    vector<int> upper;
    for (int i: list) {
        if ((1<<power) & i) {
            upper.push_back(i);
        }
        else {
            lower.push_back(i);
        }
    }
    //
    // printList(lower);
    // printList(upper);
    //
    if (!lower.empty()) {
        binarySort(lower, power-1);
    }
    if (!upper.empty()) {
        binarySort(upper, power-1);
    }
}

int main() {
    int n; cin >> n;
    vector<int> l;
    // cout << n << endl;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        // cout << a << " ";
        l.push_back(a);
    }
    // Chaque n : 0 <= n <= 10^8
    // On code donc chaque entier sur 27 (donc 32) bits
    binarySort(l);
    cout << endl;
}