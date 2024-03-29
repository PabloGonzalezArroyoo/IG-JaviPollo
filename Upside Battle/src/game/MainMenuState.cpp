#include "MainMenuState.h"
#include "PlayState.h"

// Constructora
MainMenuState::MainMenuState(ofApp* a) : GameState(a), alpha(255), changeFactor(-1) {
	// Creamos el manager del estado
	mng = new Manager();

	// Texto de t�tulo
	titleTxt = " UPSIDE\nBATTLE!";
	startTxt = "Press SPACE to start";

	// Cargar fuente
	title.load("../../resources/daydream.ttf", TITLE_FONT_SIZE);
	titleShadow.load("../../resources/daydream.ttf", TITLE_FONT_SIZE);
	pressStart.load("../../resources/phantomstorm.ttf", START_FONT_SIZE);
}

void MainMenuState::update() {
	// Parpadeo del texto de inicio
	alpha += changeFactor;
	if (alpha <= 0 || alpha >= 255) changeFactor *= -1;
}

void MainMenuState::render() {
	// Fondo HUE
	float width = ofGetWidth() / 255.0;
	int brillo = 68;
	int saturation = 4;
	for (int i = 0; i < 255; i++) {
		ofColor c = ofColor(i, saturation, brillo);
		ofSetColor(c);
		ofDrawRectangle(i * width, 0, width, ofGetHeight());
	}

	// T�tulo
	ofSetColor(64, 64, 64);
	titleShadow.drawString(titleTxt, ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2 + 20,
		ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2 - 20);
	ofSetColor(255, 255, 255);
	title.drawString(titleTxt, ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2,
		ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2);

	// Texto de inicio
	ofSetColor(179, 179, 179, alpha);
	pressStart.drawString(startTxt, ofGetWidth() / 2 - pressStart.stringWidth(startTxt) / 2,
		ofGetHeight() - pressStart.stringHeight(startTxt) / 2 * 8);
}

void MainMenuState::keyReleased(int key) {
	// Lanzar estado de juego
	if (key == ' ') {
		app->playSound(SELECT);
		app->getGameStateMachine()->changeState(new PlayState(app));
	}
}