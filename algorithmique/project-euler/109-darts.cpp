#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

#define MAX 100
#define deb(x) cout << #x << "=" << x << endl;

using namespace std;

vector<int> doubles;
vector<int> moves;
int nbWays;
int possible[MAX];

void printArray() {
    for (int x: moves) {
        printf("%d ", x);
    }
    printf("\n");
}

void fillMoves() {
    fill(possible, possible+MAX, -1);
    for (int i=1; i<=20; i++) {
        doubles.push_back(2*i);
        moves.push_back(i);
        moves.push_back(2*i);
        moves.push_back(3*i);
    }
    doubles.push_back(50);
    moves.push_back(25);
    moves.push_back(50);
    sort(moves.begin(), moves.end());
}

void searchPossible(int reach, int score=0, int i=0, int flech=1) {
    if (score == reach && flech <= 3) {
        ++nbWays;
    }
    for (int j=i; j<(int)moves.size() && flech < 3; j++) {
        if (score+moves[j] <= reach) {
            searchPossible(reach, score+moves[j], j, flech+1);
        }
        else {
            break;
        }
    }
}

int checkoutCount(int score){
    int sum = 0;
    for (int i: doubles) {
        if (score >= i) {
            if (possible[score-i] == -1) {
                nbWays = 0;
                searchPossible(score-i);
                possible[score-i] = nbWays;
                // deb(nbWays);
            }
            sum += possible[score-i];
        }
        else {
            break;
        }
    }
    return sum;
}

int main() {
    fillMoves();
    // printArray();
    int somme = 0;

    for (int score=2; score < 100; score++) {
        somme += checkoutCount(score);
    }
    printf("%d\n", somme);
}