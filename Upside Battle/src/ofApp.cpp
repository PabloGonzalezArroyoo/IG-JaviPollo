#include "ofApp.h"
#include "components/Transform.h"
#include "components/BlockComponent.h"
#include "components/UIComponent.h"
#include "components/HealthComponent.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Añadir el manager
	mngr = new Manager();

	// JUGADOR 1
	// Entidad jugador
	playerOne = mngr->addEntity();
	playerOne->addComponent<Transform>(ofVec2f(200, 200), 40, 40, ofVec2f(0, 0));
	playerOne->addComponent<BlockComponent>();
	inputOne = playerOne->addComponent<InputComponent>(OF_KEY_LEFT, OF_KEY_RIGHT, OF_KEY_UP, OF_KEY_DOWN);
	playerOne->addComponent<HealthComponent>(3);
	// Interfaz
	playerOneUI = mngr->addEntity(_grp_UI);
	playerOneUI->addComponent<Transform>(ofVec2f(0, 0), ofGetWidth() / 2, ofGetHeight() / 7, ofVec2f(0, 0));
	playerOneUI->addComponent<UIComponent>(1);

	// JUGADOR 2
	// Entidad jugador
	playerTwo = mngr->addEntity();
	playerTwo->addComponent<Transform>(ofVec2f(200, 400), 40, 40, ofVec2f(0, 0));
	playerTwo->addComponent<BlockComponent>();
	inputTwo = playerTwo->addComponent<InputComponent>('a', 'd', 'w', 's');
	playerTwo->addComponent<HealthComponent>(3);
	// Interfaz
	playerTwoUI = mngr->addEntity(_grp_UI);
	playerTwoUI->addComponent<Transform>(ofVec2f(ofGetWidth() / 2, 0), ofGetWidth() / 2, ofGetHeight() / 7, ofVec2f(0, 0));
	playerTwoUI->addComponent<UIComponent>(2);
}

//--------------------------------------------------------------
void ofApp::update(){
	mngr->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mngr->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	inputOne->keyPressed(key);
	inputTwo->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	inputOne->keyReleased(key);
	inputTwo->keyReleased(key);
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
