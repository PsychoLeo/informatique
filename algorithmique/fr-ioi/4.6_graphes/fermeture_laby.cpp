#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

void BFS(vector<vector<int>> &adjList, vector<bool> &visited, vector<vector<int>> &pred, vector<int> &result, int depNode);
void delElem (vector<int> &vec, int value);

int main() {
    ios::sync_with_stdio(false);
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;
    vector<vector<int>> adjList;
    vector<vector<int>> pred; // predecesseurs
    // Idée : trouver le noeud qui n'a aucun prédecesseur
    for (int i = 0; i < nbNodes; i++) {
        vector<int> v;
        adjList.push_back(v);
        vector<int> p;
        pred.push_back(p);
    }
    for (int i = 0; i < nbEdges; i++) {
        int A, B;
        cin >> A >> B;
        adjList[A-1].push_back(B-1);
        pred[B-1].push_back(A-1);
    }
    // for (int i = 0; i < nbNodes; i++) {
    //     for (int j = 0; j < adjList[i].size(); j++) {
    //         cout << adjList[i][j];
    //     }
    //     cout << "\n";
    // }
    vector<int> result;
    vector<bool> visited(nbNodes, false);
    for (int i = 0; i < nbNodes; i++) {
        if (pred[i].empty() && !visited[i]) {
            BFS(adjList, visited, pred, result, i);
        }
    }
    if (result.size() != nbNodes) {
        cout << "-1\n";
    }
    else {
        for (int i = 0; i < nbNodes; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}


void BFS(vector<vector<int>> &adjList, vector<bool> &visited, vector<vector<int>> &pred, vector<int> &result, int depNode) {
    result.push_back(depNode+1);
    visited[depNode] = true;
    while (!adjList[depNode].empty()) {
        int neighbor = adjList[depNode].back();
        adjList[depNode].pop_back();
        delElem(pred[neighbor], depNode);
        // remove(pred[neighbor].begin(), pred[neighbor].end(), depNode);
        if (pred[neighbor].empty() && (!visited[neighbor])) {
            visited[neighbor] = true;
            BFS(adjList, visited, pred, result, neighbor);
        }
    }
}

void delElem (vector<int> &vec, int value) {
    vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
}