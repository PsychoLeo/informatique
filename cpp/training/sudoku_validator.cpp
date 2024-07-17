#include <stdio.h>
#include <vector>
#define n 9

using namespace std;

bool sudokuValidator(vector<vector<int>> arr) {
    // Check rows and columns
	for (int i=0; i<n; i++) {
        bool visCol[n+1] = {false};
        bool visRow[n+1] = {false};
        for (int j=0; j<n; j++) {
            if (visRow[arr[i][j]] || (visCol[arr[j][i]])) {
                return false;
            }
            visRow[arr[i][j]] = true;
            visCol[arr[j][i]] = true;
        }
    }
    // Check 3 x 3 squares
    for (int i=0; i<n; i+=3) {
        for (int j=0; j<n; j+=3) {
            bool visSquare[n+1] = {false};
            for (int a=i; a<i+3; a++) {
                for (int b=j; b<j+3; b++) {
                    if (visSquare[arr[a][b]]) {
                        return false;
                    }
                    visSquare[arr[a][b]] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> arr (n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    bool x = sudokuValidator(arr);
    printf("%s\n", x ? "true": "false");
}