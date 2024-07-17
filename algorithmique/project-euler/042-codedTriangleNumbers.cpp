#include <string>
#include <unordered_map>
#define MAX_LEN 20
#define ALPH_SIZE 26

using namespace std;

string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
unordered_map<char, int> score;
bool isTriangleNumber[MAX_LEN*ALPH_SIZE];

void initScore () {
    for (int i=0; i<ALPH_SIZE; i++) {
        score[alph[i]] = i+1;
    }
}

void initTriangleNumbers() {
    fill(isTriangleNumber, isTriangleNumber+MAX_LEN*ALPH_SIZE, false);
    int curr = 0;
    isTriangleNumber[0] = true;
    for (int i=1; curr<MAX_LEN*ALPH_SIZE; i++) {
        curr += i;
        isTriangleNumber[curr] = true;
    }
}

int main() {
    initScore();
    initTriangleNumbers();
    int tot = 0;
    char c;
    int currScore = 0;
    while (scanf("%c", &c) != EOF) {
        currScore += score[c];
        if (c == ' ') {
            if (isTriangleNumber[currScore]) {
                tot++;
            }
            currScore = 0;
        }
    }
    printf("%d\n", tot);
}