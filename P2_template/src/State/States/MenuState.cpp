#include "PlayState.h"
#include "MenuState.h"

void MenuState::update(){
    text.load("diesel.ttf", 120);
};
    
void MenuState::draw(){
    ofBackground(0);
    ofDrawBitmapString(name, 10, 20);
    string titleText = "CORRE CORRE";
    text.drawString(titleText, ofGetWidth() / 2 - text.stringWidth(titleText) / 2,
        ofGetHeight() / 2 - text.stringHeight(titleText) / 2 - 20);
};

void MenuState::keyPressed(int key) {
    if (key == ' ')
        game->getGameStateMachine()->pushState(new PlayState(game));
}