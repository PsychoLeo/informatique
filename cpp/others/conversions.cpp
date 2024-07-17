#include <iostream>

// https://stackoverflow.com/questions/4103086/defining-constants-in-c
// C'est pour cela que je n'ai pas utilisé #define mais plutôt const 
// (dont j'ai au passage appris l'existence)

using namespace std;

const double METRE = (double)1/0.3048; // pied
const double GRAMME = 0.002205; // livre

double conversion (double num, char unite);
double CtoF (double temperature);
char getUnit(char unite);


double CtoF (double temperature) {
    return temperature*1.8 + 32;
}

int main() {
    int numVals; cin >> numVals;
    double num;
    char unite;
    for (int i=0; i<numVals; i++) {
        cin >> num >> unite;
        cout << conversion(num, unite) << " " << getUnit(unite) << endl;
    }
}

char getUnit(char unite) {
    if (unite == 'm') {
        return 'p';
    }
    else if (unite == 'g') {
        return 'l';
    }
    else { // unite == 'c'
        return 'f';
    }
}

double conversion (double num, char unite) {
    if (unite == 'm') {
        return num*METRE;
    }
    else if (unite == 'g') {
        return num*GRAMME;
    }
    else { // unite == 'c'
        return CtoF(num);
    }
}