#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Añadir el manager
	mngr = new Manager();

	box2d.init();
	//box2d.setGravity(0, 10);
	box2d.createBounds(0, ofGetHeight() / 7, ofGetWidth(), ofGetHeight() - ofGetHeight() / 7);
	box2d.setFPS(60.0);
	box2d.registerGrabbing();
	box2d.getWorld()->SetContactListener(new CollisionListener);

	// JUGADOR 1
	// Entidad jugador
	playerOne = mngr->addEntity();
	playerOne->addComponent<BlockComponent>(&box2d, ofVec2f(200, 200), BLOCK_DIMS, BLOCK_DIMS, 1);
	inputOne = playerOne->addComponent<InputComponent>(OF_KEY_LEFT, OF_KEY_RIGHT, OF_KEY_UP, OF_KEY_DOWN);
	playerOne->addComponent<HealthComponent>(3);
	playerOne->addComponent<WeaponComponent>();
	// Interfaz
	UIplayerOne = mngr->addEntity(_grp_UI);
	UIplayerOne->addComponent<Transform>(ofVec2f(0, 0), ofGetWidth() / 2, ofGetHeight() / 7);
	UIplayerOne->addComponent<UIComponent>(1);
	// Arma
	weaponPlayerOne = mngr->addEntity();

	// JUGADOR 2
	// Entidad jugador
	playerTwo = mngr->addEntity();
	playerTwo->addComponent<BlockComponent>(&box2d, ofVec2f(200, 400), BLOCK_DIMS, BLOCK_DIMS, 2);
	inputTwo = playerTwo->addComponent<InputComponent>('a', 'd', 'w', 's');
	playerTwo->addComponent<HealthComponent>(3);
	// Interfaz
	UIplayerTwo = mngr->addEntity(_grp_UI);
	UIplayerTwo->addComponent<Transform>(ofVec2f(ofGetWidth() / 2, 0), ofGetWidth() / 2, ofGetHeight() / 7);
	UIplayerTwo->addComponent<UIComponent>(2);
	// Arma
	weaponPlayerTwo = mngr->addEntity();
	playerTwo->addComponent<WeaponComponent>();
}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
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
