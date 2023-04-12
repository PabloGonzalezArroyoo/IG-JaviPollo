#include "UIComponent.h"

UIComponent::UIComponent(int p) : player(p), points(0) { }

void UIComponent::initComponent() {
	tr = myObj->getComponent<Transform>();

	uiBox.x = tr->getPosition().x;
	uiBox.y = tr->getPosition().y;
	uiBox.width = tr->getWidth();
	uiBox.height = tr->getHeight();

	uiPoints.load("../../resources/phantomstorm.ttf", HUD_FONT_SIZE);
}

void UIComponent::render() {
	if (player == 1) ofSetColor(219, 131, 33);
	else ofSetColor(135, 168, 14);
	ofDrawRectangle(uiBox.position, uiBox.width, uiBox.height);

	ofSetColor(0, 0, 0);
	pointsString = "P" + to_string(player) + ": " + to_string(points);
	uiPoints.drawString(pointsString,
		uiBox.x + uiBox.width / 2 - uiPoints.stringWidth(pointsString) / 2, uiBox.y + uiBox.height / 2 + HUD_FONT_SIZE / 2);

	ofSetColor(255, 255, 255);
}

void UIComponent::updatePoints(int pts) {
	points += pts;
}