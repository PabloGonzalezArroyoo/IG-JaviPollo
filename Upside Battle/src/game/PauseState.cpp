#include "PauseState.h"

// Constructora
PauseState::PauseState(ofApp* a) : GameState(a) {
	// Añadir el manager
	mng = new Manager();

	pause.load("../../resources/phantomstorm.ttf", HUD_FONT_SIZE * 3);
	pauseTxt = "PAUSA";
}

// Manejo del input en el pasueState
void PauseState::render() {
	ofSetColor(179, 179, 179);
	pause.drawString(pauseTxt,
		ofGetWidth() / 2 - pause.stringWidth(pauseTxt) / 2,
		ofGetHeight() / 4 + HUD_FONT_SIZE / 2);
}

void PauseState::keyPressed(int key) {
	if (key == 'p' || key == 'P')  app->getGameStateMachine()->popState();
}