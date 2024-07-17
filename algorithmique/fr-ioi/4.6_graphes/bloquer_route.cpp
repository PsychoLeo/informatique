#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited = {false};

vector<vector<int>> initialize2DVector (int size) {
    vector<vector<int>> result;
    for (int i = 0; i < size; i++) {
        vector<int> v;
        result.push_back(v);
    }
    return result;
}

void DFS(int nbNodes, int currNode, vector<bool> &visited, int depth=0) {
    visited[currNode] = true;
}

int main() {
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;
    vector<vector<int>> adjList = initialize2DVector(nbNodes);
    for (int i = 0; i < nbEdges; i++) {
        int A, B; 
        cin >> A >> B;
        adjList[A-1].push_back(B-1);
        adjList[B-1].push_back(A-1);
    }
}