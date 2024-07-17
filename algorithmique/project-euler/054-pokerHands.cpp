#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define F first
#define S second
#define MAX 1000
#define PB push_back


using namespace std;

int pow15[8] = {1, 15, 225, 3375, 50625, 759375, 11390625, 170859375};
// powers of 15 below integer max limit (to form numbers in base 15)
// used to calculate the score of each hand (as there are 14 cards)

int cardsValue (char c) {
    switch (c) {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default: return (c-'0');
    }
}

bool cmpCards (pair<int, char> c1, pair<int, char> c2) {
    return c1.first < c2.first;
}

struct PokerHand {

    vector<pair<int, char>> cards;
    int score;
    vector<int> v; // value of each card
    vector<int> c; // color of each card

    PokerHand(vector<string> c) {
        for (string s: c) {
            cards.push_back(make_pair(cardsValue(s[0]), s[1]));
        }
        sort(cards.begin(), cards.end(), cmpCards);
    }

    bool royalFlush() {
        if (c[0] == c[1] == c[2] == c[3] == c[4]) {
            if (v[0] == 10 && (v[0] == v[1]-1 == v[2]-2 == v[3]-3 == v[4]-4)) {
                return true;
            }
        }
        return false;
    }

    bool straightFlush() {
        if (c[0] == c[1] == c[2] == c[3] == c[4]) {
            if (v[0] == v[1]-1 == v[2]-2 == v[3]-3 == v[4]-4) {
                return true;
            }
        }
        return false;
    }

    bool fourOfKind() {
        if (v[1] == v[2] == v[3]) {
            if (v[0] == v[1] || v[4] == v[1]) {
                return true;
            }
        }
        return false;
    }

    bool fullHouse() {
        return false;
    }

    bool flush() {
        return false;
    }

    bool straight() {
        return false;
    }

    bool threeOfKind() {
        return false;
    }

    bool twoPairs() {
        return false;
    }

    bool onePair() {
        return false;
    }

    bool highCard() {
        return false;
    }

    void setScore () {
        // Check by decreasing order each possibility
        int score = 0;
        for (auto x: cards) {
            v.PB(x.F);
            c.PB(x.S);
        }
        if (royalFlush()) {
            score = 2*pow15[7];
        }
        else if (straightFlush()) {
            score = pow15[7] + v[0];
        }
        else if (fourOfKind()) {
            score = pow15[6] + pow15[5]*v[1];
        }
        else if (fullHouse()) {

        }
    }

    void print() {
        for (auto c: cards) {
            cout << c.F << " " << c.S << "\t";
        }
        cout << "\n";
    }

};  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r = 0;
    // cout << cardsValue('7') << "\n";
    for (int i=0; i<MAX; i++) {
        vector<string> p1Hands;
        vector<string> p2Hands;
        string lin;
        getline(cin, lin);
        for (int i=0; i<30; i+=3) {
            string s;
            s = lin.substr(i, 2);
            if (i < 15) {
                p1Hands.push_back(s);
            }
            else {
                p2Hands.push_back(s);
            }
        }
        PokerHand p1 = PokerHand(p1Hands);
        PokerHand p2 = PokerHand(p2Hands);
        p1.setScore();
        p2.setScore();
        if (p1.score > p2.score) {
            r++;
        }
        else if (p1.score == p2.score) {
            cout << "2 players have same score" << "\n";
            p1.print();
            p2.print();
        }
        // p1.print();
        // p2.print();
    }
    printf("%d\n", r);
}