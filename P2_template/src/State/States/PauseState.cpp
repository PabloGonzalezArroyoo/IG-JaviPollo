#include "PauseState.h"
#include "PlayState.h"
#include "Player.h"

PauseState::PauseState(Game* game) : State(game, "Pause State") {
    pauseTxt = "PAUSE";
    pressTxt = "Press P to continue";
    controlsTxt = "Controls:\n";
    controlsTxt += " + Press UP ARROW to accelerate\n";
    controlsTxt += " + Press LEFT or RIGHT ARROW to turn\n";
    controlsTxt += " + Press SPACE to shoot\n";
    controlsTxt += " + Press P to continue or pause\n";

    // Cargar fuente
    pause.load("../../resources/fonts/diesel.ttf", 150);
    controls.load("../../resources/fonts/diesel.ttf", 40);
};

void PauseState::update() {

};

void PauseState::draw() {
    ofBackground(0);

    ofEnableLighting();
    ofEnableDepthTest();

    pause.drawString(pauseTxt, ofGetWidth() / 2 - pause.stringWidth(pauseTxt) / 2,
        ofGetHeight() / 2 - pause.stringHeight(pauseTxt) * 1.5);
    ofSetColor(179);
    controls.drawString(controlsTxt, ofGetWidth() / 2 - controls.stringWidth(controlsTxt) / 2,
        ofGetHeight() - controls.stringHeight(controlsTxt) * 1.5);
    ofSetColor(255);

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
