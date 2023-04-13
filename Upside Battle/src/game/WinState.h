#pragma once
#include "GameState.h"

class WinState : public GameState {
private:
	ofTrueTypeFont win;
	string winTxt;
	ofTrueTypeFont pressStart;
	string startTxt;
	int winner;
	int alpha;
	int changeFactor;
	ofRectangle rectP1;
	ofRectangle rectP2;

public:
	// Constructora
	WinState(ofApp* a, int w);

	// Sobrecarga del metodo update
	virtual void update();
	virtual void render();
	virtual void keyPressed(int key);

	void createWinnerDisplay();
	void drawCrown();
};