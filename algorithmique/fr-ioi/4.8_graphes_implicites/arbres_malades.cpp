#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double dist(int xA, int yA, int xB, int yB) {
    return sqrt(pow(xA-xB, 2)+ pow(yA-yB, 2));
}

vector<vector<int>> initVector (int n) {
    vector<vector<int>> res;
    for (int i=0; i<n; i++) {
        vector<int> v;
        res.push_back(v);
    }
    return res;
}

int DFS(int n, int depNode, vector<vector<int>> listAdj) {
    int r = 0;
    bool visited[n] = {false};
    vector<int> toVisit = {depNode};
    visited[depNode] = true;
    while (!toVisit.empty()) {
        int node = toVisit.back();
        toVisit.pop_back();
        r++;
        for (int neighbour: listAdj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                toVisit.push_back(neighbour);
            }
        }
    }
    return r;
}

int main() {
    int nbArbres, nbReq;
    cin >> nbArbres >> nbReq;
    vector<pair<int, int>> pos;
    vector<int> radius;
    for (int i=0; i<nbArbres; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        pos.push_back(make_pair(x, y));
        radius.push_back(r);
    }
    int nbInfectes[nbArbres];
    for (int i=0; i<nbArbres; i++) {
        nbInfectes[i] = -1;
    }
    vector<vector<int>> listAdj = initVector(nbArbres);
    // Form a graph => if dist from pos[i] to pos[j] <= radius[i], they are linked
    for (int i=0; i<nbArbres; i++) {
        for (int j=0; j<nbArbres; j++) {
            if (i != j) {
                int xi = pos[i].first, yi = pos[i].second;
                int xj = pos[j].first, yj = pos[j].second;
                if (dist(xi, yi, xj, yj) <= radius[i]) {
                    listAdj[i].push_back(j);
                }
            }
        }
    }
    // We have formed the adjacency list of the graph
    // For every request, give the number of nodes visited with a DFS/BFS from the given node
    for (int i=0; i<nbReq; i++) {
        int req;
        cin >> req;
        if (nbInfectes[req] == -1) {
            nbInfectes[req] = DFS(nbArbres, req, listAdj);
        }
        cout << nbInfectes[req] << endl;
    }
}