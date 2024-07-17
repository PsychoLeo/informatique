#include <iostream>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score=0;
pair<int, int> dir = {0, 0};


void setup() {
	gameOver = false;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void draw() {
    system("clear"); // clear console window (on linux)
    for (int i=0; i<width; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (j == 0 || j == width-1) {
                cout << "#";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

}

void input() {

}

void logic() {

}

int main() {
	while (!gameOver) {
		draw();
		input();
		logic();
        // sleep(10); // sleep for 10 milliseconds
	}
}
