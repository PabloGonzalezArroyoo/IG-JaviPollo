#include "PauseState.h"
#include "PlayState.h"
#include "Player.h"

PauseState::PauseState(Game* game) : State(game, "Pause State") {

};

void PauseState::update() {
    game->update();
};

void PauseState::draw() {
    ofBackground(0);

    ofEnableLighting();
    ofEnableDepthTest();

    game->drawHUD();

    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Fps: " + ofToString(ofGetFrameRate()), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString(name, 0, 0);
    }
    ofPopMatrix();

    ofDisableLighting();
    ofDisableDepthTest();
};


void PauseState::keyPressed(int key) {
    if (key == 'p') {
        game->getGameStateMachine()->popState();
    }
}
