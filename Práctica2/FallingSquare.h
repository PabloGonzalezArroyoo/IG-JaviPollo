#pragma once

#include "ofMain.h"

class FallingSquare
{
private:
	ofRectangle square;
	int color;

public:
	FallingSquare(int posX) {
		square.x = posX;
		square.y = 0;
		square.width = 50;
		square.height = 50;

		int random = ofRandom(0, 2);
		color = random;
	}

	void move() {
		square.position.y += 1;
	}

	ofRectangle getSquare() { return square; }
	int getColor() { return color; }
	int setColor() { return color; }
	int getY() { return square.y; }
};

