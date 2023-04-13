#include "WallComponent.h"

// Constructora
WallComponent::WallComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h) {
	body = new ofxBox2dRect();
	body->setPhysics(0, 0, 0);
	body->setup(b2dworld->getWorld(), pos.x, pos.y, w, h);
	body->enableGravity(false);
	body->setFixedRotation(true);
}

WallComponent::~WallComponent() {
	delete body;
}

void WallComponent::render() {
	body->update();
	ofSetColor(162, 32, 147);
	body->draw();
}