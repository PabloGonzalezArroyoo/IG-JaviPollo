#pragma once
#include "../ecs/Component.h"

class BlockComponent : public Component {
private:
	ofxBox2dRect* body;
	ofxBox2d* world;
	int player;

public:
	static constexpr cmpId_type id = _BLOCK;

	inline BlockComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h, int p) :
		Component(), world(b2dworld), player(p) {
		body = new ofxBox2dRect();
		body->setPhysics(1, 0, 0);
		body->setup(world->getWorld(), pos.x, pos.y, w, h);
		body->enableGravity(false);
		body->setFixedRotation(true);
	}

	inline virtual void render() {
		body->update();
		if (player == 1) ofSetColor(255, 0, 0);
		else ofSetColor(0, 0, 255);
		body->draw();
	}

	inline virtual void update() {
		body->setVelocity(body->getVelocity() * 0.99);
		if (getMagnitudedVelocity() <= 0.002) body->setVelocity(ofVec2f());
	}

	inline float getMagnitudedVelocity() {
		return sqrtf(powf(body->getVelocity().x, 2) + powf(body->getVelocity().y, 2));
	}

	inline void move(ofVec2f vel) {
		body->setVelocity(vel);
	}

	inline ofxBox2dRect* getBody() { return body; }
};