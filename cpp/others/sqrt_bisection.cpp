// Template :
// #include <iostream>
// #include <cmath>

// using namespace std;

// int main() {
	
// }

#include <iostream>
#include <cmath>

using namespace std;

double squareRoot (double n);

int main() {
    cout << "Enter the number to get its square root : ";
    double n; cin >> n;
    cout << "sqrt(" << n << ") = " << squareRoot(n) << endl;
    return 0;
}

double squareRoot(double n) {
    double mini=0, mid=n/2, maxi=n;
    double delta=0.000001, ecart = mid*mid - n;
    while (ecart > delta || ecart < -delta) {
        if (ecart > delta) {
            maxi = mid;
            mid = (mini+maxi)/2;
        }
        else {
            mini = mid;
            mid = (mini+maxi)/2;
        }
        ecart = mid*mid-n;
    }
    return mid;
}