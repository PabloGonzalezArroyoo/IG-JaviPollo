#include "WinState.h"
#include "PlayState.h"

// Constructora
WinState::WinState(ofApp* a, int w) : GameState(a), alpha(255), changeFactor(-1), winner(w) {
	// Añadir el manager
	mng = new Manager();

	ofSetBackgroundColor(43, 29, 92);

	// Cargar fuentes
	win.load("../../resources/daydream.ttf", PAUSE_FONT_SIZE);
	pressStart.load("../../resources/phantomstorm.ttf", START_FONT_SIZE);

	winTxt = "P" + to_string(winner) + "  WINS!";
	startTxt = "Press SPACE to play again";

	app->playSound(WIN);

	createWinnerDisplay();
}

void WinState::render() {
	ofSetColor(255, 255, 255);
	win.drawString(winTxt, ofGetWidth() / 2 - win.stringWidth(winTxt) / 2, ofGetHeight() / 4 + PAUSE_FONT_SIZE / 2);

	ofSetColor(219, 131, 33); 
	ofDrawRectangle(rectP1);
	ofSetColor(135, 168, 14);
	ofDrawRectangle(rectP2);

	if (winner == 1) drawCrown(rectP1.x, rectP1.y, rectP1.width);
	else drawCrown(rectP2.x, rectP2.y, rectP2.width);

	ofSetColor(179, 179, 179, alpha);
	pressStart.drawString(startTxt, ofGetWidth() / 2 - pressStart.stringWidth(startTxt) / 2,
		ofGetHeight() - pressStart.stringHeight(startTxt));
}

void WinState::update() {
	alpha += changeFactor;
	if (alpha <= 0 || alpha >= 255) changeFactor *= -1;
}

void WinState::keyPressed(int key) {
	if (key == ' ') app->getGameStateMachine()->changeState(new PlayState(app));
}

void WinState::createWinnerDisplay() {
	rectP1.x = ofGetWidth() / 4;
	
	if (winner == 1) {
		rectP2.x = ofGetWidth() / 4 + 200 * 2;
		rectP1.width = 200;
		rectP1.height = 200;
		rectP2.width = 100;
		rectP2.height = 100;
		rectP1.y = ofGetHeight() / 2 + 50;
		rectP2.y = ofGetHeight() / 2 + 150;
	}
	else {
		rectP2.x = ofGetWidth() / 4 + 300;
		rectP2.width = 200;
		rectP2.height = 200;
		rectP1.width = 100;
		rectP1.height = 100;
		rectP2.y = ofGetHeight() / 2 + 50;
		rectP1.y = ofGetHeight() / 2 + 150;
	}
}

void WinState::drawCrown(int x, int y, int w) {
	if (winner == 1) ofSetColor(219, 131, 33);
	else ofSetColor(135, 168, 14);

	ofBeginShape();
	ofVertex(x + w / 2 - 40, y + w - 220);
	ofVertex(x + w / 2 - 40, y + w - 280);
	ofVertex(x + w / 2 - 20, y + w - 260);
	ofVertex(x + w / 2, y + w - 280);
	ofVertex(x + w / 2 + 20, y + w - 260);
	ofVertex(x + w / 2 + 40, y + w - 280);
	ofVertex(x + w / 2 + 40, y + w - 220);
	ofEndShape();
}