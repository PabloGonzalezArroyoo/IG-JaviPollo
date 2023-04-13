#pragma once

#include "ofMain.h"
#include "game/GameStateMachine.h"

class GameStateMachine;
class ofApp : public ofBaseApp {
private:
	GameStateMachine* gsm;
	vector<ofSoundPlayer> sounds;

	public:
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

		GameStateMachine* getGameStateMachine() { return gsm; }
		void playSound(int s);
};
