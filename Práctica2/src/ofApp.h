#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "C:\Users\pavip\Desktop\Universidad\IG1\Pr�ctica2\FallingSquare.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		ofRectangle platform;
		vector<FallingSquare> squares;
		ofTrueTypeFont puntuacion;
		int points;
		int deltaTime;
		bool generar;


		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
