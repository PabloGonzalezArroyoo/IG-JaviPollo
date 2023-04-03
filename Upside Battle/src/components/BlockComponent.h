#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class BlockComponent : public Component {
private:
	ofRectangle body;
	Transform* tr;

public:
	static constexpr cmpId_type id = _BLOCK;

	BlockComponent() : Component() {}

	inline virtual void initComponent() {
		tr = myObj->getComponent<Transform>();
	}

	inline virtual void render() {
		ofDrawRectangle(tr->getPosition(), tr->getWidth(), tr->getHeight());
	}

	inline virtual void update() {
		tr->setVelocity(tr->getVelocity() * 0.99);
		if (tr->velocityMagnitude(tr->getVelocity()) <= 0.002) tr->setVelocity(ofVec2f());
	}

	inline void move(ofVec2f vel) {
		tr->setVelocity(vel);
	}
};