#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int nbEdges, nbNodes;
const vector<vector<int>> G(nbNodes, vector<int>(0, 0));

void initGraph(vector<vector<int>> &listAdj) {
	for (int i=0; i<nbEdges; i++) {
		int A, B;
		cin >> A >> B;
		// cout << A << B << endl;
		listAdj[A-1].push_back(B-1);
		listAdj[B-1].push_back(A-1); // car le graphe est non-orienté
	}
}

void printGraph(vector<vector<int>> &listAdj) {
	cout << endl;
	cout << "Graph : " << endl;
	for (int i=0; i < (int)listAdj.size(); i++) {
		cout << i+1 << " : ";
		for (int j=0; j < (int)listAdj[i].size(); i++) {
			cout << listAdj[i][j]+1 << " ";
		}
		cout << endl;
	}
}

// int isConnexe () {
// 	// On va faire un DFS et retourner le nombre de sommets visités
// 	int nbVisited = 0;
// 	bool visited[nbNodes] = {false};
// 	int currNode = 0;
// 	vector<int> toVisit = {currNode};
// 	visited[currNode] = true;
// 	while (!toVisit.empty()) {
// 		currNode = toVisit.back();
// 		toVisit.pop_back();
// 		nbVisited++;
// 		for (int neighbor : listAdj[currNode]) {
// 			if (!visited[neighbor]) {
// 				visited[neighbor] = true;
// 				toVisit.push_back(neighbor);
// 			}
// 		}
// 	}
// 	return nbVisited;
// }

// void delElem(vector<vector<int>> &listAdj, int index, int val) {
// 	vector<int>::iterator position = find(listAdj[index].begin(), listAdj[index].end(), val);
// 	if (position != listAdj[index].end()) // == myVector.end() means the element was not found
//     	listAdj[index].erase(position);
// 	else {
// 		cout << "Error in deleting element" << endl;
// 		printGraph(listAdj);
// 	}
// }

void cycleEulerien (vector<vector<int>> &listAdj) {
	int currNode = 0;
	int prevNode = -1; // previous node (necessary for deletion)
	vector<int> chemin = {0};
	bool started = false;
	while (currNode != 0 || !started) {
		cout << currNode+1 << " ";
		started = true;
		prevNode = currNode;
		currNode = listAdj[currNode].back();
		listAdj[currNode].pop_back();
		// delElem(listAdj, prevNode, currNode);
		chemin.push_back(currNode);
	}
	cout << 0 << endl;
}

int main() {
	cin >> nbNodes >> nbEdges;
	// Initializing adjacency list
	vector<vector<int>> listAdj(nbNodes, vector<int>(0, 0));
	initGraph(listAdj);
	printGraph(listAdj);
	// if (isConnexe(listAdj) < nbNodes) {
	// 	cout << -1 << endl;
	// 	return 0;
	// }
	// Si tous les noeuds n'ont pas un degré pair
	for (int i=0; i<nbNodes; i++) {
		if (listAdj[i].size() % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	// Le graphe est connexe et tous les noeuds ont des degrés pairs
	cycleEulerien(listAdj); // trouver le chemin du cycle eulérien
}