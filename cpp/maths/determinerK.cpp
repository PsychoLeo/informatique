#include <iostream>
#include <cmath>

using namespace std;
int mini;
int maxi;
double seuil;
double d;

double u_n (int n) {
    return log(n)/n - seuil;
}

void searchN (int lower, int upper) {
    int mid = (lower+upper)/2;
    double delta = u_n(mid);
    double deltaB = u_n(mid+1);
    if (delta > 0 && deltaB > 0) { // ln(k)/k > seuil - on a cherché trop bas
        searchN(mid+1, upper);
    }
    else if (delta < 0 && deltaB < 0) {
        searchN(lower, mid);
    }
    else {
        cout << mid+1 << endl;
        return;
    }
}

int main() {
    mini = 1;
    maxi = 500*1000*1000;
    cin >> seuil;
    d = 1e-8;
    searchN(mini, maxi);
}