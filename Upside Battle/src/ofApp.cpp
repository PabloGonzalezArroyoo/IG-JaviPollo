#include "ofApp.h"
#include "game/MainMenuState.h"


//--------------------------------------------------------------
void ofApp::setup(){
	// Máquina de estados
	gsm = new GameStateMachine();

	gsm->pushState(new MainMenuState(this));
	
	ofSoundPlayer s1;
	s1.load("../../resources/select.wav");
	sounds.push_back(s1); 
	ofSoundPlayer s2;
	s2.load("../../resources/win.wav");
	sounds.push_back(s2);
}

//--------------------------------------------------------------
void ofApp::update(){
	gsm->currentState()->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	gsm->currentState()->render();
	gsm->currentState()->refresh();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	gsm->currentState()->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	gsm->currentState()->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::playSound(int s) {
	sounds[s].play();
}