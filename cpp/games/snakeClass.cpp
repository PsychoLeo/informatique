#include <conio.h>
#include <iostream>
#include <deque>

using namespace std;

struct Snake {
	int x, y, dx, dy, size=1;
	Field f;
	deque<pair<int, int>> body;
	
	Snake (Field F) {
		f = F;
		x = f.w/2;
		y = f.h/2;
		dx = 1; // moving left
		dy = 0;
		body.push_back(make_pair(x, y));
	}

	void move (Apple a) {
		x += dx;
		y += dy;
		if (eatsApple(a)) {
			size++;
		}
		if (dies()) {
			size = 1;
			x = 
		}
	}

	bool dies() {
		return (x == f.w-1 || y == f.h-1 || x == 0 || y == 0);
	}

	bool eatsApple (Apple a) {
		return (x == a.x && y == a.y);
	}
};

struct Field {
	int w, h; // width and height
	vector<vector<int>> grid;

	Field(int W, int H) {
		w = W;
		h = H;
		for (int i=0; i<h; i++) {
			vector<int> v;
			for (int j=0; j<w; j++) {
				if (j == 0 || j == w-1) {
					v.push_back(-1);
				}
				else {
					v.push_back(0);
				}
			}
		}
	}
};

struct Apple {
	int x, y;
	Snake s;
	Field f;

	Apple (Snake S, Field F) {
		s = S;
		f = F;
		while (rand() % f.w
	}
};

int main() {

}
