#pragma once
#include "../ecs/Component.h"

class PickupComponent : public Component {
private:
	int playerPick;
	ofxBox2dRect* body;

public:
	// Id del componente
	static constexpr cmpId_type id = _BLOCK;

	inline PickupComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h, int p) :
		Component(), playerPick(p) {
		body = new ofxBox2dRect();
		body->setPhysics(1, 0, 0);
		body->setup(b2dworld->getWorld(), pos.x, pos.y, w, h);
		body->enableGravity(false);
		body->setFixedRotation(true);
	}

	inline ~PickupComponent() {
		body->destroy();
	}

	inline virtual void initComponent() {
		body->setData(myObj);
	}

	inline virtual void render() {
		body->update();
		if (playerPick == 1) ofSetColor(255, 0, 0);
		else ofSetColor(0, 0, 255);
		body->draw();
	}

	inline int getPlayerPick() { return playerPick; }
};