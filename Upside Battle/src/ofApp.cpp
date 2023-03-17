#include "ofApp.h"
#include "ofxBox2d.h"
#include "components/Transform.h"
#include "components/BlockComponent.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// Inicializar las físicas y el mapa
	bounds.init();
	bounds.setGravity(0, 10);
	bounds.createBounds();
	bounds.setFPS(60.0);
	bounds.registerGrabbing();

	mngr = new Manager();
	player = mngr->addEntity();
	player->addComponent<Transform>(ofVec2f(200, 200), 20, 20, ofVec2f(0, 1));
	player->addComponent<BlockComponent>(&bounds);
	plOneInput = player->addComponent<InputComponent>();
}

//--------------------------------------------------------------
void ofApp::update(){
	bounds.update();
	mngr->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mngr->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	plOneInput->handleInput(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
