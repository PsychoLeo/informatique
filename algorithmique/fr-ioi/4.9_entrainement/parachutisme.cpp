#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define deb(x) cout << #x << "=" << x << endl
#define test() cout << "OK" << endl

#define ll long long
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX 1000

vector<tuple<int, int, int, int>> lacs;
int side, nbLacs, n;
int isLac[MAX][MAX] = {false};

void fillLacs() {
    for (auto t: lacs) {
        int x1, y1, x2, y2;
        tie(x1, x2, y1, y2) = t;
        // deb(dx);
        for (int i=y1; i<=y2; i++) {
            int dx = x2-x1+1;
            for (int j=x1; j<=x2; j++) {
                // deb(j);
                if (isLac[i][j] >= dx && dx > 0) {
                    int d = isLac[i][j]-1;
                    j += d;
                    dx -= d;
                }
                else {
                    isLac[i][j] = dx;
                    dx--;
                }
            }
        }
    }
}

bool compTuple (tuple<int, int, int, int> t1, tuple<int, int, int, int> t2) {
    int dx1 = get<1>(t1) - get<0>(t1);
    int dx2 = get<1>(t2) - get<0>(t2);
    return dx1 > dx2;
}

void printGrid() {
    for (int i=0; i<side; i++) {
        for (int j=0; j<side; j++) {
            printf("%d ", isLac[i][j]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d %d %d", &side, &nbLacs, &n);
    for (int i=0; i<nbLacs; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        lacs.pb(mt(x1, x2, y1, y2));
    }
    // sort(lacs.begin(), lacs.end());
    fillLacs();
    // printGrid(); // debugging the grid
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &y, &x);
        printf("%d\n", (isLac[y][x]>0));
    }
}