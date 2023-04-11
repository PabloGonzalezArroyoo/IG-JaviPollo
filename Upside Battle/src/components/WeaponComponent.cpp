#include "WeaponComponent.h"
#include "BlockComponent.h"
#include "BulletComponent.h"

void WeaponComponent::initComponent() {
	blockBody = myObj->getComponent<BlockComponent>()->getBody();
}

void WeaponComponent::render() {
	ofVec2f vel = blockBody->getVelocity();
	ofVec2f pos = blockBody->getPosition();
	
	if (vel.x != 0 || vel.y != 0) {
		ofBeginShape();
		if (vel.y == 0) {
			if (vel.x < 0) {
				ofVertex(pos.x - 30, pos.y - 10);
				ofVertex(pos.x - 50, pos.y);
				ofVertex(pos.x - 30, pos.y + 10);
			}
			else if (vel.x > 0) {
				ofVertex(pos.x + 30, pos.y - 10);
				ofVertex(pos.x + 50, pos.y);
				ofVertex(pos.x + 30, pos.y + 10);
			}
		}
		if (vel.x == 0) {
			if (vel.y < 0) {
				ofVertex(pos.x - 10, pos.y - 30);
				ofVertex(pos.x, pos.y - 50);
				ofVertex(pos.x + 10, pos.y - 30);
			}
			else if (vel.y > 0) {
				ofVertex(pos.x - 10, pos.y + 30);
				ofVertex(pos.x, pos.y + 50);
				ofVertex(pos.x + 10, pos.y + 30);
			}
		}
		ofEndShape();
	}
}

void WeaponComponent::shoot() {
	Entity* bullet = myMng->addEntity();
	ofVec2f vel = blockBody->getVelocity().normalize();
	if (vel.x != 0 || vel.y != 0) {
		ofVec2f pos = blockBody->getPosition();
		ofVec2f newPos;
		if (vel.y == 0) {
			if (vel.x < 0) newPos = ofVec2f(pos.x - 50, pos.y);
			else if (vel.x > 0) newPos = ofVec2f(pos.x + 50, pos.y);
		}
		if (vel.x == 0) {
			if (vel.y < 0) newPos = ofVec2f(pos.x, pos.y - 50);
			else if (vel.y > 0) newPos = ofVec2f(pos.x, pos.y + 50);
		}
		bullet->addComponent<BulletComponent>(myMng->getWorld(), newPos, vel * BULLET_SPEED,
			myObj->getComponent<BlockComponent>()->getPlayer());
	}
	// bullet->addComponent<DisableOnExit>();
}