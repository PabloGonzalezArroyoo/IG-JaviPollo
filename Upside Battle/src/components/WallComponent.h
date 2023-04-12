#pragma once
#include "../ecs/Component.h"

class WallComponent : public Component {
private:
	ofxBox2dRect* body;

public:
	// Id del componente
	static constexpr cmpId_type id = _BLOCK;

	// Constructora y destructora
	WallComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h) {
		body = new ofxBox2dRect();
		body->setPhysics(0, 0, 0);
		body->setup(b2dworld->getWorld(), pos.x, pos.y, w, h);
		body->enableGravity(false);
		body->setFixedRotation(true);
	}
	~WallComponent() {
		delete body;
	}

	// Métodos virtuales
	virtual void render() {
		body->update();
		ofSetColor(162, 32, 147);
		body->draw();
	}
};