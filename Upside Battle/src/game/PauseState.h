#pragma once
#include "GameState.h"

class PauseState : public GameState {
private:
	ofTrueTypeFont pause;
	string pauseTxt;
	ofTrueTypeFont controls;
	string controlsTxt;

public:
	// Constructora
	PauseState(ofApp* a);

	// Sobrecarga del metodo update
	virtual void render();
	virtual void keyPressed(int key);
};