#include "MainMenuState.h"
#include "PlayState.h"

// Constructora
MainMenuState::MainMenuState(ofApp* a) : GameState(a), alpha(255), changeFactor(-1) {
	// Creamos el manager del estado
	mng = new Manager();

	// Texto de título
	titleTxt = " UPSIDE\nBATTLE!";
	startTxt = "Press SPACE to start";

	// Cargar fuente
	title.load("../../resources/daydream.ttf", TITLE_FONT_SIZE);
	titleShadow.load("../../resources/daydream.ttf", TITLE_FONT_SIZE);
	pressStart.load("../../resources/phantomstorm.ttf", START_FONT_SIZE);

	ofSetBackgroundColor(0, 0, 0);
}

void MainMenuState::update() {
	alpha += changeFactor;
	if (alpha <= 0 || alpha >= 255) changeFactor *= -1;
}

void MainMenuState::render() {
	ofSetColor(64, 64, 64);
	titleShadow.drawString(titleTxt,
		ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2 + 20, ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2 - 20);
	ofSetColor(255, 255, 255);
	title.drawString(titleTxt,
		ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2, ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2);
	ofSetColor(179, 179, 179, alpha);
	pressStart.drawString(startTxt,
		ofGetWidth() / 2 - pressStart.stringWidth(startTxt) / 2, ofGetHeight() - pressStart.stringHeight(startTxt) / 2 * 8);
}

void MainMenuState::keyReleased(int key) {
	if (key == ' ') app->getGameStateMachine()->changeState(new PlayState(app));
}