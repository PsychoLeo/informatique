#include <cmath>
#include <iostream>

using namespace std;
// calculator (enhanced)

int exponent (int a, int b);

int main () {
    char oper;
    int a, b, result;
    cout << "Enter the first number (int): ";
    cin >> a;
    cout << "Enter the second number (int): ";
    cin >> b;
    cout << "Enter the operator (+ - / * ^) : ";
    cin >> oper;
    switch (oper) {
    case '+': 
        result = a+b;
        break;
    case '-' :
        result = a - b;
        break;
    case '/' :
        result = a/b;
        break;
    case '*' :
        result = a*b;
        break;
    case '^' :
        result = exponent(a, b); 
        break;
    default:
        cout << "Invalid input" << endl;
    }
    cout << a << " " << oper << " " << b << " = " << result << endl;
    return 0;
}

int exponent (int a, int b) { // returns a^b
    if (b <= 0) {
        return 1;
    }
    else {
        return a*exponent(a, b-1);
    }
}