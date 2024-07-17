using namespace std;

#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <tuple>

#define ll long long
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
#define pii pair<int, int>
#define MAX 1000

deque<tuple<int, int, int>> toVisit;
tuple<int, int, int> lastVisited;
bool visited[MAX][MAX];
int side, nbCasernes;
vector<pii> possibleMoves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// void fillArray() {
//     for (int i=0; i<MAX; i++) {
//         for (int j=0; j<MAX; j++) {
//             visited[i][j] = false;
//         }
//     }
// }

int main() {
    scanf("%d %d", &side, &nbCasernes);
    for (int i=0; i<nbCasernes; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        visited[y][x] = true;
        toVisit.push_back(mt(x, y, 0));
    }
    while (!toVisit.empty()) {
        auto t = toVisit.front();
        if (toVisit.size() == 1) {
            lastVisited = t;
        }
        toVisit.pop_front();
        int x, y, len;
        tie(x, y, len) = t;
        for (auto d: possibleMoves) {
            int nx = x+d.fi, ny = y+d.se;
            if (nx >= 0 && nx < side && ny >= 0 && ny < side) {
                if (!visited[ny][nx]) {
                    toVisit.push_back(mt(nx, ny, len+1));
                    visited[ny][nx] = true;
                }
            }
        }
    }
    printf("%d\n", get<2>(lastVisited));
    return 0;
}