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
	box2d.getWorld()->SetContactListener(new CollisionListener(mngr));

	// Mundo al manager
	mngr->setWorld(&box2d);

	// JUGADOR 1
	// Entidad jugador
	playerOne = mngr->addEntity();
	playerOne->addComponent<BlockComponent>(&box2d, ofVec2f(200, 200), BLOCK_DIMS, BLOCK_DIMS, 1);
	inputOne = playerOne->addComponent<InputComponent>(OF_KEY_LEFT, OF_KEY_RIGHT, OF_KEY_UP, OF_KEY_DOWN);
	// Interfaz
	UIplayerOne = mngr->addEntity(_grp_UI);
	UIplayerOne->addComponent<Transform>(ofVec2f(0, 0), ofGetWidth() / 2, ofGetHeight() / 7);
	UIplayerOne->addComponent<UIComponent>(1);
	// Arma
	weaponPlayerOne = mngr->addEntity();
	weaponPlayerOne->addComponent<PickupComponent>(&box2d, ofVec2f(800, 200), 10, 10, 1);

	// JUGADOR 2
	// Entidad jugador
	playerTwo = mngr->addEntity();
	playerTwo->addComponent<BlockComponent>(&box2d, ofVec2f(200, 400), BLOCK_DIMS, BLOCK_DIMS, 2);
	inputTwo = playerTwo->addComponent<InputComponent>('a', 'd', 'w', 's');
	// Interfaz
	UIplayerTwo = mngr->addEntity(_grp_UI);
	UIplayerTwo->addComponent<Transform>(ofVec2f(ofGetWidth() / 2, 0), ofGetWidth() / 2, ofGetHeight() / 7);
	UIplayerTwo->addComponent<UIComponent>(2);
	// Arma
	weaponPlayerTwo = mngr->addEntity();
	weaponPlayerTwo->addComponent<PickupComponent>(&box2d, ofVec2f(800, 400), 10, 10, 2);

	// Vida
	healthPlayerOne = playerOne->addComponent<HealthComponent>(MAX_LIFE, UIplayerTwo->getComponent<UIComponent>());
	healthPlayerTwo = playerTwo->addComponent<HealthComponent>(MAX_LIFE, UIplayerOne->getComponent<UIComponent>());

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
	mngr->update();

	if (!healthPlayerOne->isAlive() || !healthPlayerTwo->isAlive()) onRoundOver();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mngr->render();
	mngr->refresh();
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

void ofApp::onRoundOver() {
	auto body = playerOne->getComponent<BlockComponent>()->getBody();
	body->setVelocity(ofVec2f(0, 0));
	body->setPosition(ofVec2f(200, 200));

	body = playerTwo->getComponent<BlockComponent>()->getBody();
	body->setVelocity(ofVec2f(0, 0));
	body->setPosition(ofVec2f(200, 400));

	playerOne->removeComponent<WeaponComponent>();
	playerTwo->removeComponent<WeaponComponent>();
	inputOne->resetShootKey();
	inputTwo->resetShootKey();

	weaponPlayerTwo = mngr->addEntity();
	weaponPlayerTwo->addComponent<PickupComponent>(&box2d, ofVec2f(800, 400), 10, 10, 2);

	weaponPlayerOne = mngr->addEntity();
	weaponPlayerOne->addComponent<PickupComponent>(&box2d, ofVec2f(800, 200), 10, 10, 1);

	healthPlayerOne->setAlive(true);
	healthPlayerTwo->setAlive(true);
}