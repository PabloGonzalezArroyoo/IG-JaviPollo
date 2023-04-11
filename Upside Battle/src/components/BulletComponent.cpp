#include "BulletComponent.h"
#include "../ecs/Entity.h"

BulletComponent::BulletComponent(ofxBox2d* b2dworld, ofVec2f pos, ofVec2f vel, int p) :
	Component(), playerBullet(p), time(0) {
	body = new ofxBox2dRect();
	body->setPhysics(1, 0, 0);
	body->setup(b2dworld->getWorld(), pos.x, pos.y, 15, 15);
	body->enableGravity(false);
	body->setFixedRotation(true);
	body->setVelocity(vel);
}

void BulletComponent::initComponent() {
	body->setData(myObj);
}

void BulletComponent::update() {
	time += ofGetLastFrameTime();
	if (time >= LIFETIME) {
		myObj->setAlive(false);
		time = 0;
	}
}

void BulletComponent::render() {
	body->update();
	if (playerBullet == 1) ofSetColor(255, 0, 0);
	else ofSetColor(0, 0, 255);
	body->draw();
}