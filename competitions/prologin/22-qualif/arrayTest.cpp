#include <cstdio>

using namespace std;

void changeVal(int arr[], int pos, int newVal) {
    arr[pos] = newVal;
}

int main() {
    int arr[5] = {-1};
    changeVal(arr, 0, -2);
    for (int e: arr) {
        printf("%d ", e);
    }
    printf("\n");
}