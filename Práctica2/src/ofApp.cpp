#include "ofApp.h"

string quasso = "QUASSO";

//--------------------------------------------------------------
void ofApp::setup(){
	platform.y = ofGetHeight() - 100;
	platform.width = 200;
	platform.height = 30;
	puntuacion.load("Purple Smile.ttf", 30, true, false);
	itFirstSquare = squares.begin();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!lose) {
		deltaTime = ofGetElapsedTimef() * 10;
		if (squares.size() < 3) {
			if (deltaTime % 20) {
				if (generar) {
					squares.push_back(FallingSquare(ofRandom(ofGetWidth())));
					itFirstSquare = squares.begin();
					generar = false;
				}
			}
			else generar = true;
		}

		for (auto it = squares.begin(); it != squares.end(); it++) {
			// Mover
			it->move();

			// Colisión
			if (it->getSquare().intersects(platform)) {
				switch (it->getColor()) {
				case 0: lose = true; break;
				case 1: points++; break;
				}
				squares.erase(it);
				break;
			}

			// Fin de pantalla
			if (it->getY() > ofGetHeight()) {
				squares.erase(it);
				break;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!lose) {
		// Añadir plataforma
		platform.x = ofGetMouseX() - platform.width / 2;
		ofSetColor(0, 0, 255);
		ofDrawRectangle(platform);

		// Mover rectángulos
		for (int i = 0; i < squares.size(); i++) {
			switch (squares[i].getColor()) {
			case 0: ofSetColor(ofColor::red); break;
			case 1: ofSetColor(ofColor::white); break;
			}
			ofDrawRectangle(squares[i].getSquare());
		}

		ofSetColor(ofColor::yellow);
		puntuacion.drawString(ofToString(points), 50, 50);
	}
	else {
		puntuacion.drawString(quasso + " " + to_string(points), ofGetWidth() / 2 - puntuacion.stringWidth(quasso) / 2, ofGetHeight() / 2);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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