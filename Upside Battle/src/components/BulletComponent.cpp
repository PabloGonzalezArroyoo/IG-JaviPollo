#include "BulletComponent.h"
#include "../ecs/Entity.h"

BulletComponent::BulletComponent(ofxBox2d* b2dworld, ofVec2f pos, ofVec2f vel, int p) :
	Component(), playerBullet(p), time(0) {
	body = new ofxBox2dCircle();
	body->setPhysics(1, 0, 0);
	body->setup(b2dworld->getWorld(), pos.x, pos.y, 10);
	body->enableGravity(false);
	body->setFixedRotation(true);
	body->setVelocity(vel);
}

BulletComponent::~BulletComponent() {
	body->destroy();
}

void BulletComponent::initComponent() {
	body->setData(myObj);
}

void BulletComponent::update() {
	body->update();
	time += ofGetLastFrameTime();
	if (time >= LIFETIME) {
		myObj->setAlive(false);
		time = 0;
	}
}

void BulletComponent::render() {
	if (playerBullet == 1) ofSetColor(219, 131, 33);
	else ofSetColor(135, 168, 14);
	body->draw();
}