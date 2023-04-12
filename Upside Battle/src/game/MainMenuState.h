#pragma once
#include "GameState.h"

class MainMenuState : public GameState {
private:
	ofTrueTypeFont title;
	ofTrueTypeFont titleShadow;
	ofTrueTypeFont pressStart;
	string titleTxt;
	string startTxt;
	int alpha;
	int changeFactor;

public:
	// Constructora
	MainMenuState(ofApp* a);

	// Sobrecarga del método update
	virtual void update();
	virtual void render();
	virtual void keyReleased(int key);
};