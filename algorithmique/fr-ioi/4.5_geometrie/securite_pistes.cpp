#include <iostream>

using namespace std;

int main() {
    cout.precision(10);
    int xa, ya, xb, yb, xc, yc, xd, yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    if (xb == xa) {
        double m2 = (double)(yd-yc)/(xd-xc);
        double p2 = yc - m2*xc;
        cout << xa << " " << m2*xa+p2 << "\n";
        return 0;
    }
    if (xd == xc) {
        double m1 = (double)(yb-ya)/(xb-xa);
        double p1 = ya - m1*xa;
        cout << xd << " " << m1*xd + p1 << "\n";
        return 0;
    }
    double m1 = (double)(yb-ya)/(xb-xa);
    double m2 = (double)(yd-yc)/(xd-xc);
    double p1 = ya - m1*xa;
    double p2 = yc - m2*xc;
    double x = (p2-p1)/(m1-m2);
    double y = m1*x + p1;
    cout << x << " " << y << "\n";
}