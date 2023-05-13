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
    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Fps: " + ofToString(ofGetFrameRate()), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString(name, 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Time: " + ofToString(game->getEllapsedTime(), 2), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Speed: " + ofToString(game->getPlayer()->getSpeed(), 2), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Coins: " + ofToString(game->getPlayer()->getCoins(), 2), 0, 0);

    }
    ofPopMatrix();
    game->draw();
};


void PauseState::keyPressed(int key) {
    if (key == 'p') {
        game->getGameStateMachine()->popState();
    }
}
