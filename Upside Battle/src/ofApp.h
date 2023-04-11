#pragma once

#include "ofMain.h"
#include "ecs/Manager.h"
#include "ecs/Entity.h"
#include "components/InputComponent.h"
#include "components/Transform.h"
#include "components/BlockComponent.h"
#include "components/UIComponent.h"
#include "components/HealthComponent.h"
#include "components/WeaponComponent.h"
#include "ecs/CollisionListener.h"

class ofApp : public ofBaseApp {

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

		void onRoundOver();

		// Manager
		Manager* mngr;

		// Mundo (the box2d world)
		ofxBox2d box2d;

		// Jugador 1
		Entity* playerOne;
		InputComponent* inputOne;
		Entity* UIplayerOne;
		Entity* weaponPlayerOne;
		HealthComponent* healthPlayerOne;

		// Jugador 2
		Entity* playerTwo;
		InputComponent* inputTwo;
		Entity* UIplayerTwo;
		Entity* weaponPlayerTwo;
		HealthComponent* healthPlayerTwo;

		// Arma
		Entity* weapon;
};
