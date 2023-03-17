#include "InputComponent.h"

void InputComponent::initComponent() {
	tr = myObj->getComponent<Transform>();
	rect = myObj->getComponent<BlockComponent>();
}

void InputComponent::handleInput(int key) {
	if (key == OF_KEY_LEFT) {
		rect->advance(tr->getVelocity() * ofVec2f(-1, 1));
	}
}