#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 10000
using namespace std;

int n;
bool visited[MAX_SIZE];
int l[MAX_SIZE];
vector<vector<int>> cycles;

void getCycles () {
    for (int i=0; i<n; i++) {
        if (l[i] == i) {
            vector<int> v;
            v.push_back(i+1);
            visited[i] = true;
            cycles.push_back(v);
        }
        else if (!visited[i]) { // on a détecté un nouveau cycle
            int j=i;
            vector<int> currCycle;
            while (!visited[j]) {
                visited[j] = true;
                currCycle.push_back(l[j]+1);
                j = l[j];
            }
            cycles.push_back(currCycle);
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        l[i] = a-1;
    }
    getCycles();
    cout << cycles.size() << endl;
    for (vector<int> v: cycles) {
        for (int e: v) {
            cout << e << " ";
        }
        cout << endl;
    }
}