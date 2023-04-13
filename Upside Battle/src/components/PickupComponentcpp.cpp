#include "PickupComponent.h"

PickupComponent::PickupComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h, int p) :
	Component(), playerPick(p) {
	body = new ofxBox2dRect();
	body->setPhysics(1, 0, 0);
	body->setup(b2dworld->getWorld(), pos.x, pos.y, w, h);
	body->enableGravity(false);
	body->setFixedRotation(true);
}

PickupComponent::~PickupComponent() {
	body->destroy();
}

void PickupComponent::initComponent() {
	body->setData(myObj);
}

void PickupComponent::update() {
	body->update();
}

void PickupComponent::render() {
	if (playerPick == 1) ofSetColor(219, 131, 33);
	else ofSetColor(135, 168, 14);
	body->draw();

	ofNoFill();
	ofDrawCircle(body->getPosition(), 20);
	ofFill();
}