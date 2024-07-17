#include <iostream>
#include <cmath>

using namespace std;

int u(int n);
// int diviseurs (int n);

int main() {
    // diviseurs(2000);
    int n; cout << "Entrer le nombre auquel nous sommes congru : "; cin >> n;
    int l[n], result[n];
    for (int i=0; i<n; i++) {
        l[i] = i;
        result[i] = u(i)%n;
    }
    for (int i=0; i<n; i++) {
        cout << "n = " << l[i] << " <=> u(n) ≡ " << result[i] << " mod(" << n << ")" << endl;
    }
}

int u(int n) {
    // returns the image of a number by this function
    // Changer cette fonction si l'on souhaite changer le output
    return pow(n, 3)+n-2;
}

int diviseurs (int n) {
    // renvoie les diviseurs de n
    cout << "Diviseurs de n : " << endl;
    cout << n << " ";
    for (int i=n-1; i>1; i--) {
        if (n%i==0) {
            cout << i << " ";
        }
    }
    cout << 1 << endl; // print 1 and n as they both divide n
    return 0;
}