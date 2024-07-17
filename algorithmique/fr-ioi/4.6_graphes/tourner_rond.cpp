#include <iostream>
#include <vector>

using namespace std;

bool isCycle (int nbNodes, int nbEdges, vector<vector<int>> listAdj, int currNode);

int main() {
    ios::sync_with_stdio(false);
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;
    vector<vector<int>> listAdj;
    for (int i = 0; i < nbNodes; i++) {
        vector<int> v;
        listAdj.push_back(v);
    }
    for (int i = 0; i < nbEdges; i++) {
        // vector<int> v;
        // v.push_back(0);
        int A, B;
        cin >> A >> B;
        listAdj[A-1].push_back(B-1);
    }
    for (int i = 0; i < nbNodes; i++) {
        if (isCycle(nbNodes, nbEdges, listAdj, i)) {
            cout << "OUI" << "\n";
            return 0;
        }
    }
    cout << "NON" << "\n";
}

bool isCycle (int nbNodes, int nbEdges, vector<vector<int>> listAdj, int currNode) {
    bool visited[nbNodes] = {false};
    visited[currNode] = true;
    vector<int> toVisit = {currNode};
    while (!toVisit.empty()) {
        int node = toVisit.back();
        toVisit.pop_back();
        visited[node] = true;
        for (int neighbor: listAdj[node]) {
            if (neighbor == currNode) {
                return true;
            }
            if (!visited[neighbor]) {
                toVisit.push_back(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return false;
}