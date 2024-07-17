#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void getStrings (int tailleMot, int numLettres, string mot); 

int main() {
   int tailleMot, numLettres;
   string mot;
   cin >> tailleMot;
   cin.ignore();
   getline(cin, mot);
   cin >> numLettres;
   sort(mot.begin(), mot.end()); // sorting string
//    cout << mot << endl;
   getStrings (tailleMot, numLettres, mot); // calling function
}

void getStrings (int tailleMot, int numLettres, string mot) {
    int size = pow(tailleMot, numLettres); // total number of possible words
    string results[size];
    string pred[size];
    int currentSize = 0;
    for (int i=0; i<numLettres; i++) {
        if (currentSize == 0) { // if no predecessor
            currentSize = tailleMot;
            for (int j=0; j< tailleMot; j++) {
                results[j] = mot[j];
            }
        }
        else {
            for (int j=0; j < currentSize; j++) {
                for (int k=0; k < tailleMot; k++) {
                    results[j*tailleMot+k] = pred[j] +mot[k];
                }
            }
            currentSize *= currentSize; // raise currentSize by one power
        }
        for (int i=0; i<currentSize; i++) {
            pred[i] = results[i]; // using pred to have predecessors
        }
   }
   cout << size << endl;
   for (string res: results) {
       cout << res << endl;
   }
}

