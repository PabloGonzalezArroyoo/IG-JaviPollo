#include "HealthComponent.h"

HealthComponent::HealthComponent(int life, bool inv) : Component(), maxLife(life), invincibility(inv), lifePoints(life) { }

void HealthComponent::initComponent() {
	tr = myObj->getComponent<Transform>();

	for (int i = 0; i < maxLife; i++) {
		ofRectangle rect;
		rect.width = (tr->getWidth() + 20) / maxLife;
		rect.height = 10;
		lifesHUD.push_back(rect);
	}
}

void HealthComponent::receiveDamage(int damage) {
	maxLife -= damage;
}

void HealthComponent::update() {
	for (int i = 0; i < lifePoints; i++) {
		ofRectangle rect = lifesHUD[i];
		lifesHUD[i].x = (tr->getPosition().x - (20 + (5 * (maxLife - 1))) / 2) + ((lifesHUD[i].width + 5) * i);
		lifesHUD[i].y = tr->getPosition().y - 20;
	}
}

void HealthComponent::render() {
	ofSetColor(255, 0, 0);
	for (int i = 0; i < lifePoints; i++) {
		ofRectangle rect = lifesHUD[i];
		ofDrawRectangle(rect.position, rect.width, rect.height);
	}
	ofSetColor(255, 255, 255);
}

void HealthComponent::die() {

}