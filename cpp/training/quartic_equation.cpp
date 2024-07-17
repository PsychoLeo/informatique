#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

struct QuarticEquation {
    int a, b, c;
    QuarticEquation(int A, int B, int C) {
        a = A;
        b = B;
        c = C;
    }
    int nbSolutions() {
        int delta = b*b - 4*a*c;
        if (delta < 0) {
            return 0;
        }
        else {
            int res = 0;
            int x1 = (-b-sqrt(delta))/(2*a);
            int x2 = (-b+sqrt(delta))/(2*a);
            if (x1 >= 0) {
                res += 2;
            }
            if (x2 >= 0) {
                res += 2;
            }
            return res;
        }
    }
};

int quarticEquation(int a, int b, int c) {
	float delta = (float)b*b - 4*a*c;
    if (delta < 0) {
        return 0;
    }
    else {
        int res = 0;
        float x1 = (-b-sqrt(delta))/(2*a);
        float x2 = (-b+sqrt(delta))/(2*a);
        if (x1 > 0) {
            res += 2;
        }
        else if (x1 == 0) {
            res++;
        }
        if (x2 > 0) {
            res += 2;
        }
        else if (x2 == 0) {
            res++;
        }
        return res;
    }
} 

int main() {
    vector<vector<int>> test = {{1, -5, 4}, {4, 3, -1}, {1, 10, 9}};
    for (vector<int> v: test) {
        // QuarticEquation q = QuarticEquation(v[0], v[1], v[2]);
        printf("%d\n", quarticEquation(v[0], v[1], v[2]));
    }
}