#include "ofApp.h"
#include "MenuState.h"

//--------------------------------------------------------------
void ofApp::setup(){
    game = new Game();
    game->getGameStateMachine()->pushState(new MenuState(game));
    ofSetFrameRate(60);
}

ofApp::~ofApp(){
    delete game;
}

//--------------------------------------------------------------
void ofApp::update(){
    game->getGameStateMachine()->currentState()->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    game->getGameStateMachine()->currentState()->draw();
}


void ofApp::keyPressed(int key){    
    game->getGameStateMachine()->currentState()->keyPressed(key);
}


void ofApp::keyReleased(int key){
    game->getGameStateMachine()->currentState()->keyReleased(key);
}
