#include "HealthComponent.h"
#include "BlockComponent.h"

HealthComponent::HealthComponent(int life, UIComponent* uc, bool inv) : Component(),
maxLife(life), invincibility(inv), lifePoints(life), ui(uc), alive(true) { }

void HealthComponent::initComponent() {
	tr = myObj->getComponent<BlockComponent>()->getBody();

	for (int i = 0; i < maxLife; i++) {
		ofRectangle rect;
		rect.width = (tr->getWidth() + X_OFFSET) / maxLife;
		rect.height = 10;
		lifesHUD.push_back(rect);
	}
}

void HealthComponent::receiveDamage(int damage) {
	lifePoints -= damage;
	if (lifePoints <= 0) {
		die();
		ui->updatePoints(3);
	}
	else ui->updatePoints(1);
}

void HealthComponent::update() {
	for (int i = 0; i < lifePoints; i++) {
		ofRectangle rect = lifesHUD[i];
		lifesHUD[i].x = (tr->getPosition().x - (X_OFFSET + (INBETWEEN_OFFSET * (maxLife - 1))) / 2 - tr->getWidth() / 2)
			+ ((lifesHUD[i].width + INBETWEEN_OFFSET) * i);
		lifesHUD[i].y = tr->getPosition().y - Y_OFFSET;
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
	lifePoints = maxLife;
	alive = false;
}