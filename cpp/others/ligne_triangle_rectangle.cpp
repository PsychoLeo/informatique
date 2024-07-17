#include <iostream>

using namespace std;

void drawLine (int line);
void drawRect (int line, int col);
void drawTrig (int line);

int main() {
    int line, rectLine, rectCol, trigLine;
    cin >> line >> rectLine >> rectCol >> trigLine;
    drawLine (line);
    drawRect (rectLine, rectCol);
    drawTrig (trigLine);
}

void drawLine (int line) {
    for (int i=0; i<line; i++) {
        cout << 'X';
    }
    cout << endl;
}

void drawRect(int line, int col) {
    for (int i=0; i<line; i++) {
        if (i == 0 || i == line-1) {
            for (int j=0; j<col; j++) {
                cout << '#';
            }
            cout << endl;
        }
        else {
            for (int j=0; j<col; j++) {
                if (j == 0 || j == col-1) {
                    cout << '#';
                }
                else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }
}

void drawTrig (int line) {
    for (int i=0; i<line; i++) {
        if (i == 0) {
            cout << '@' << endl;
        }
        else if (i == line-1) {
            for (int j=0; j<line; j++) {
                cout << '@';
            }
            cout << endl;
        }
        else {
            for (int j=0; j<i+1; j++) {
                if (j == 0) {
                    cout << '@';
                }
                else if (j == i) {
                    cout << '@';
                }
                else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }
}