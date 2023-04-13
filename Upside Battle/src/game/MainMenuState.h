#pragma once
#include "GameState.h"

class MainMenuState : public GameState {
private:
	// Fuentes
	ofTrueTypeFont title;
	ofTrueTypeFont titleShadow;
	ofTrueTypeFont pressStart;

	// Textos
	string titleTxt;
	string startTxt;

	// Variables
	int alpha;
	int changeFactor;

public:
	// Constructora
	MainMenuState(ofApp* a);

	// M�todos esenciales
	virtual void update();
	virtual void render();
	virtual void keyReleased(int key);
};