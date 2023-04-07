#include "BlockComponent.h"

BlockComponent::BlockComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h, int p) :
	Component(), world(b2dworld), player(p) {
	body = new ofxBox2dRect();
	body->setPhysics(1, 0, 0);
	body->setup(world->getWorld(), pos.x, pos.y, w, h);
	body->enableGravity(false);
	body->setFixedRotation(true);
}

BlockComponent::~BlockComponent() {
	delete body;
}

void BlockComponent::initComponent() {
	body->setData(myObj);
}

void BlockComponent::render() {
	body->update();
	if (player == 1) ofSetColor(255, 0, 0);
	else ofSetColor(0, 0, 255);
	body->draw();
}

void BlockComponent::update() {
	body->setVelocity(body->getVelocity() * 0.99);
	if (getMagnitudedVelocity() <= 0.002) body->setVelocity(ofVec2f());
}

void BlockComponent::move(ofVec2f vel) {
	body->setVelocity(vel);
}