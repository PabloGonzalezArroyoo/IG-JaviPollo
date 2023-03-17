#pragma once
#include "../ecs/Component.h"
#include "../ecs/Entity.h"
#include "Transform.h"

class BlockComponent : public Component {
private:
	ofxBox2dRect body;
	ofxBox2d* world;
	Transform* tr;

public:
	static constexpr cmpId_type id = _BLOCK;

	BlockComponent(ofxBox2d* w) : Component(), world(w) {}

	inline virtual void initComponent() {
		tr = myObj->getComponent<Transform>();

		body.setPhysics(1, 0, 0);
		body.setup(world->getWorld(), tr->getPosition().x, tr->getPosition().y, tr->getWidth(), tr->getHeight());
		body.enableGravity(true);
	}

	inline virtual void render() {
		body.draw();
	}

	inline void advance(ofVec2f vel) {
		body.setPosition(body.getPosition() + vel);
	}
};