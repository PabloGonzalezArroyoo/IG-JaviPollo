#pragma once

#include "ofMain.h"

class FallingSquare
{
private:
	ofRectangle square;
	int color;
	float xMoveFactor;
	float speed;

public:
	FallingSquare(int posX) {
		square.x = posX;
		square.y = 0;
		square.width = 50;
		square.height = 50;

		int random = ofRandom(0, 2);
		color = random;
		xMoveFactor = ofRandom(-1, 2) / 4;

		speed = 1.5;
	}

	void move() {
		square.position.y += speed;
		square.position.x += xMoveFactor;
	}

	ofRectangle getSquare() { return square; }
	int getColor() { return color; }
	int setColor() { return color; }
	int getY() { return square.y; }
};

