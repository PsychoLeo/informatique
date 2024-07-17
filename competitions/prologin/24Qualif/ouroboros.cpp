#include <string>
#include <vector>
#include <iostream>

using namespace std;

void ouroboros(int n, int m, vector<string> villes, string actions) {
    vector<int> manges; // villes mangées
    for (char x: 

}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> villes(n);
    string actions;
    for (int i=0; i<n; ++i) { 
        cin >> villes[i];
    }
    cin >> actions;
    ouroboros(n, m, villes, actions);
}