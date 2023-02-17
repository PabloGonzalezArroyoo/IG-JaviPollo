#include "ofApp.h"

int red1 = 0, blue1 = 0;
int red2 = 0, blue2 = 0;
bool change1 = false, change2 = true;
bool control = false, win = false;
int counter = 0;
int secs = 1350;
int p1 = 0, p2 = 0;
ofTrueTypeFont puntuacion;
string winTxt = "";

//--------------------------------------------------------------
void ofApp::setup(){
	puntuacion.load("dimitri.ttf", 32);
}

void randomizer() {
	// Color
	int random1 = ofRandom(2);
	int random2 = ofRandom(2);

	switch (random1) {
		case 0: red1 = 255; blue1 = 0; break;
		default: red1 = 0; blue1 = 255; break;
	}

	switch (random2) {
		case 0: red2 = 255; blue2 = 0; break;
		default: red2 = 0; blue2 = 255; break;
	}

	// Figura
	random1 = ofRandom(2);
	random2 = ofRandom(2);

	switch (random1) {
		case 0: change1 = true; break;
		default: change1 = false; break;
	}

	switch (random2) {
		case 0: change2 = true; break;
		default: change2 = false; break;
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!win) {
		counter++;
		if (counter >= secs) {
			secs = ofRandom(700, 2001);
			counter = 0;
			randomizer();
			control = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!win) {
		ofSetColor(red1, 0, blue1);
		if (change1) ofDrawCircle(ofGetWidth() / 4, ofGetHeight() / 2, 100);
		else ofDrawRectangle(ofGetWidth() / 4, ofGetHeight() / 2 - 100, 200, 200);
	
		ofSetColor(red2, 0, blue2);
		if (change2) ofDrawCircle(3 * ofGetWidth() / 4, ofGetHeight() / 2, 100);
		else ofDrawRectangle(3 * ofGetWidth() / 4, ofGetHeight() / 2 - 100, 200, 200);

		ofSetColor(0, 255, 0);
		puntuacion.drawString("PUNTUACION:\n  P1 - " + to_string(p1) + "\n  P2 - " + to_string(p2), 350, 600);
	}
	else {
		ofSetColor(255, 255, 0);
		puntuacion.drawString(winTxt, 350, 400);
	}
}

bool isValid() {
	return (red1 == red2 || blue1 == blue2) || (change1 && change2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (control) {
		if (key == 'q' && isValid()) { p1++; control = false; }
		else if (key == 'q' && !isValid()) p1--;
		else if (key == 'w' && !isValid()) { p1++; control = false; }
		else if (key == 'w' && isValid()) p1--;

		if (key == 'p' && isValid()) { p2++; control = false; }
		else if (key == 'p' && !isValid()) p2--;
		else if (key == 'o' && !isValid()) { p2++; control = false; }
		else if (key == 'o' && isValid()) p2--;	

		if (p1 >= 10) { win = true; winTxt = "PLAYER 1 WINS!"; }
		else if (p2 >= 10) { win = true; winTxt = "PLAYER 2 WINS!"; }
	}
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