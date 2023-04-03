#include "InputComponent.h"

InputComponent::InputComponent(int keyLeft, int keyRight, int keyUp, int keyDown) : Component() {
	keyIds[0] = keyLeft;
	keyIds[1] = keyRight;
	keyIds[2] = keyUp;
	keyIds[3] = keyDown;

	for (int i = 0; i < NUMBER_OF_KEYS; i++) keys[i] = false;
}

void InputComponent::initComponent() {
	tr = myObj->getComponent<Transform>();
	rect = myObj->getComponent<BlockComponent>();
}

void InputComponent::update() {
	if (keys[0]) rect->move(ofVec2f(-1, 0) * SPEEDLIMIT);
	else if (keys[1]) rect->move(ofVec2f(1, 0) * SPEEDLIMIT);
	else if (keys[2]) rect->move(ofVec2f(0, -1) * SPEEDLIMIT);
	else if (keys[3]) rect->move(ofVec2f(0, 1) * SPEEDLIMIT);
}

void InputComponent::keyPressed(int key) {
	if (key == keyIds[0]) keys[0] = true;
	if (key == keyIds[1]) keys[1] = true;
	if (key == keyIds[2]) keys[2] = true;
	if (key == keyIds[3]) keys[3] = true;
}

void InputComponent::keyReleased(int key) {
	if (key == keyIds[0]) keys[0] = false;
	if (key == keyIds[1]) keys[1] = false;
	if (key == keyIds[2]) keys[2] = false;
	if (key == keyIds[3]) keys[3] = false;
}