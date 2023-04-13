#include "PauseState.h"

// Constructora
PauseState::PauseState(ofApp* a) : GameState(a) {
	// Añadir el manager
	mng = new Manager();

	pause.load("../../resources/daydream.ttf", PAUSE_FONT_SIZE);
	pauseTxt = "PAUSE";
	controls.load("../../resources/phantomstorm.ttf", CONTROLS_FONT_SIZE);
	controlsTxt = "Controls:\n";
	controlsTxt += " + P1:\n   Use the arrows to move\n   Use L to shoot\n";
	controlsTxt += " + P2:\n   Use WASD to move\n   Use V to shootr\n";
	controlsTxt += " + Press P to continue or pause";
}

void PauseState::render() {
	ofSetColor(255, 255, 255);
	pause.drawString(pauseTxt,
		ofGetWidth() / 2 - pause.stringWidth(pauseTxt) / 2,
		ofGetHeight() / 4 + PAUSE_FONT_SIZE / 2);
	ofSetColor(179, 179, 179);
	controls.drawString(controlsTxt,
		ofGetWidth() / 2 - controls.stringWidth(controlsTxt) / 2,
		ofGetHeight() / 2 + CONTROLS_FONT_SIZE / 2);
}

void PauseState::keyPressed(int key) {
	if (key == 'p' || key == 'P')  app->getGameStateMachine()->popState();
}