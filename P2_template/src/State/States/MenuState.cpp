#include "PlayState.h"
#include "MenuState.h"

MenuState::MenuState(Game* game) : State(game, "Menu State"), alpha(255), changeFactor(-1) {
    // Texto de título
    titleTxt = "CORRE CORRE";
    startTxt = "Press SPACE to start";

    // Cargar fuente
    title.load("diesel.ttf", 150);
    titleShadow.load("diesel.ttf", 150);
    pressStart.load("diesel.ttf", 80);
};

void MenuState::update(){
    // Parpadeo del texto de inicio
    alpha += changeFactor;
    if (alpha <= 0 || alpha >= 255) changeFactor *= -1;
};
    
void MenuState::draw(){
    // Fondo HUE
    float width = ofGetWidth() / 255.0;
    int brillo = 10;
    int saturation = 4;
    for (int i = 0; i < 255; i++) {
        ofColor c = ofColor(i, saturation, brillo);
        ofSetColor(c);
        ofDrawRectangle(i * width, 0, width, ofGetHeight());
    }

    // Nombre del estado
    ofDrawBitmapString(name, 10, 20);

    // Título
    ofSetColor(64, 64, 64);
    titleShadow.drawString(titleTxt, ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2 + 20,
        ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2 - 20);
    ofSetColor(255, 255, 255);
    title.drawString(titleTxt, ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2,
        ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2);

    // Texto de inicio
    ofSetColor(179, 179, 179, alpha);
    pressStart.drawString(startTxt, ofGetWidth() / 2 - pressStart.stringWidth(startTxt) / 2,
        ofGetHeight() - pressStart.stringHeight(startTxt) / 3 * 8);
    ofSetColor(255, 255, 255);
};

void MenuState::keyPressed(int key) {
    if (key == ' ')
        game->getGameStateMachine()->pushState(new PlayState(game));
}