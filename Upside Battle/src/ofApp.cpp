#include "ofApp.h"
#include "components/Transform.h"
#include "components/BlockComponent.h"
#include "components/UIComponent.h"
#include "components/HealthComponent.h"
#include "components/ColliderComponent.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Añadir el manager
	mngr = new Manager();

	// JUGADOR 1
	// Entidad jugador
	playerOne = mngr->addEntity(_grp_BLOCK1);
	playerOne->addComponent<Transform>(ofVec2f(200, 200), 40, 40, ofVec2f(0, 0));
	playerOne->addComponent<BlockComponent>();
	inputOne = playerOne->addComponent<InputComponent>(OF_KEY_LEFT, OF_KEY_RIGHT, OF_KEY_UP, OF_KEY_DOWN);
	playerOne->addComponent<HealthComponent>(3);
	auto cols1 = playerOne->addComponent<ColliderComponent>();
	cols1->addCollisionGroup(_grp_BLOCK2);

	// Interfaz
	playerOneUI = mngr->addEntity(_grp_UI);
	playerOneUI->addComponent<Transform>(ofVec2f(0, 0), ofGetWidth() / 2, ofGetHeight() / 7, ofVec2f(0, 0));
	playerOneUI->addComponent<UIComponent>(1);

	// JUGADOR 2
	// Entidad jugador
	playerTwo = mngr->addEntity(_grp_BLOCK2);
	playerTwo->addComponent<Transform>(ofVec2f(200, 400), 40, 40, ofVec2f(0, 0));
	playerTwo->addComponent<BlockComponent>();
	inputTwo = playerTwo->addComponent<InputComponent>('a', 'd', 'w', 's');
	playerTwo->addComponent<HealthComponent>(3);
	auto cols2 = playerTwo->addComponent<ColliderComponent>();
	cols2->addCollisionGroup(_grp_BLOCK1);
	// Interfaz
	playerTwoUI = mngr->addEntity(_grp_UI);
	playerTwoUI->addComponent<Transform>(ofVec2f(ofGetWidth() / 2, 0), ofGetWidth() / 2, ofGetHeight() / 7, ofVec2f(0, 0));
	playerTwoUI->addComponent<UIComponent>(2);

	cols1->addFunction([&](Entity* pl) {
		if (pl->hasComponent<BlockComponent>()) {
			auto tr = pl->getComponent<Transform>();
			tr->setVelocity(ofVec2f(0, 0));
			auto tr2 = playerOne->getComponent<Transform>();
			
			// Derecha
			if (tr->getPosition().x + tr->getWidth() > tr2->getPosition().x + tr2->getWidth()) {
				cout << "derecha" << endl;
				tr->setPosition(ofVec2f(tr2->getPosition().x + tr2->getWidth() + 1, tr->getPosition().y));
			}
			// Izquierda
			else if (tr->getPosition().x + tr->getWidth() < tr2->getPosition().x + tr2->getWidth()) {
				cout << "izquierda" << endl;
				tr->setPosition(ofVec2f(tr2->getPosition().x - tr2->getWidth() - 1, tr->getPosition().y));
			}
		}
		});
	cols2->addFunction([&](Entity* pl) {
		auto tr = pl->getComponent<Transform>();
		tr->setVelocity(ofVec2f(0, 0));
		auto tr2 = playerTwo->getComponent<Transform>();

		// Arriba
		if (tr->getPosition().y + tr->getHeight() < tr2->getPosition().y + tr2->getHeight())
			tr->setPosition(ofVec2f(tr->getPosition().x, tr2->getPosition().y + tr2->getHeight()));
		// Abajo
		if (tr->getPosition().y + tr->getHeight() > tr2->getPosition().y + tr2->getHeight())
			tr->setPosition(ofVec2f(tr->getPosition().x, tr2->getPosition().y - tr2->getHeight() - 1));
		});
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
