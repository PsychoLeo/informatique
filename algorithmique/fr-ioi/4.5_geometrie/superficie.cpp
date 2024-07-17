#include <iostream>
#include <algorithm>

using namespace std;

int intersection (int a, int b, int c, int d);

int main() {
    int xA, yA, xB, yB;
    cin >> xA >> yA >> xB >> yB;
    int surface = (xB-xA)*(yB-yA);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        // cout << surface << "\n";
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // On cherche l'intersection de l'intervalle [x1; x2] et [xA; xB]
        // De même pour [y1; y2] et [yA; yB]
        int dx = intersection(x1, x2, xA, xB);
        int dy = intersection(y1, y2, yA, yB);
        if (dx > 0 && dy > 0) {
            surface -= dx*dy;
        }
    }
    cout << surface << "\n";
}

int intersection (int a, int b, int c, int d) {
    // Calcule la taille de l'intersection entre [a, b] et [c, d]
    int left, right;
    if (b <= c || d <= a) { // no intersection
        return -1;
    }
    else if (a <= c) {
        return min(b, d)-c;
    }
    else {
        return min(b, d)-a;
    }
}